#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->backupFileList->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->backupFileList->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->taskTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->taskTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->taskTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->cloudFileTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->cloudFileTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->cloudFileTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->pwdLineEdit->setEchoMode(QLineEdit::Password);
    ui->pwdLineEdit_2->setEchoMode(QLineEdit::Password);
    ui->progressBar->setValue(0);
    ui->progressBar_2->setValue(0);
    ui->progressBar->setAlignment(Qt::AlignVCenter);
    ui->progressBar_2->setAlignment(Qt::AlignVCenter);
    this->backupName = nullptr;
    this->backupDirectory = nullptr;
    this->passwordCheckBox = false;
    this->isCloud = false;
    this->password = nullptr;
    this->username = nullptr;
    this->loginPwd = nullptr;
    this->user_id = -1;
    taskManager.init();
    for (const auto& t : taskManager.getTaskList())
    {
        showTasks(t);
    }

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("cloud");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("root");
    if(db.open()){
        qDebug() << "server connect success";
    }else{
        QSqlError err = db.lastError();
        qDebug() << err.text();
    }

    //定时任务
    connect(&timer, &QTimer::timeout, this, &Widget::timeout_SLOT);
    connect(ui->cloudFileTableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(chooseCloudFile_SLOT()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_addFileButton_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(
                            this,
                            "选择文件",
                            "/home",
                            "所有文件 (*.*)");

    int RowCont;
    for(int i = 0; i < files.size(); i++)
    {
        RowCont=ui->backupFileList->rowCount();
        ui->backupFileList->insertRow(RowCont);//增加一行
        QTableWidgetItem* fileNameItem = new QTableWidgetItem;
        QTableWidgetItem* filePathItem = new QTableWidgetItem;
        fileNameItem->setText(QFileInfo(files[i]).fileName());
        filePathItem->setText(files[i]);
//        qDebug() << files[i] <<endl;
//        qDebug() << QFileInfo(files[i]).fileName() <<endl;
        ui->backupFileList->setItem(RowCont,0,fileNameItem);
        ui->backupFileList->setItem(RowCont,1,filePathItem);
    }


}

void Widget::on_addFoldButton_clicked()
{
    QString directory = QFileDialog::getExistingDirectory(
                            this,
                            tr("选择一个文件夹"),
                            "/home",
                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);


    int RowCont;
    if(directory != "")
    {
        RowCont=ui->backupFileList->rowCount();
        ui->backupFileList->insertRow(RowCont);//增加一行
        QTableWidgetItem* directoryNameItem = new QTableWidgetItem;
        QTableWidgetItem* directoryPathItem = new QTableWidgetItem;
        directoryNameItem->setText(QFileInfo(directory).fileName());
        directoryPathItem->setText(directory);
        ui->backupFileList->setItem(RowCont,0,directoryNameItem);
        ui->backupFileList->setItem(RowCont,1,directoryPathItem);
    }
}

void Widget::on_deleteButton_clicked()
{
    int RowIndex = ui->backupFileList->currentRow();
    if (RowIndex != -1)
         ui->backupFileList->removeRow(RowIndex);
}

void Widget::on_clearButton_clicked()
{
    int RowCount = ui->backupFileList->rowCount();
    for(int i = RowCount - 1; i >= 0; i--)
    {
        ui->backupFileList->removeRow(i);
    }
}

void Widget::on_startButton_clicked()
{
    ui->progressBar->setValue(0);

    if(backupName == "")
    {
        QMessageBox::information(this, "提示", "请设置备份信息。", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }

    if (!ui->backupFileList->rowCount()) {
        QMessageBox::information(this, "提示", "请添加需要备份的文件。", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }

    auto rootDirectory = QFileInfo(ui->backupFileList->item(0, 1)->text()).path();
    for (int i = 1; i < ui->backupFileList->rowCount(); i++) {
        if (QFileInfo(ui->backupFileList->item(i, 1)->text()).path() != rootDirectory) {
            QMessageBox::information(this, "提示", "选择的文件或文件夹应位于同一目录下。", QMessageBox::Yes, QMessageBox::Yes);
            return;
        }
    }

    QStringList files;
    for(int i = 0; i < ui->backupFileList->rowCount(); i++)
    {
        files.append(ui->backupFileList->item(i, 1)->text());
    }

    ui->progressBar->setValue(10);

    //打包
    if(!Package::pack(files, backupName + ".tar"))
    {
        qDebug() << "package complete" << endl;
    }

    ui->progressBar->setValue(30);

    //压缩
    Compress compressor;
    if(!compressor.compress(backupName.toStdString() + ".tar",
                        backupDirectory.toStdString() + "/",
                        password.toStdString()))
    {
        qDebug() << "compress complete" << endl;
    }

    ui->progressBar->setValue(60);

    //删除中间文件
    QFile temp(backupName + ".tar");
    temp.remove();

    //云备份
    if(isCloud)
    {
        QDateTime now = QDateTime::currentDateTime();
        QSqlQuery query;
        QString sql = QString("insert into file(backupName, date, user_id) values('%1', '%2', '%3');").arg(backupName + ".bak").arg(now.toString("yyyy-MM-dd hh:mm:ss")).arg(user_id);
        if(!query.exec(sql))
            qDebug()<<query.lastError().text();

        sql = QString("select id from file where user_id = '%1' AND backupName = '%2' AND date = '%3'").arg(user_id).arg(backupName + ".bak").arg(now.toString("yyyy-MM-dd hh:mm:ss"));
        if(!query.exec(sql))
            qDebug()<<query.lastError().text();
        query.next();
        QVariant file_id = query.value(0);
        QByteArray data;
        QFile cloudFile(backupDirectory + "/" + backupName + ".bak");
        if(!cloudFile.open(QFile::ReadOnly))
        {
            qDebug() <<"update file open failed";
        }
        data = cloudFile.readAll();
        cloudFile.close();
        QVariant content(data);
        sql = QString("insert into file_content(content, file_id) values(?, ?);");
        query.prepare(sql);
        query.addBindValue(content);
        query.addBindValue(file_id);
        if(!query.exec())
            qDebug()<<query.lastError().text();
    }

    //添加任务
    if(!once)
    {
        ui->taskTableWidget->insertRow(0);//增加一行
        QTableWidgetItem* bakName = new QTableWidgetItem;
        QTableWidgetItem* freq = new QTableWidgetItem;
        QTableWidgetItem* isCode = new QTableWidgetItem;
        QTableWidgetItem* localPath = new QTableWidgetItem;
        QTableWidgetItem* isCloud = new QTableWidgetItem;

        bakName->setText(backupName + ".bak");
        freq->setText(day ? "每天" : "每周");
        isCode->setText(passwordCheckBox ? "是" : "否");
        localPath->setText(backupDirectory + "/" + backupName + ".bak");
        isCloud->setText(this->isCloud ? "是" : "否");

        ui->taskTableWidget->setItem(0, 0, bakName);
        ui->taskTableWidget->setItem(0, 1, freq);
        ui->taskTableWidget->setItem(0, 2, isCode);
        ui->taskTableWidget->setItem(0, 3, localPath);
        ui->taskTableWidget->setItem(0, 4, isCloud);

        QList<QString> files;
        for (int i = 0; i < ui->backupFileList->rowCount(); i++) {
            files.append(ui->backupFileList->item(i, 0)->text());
        }

        QDateTime nextTime = QDateTime::currentDateTime().addDays(day ? 1 : 7);

        taskManager.addTask(Tasks(files,
                                  backupName + ".bak",
                                  day ? "每天" : "每周",
                                  passwordCheckBox ? password : "",
                                  backupDirectory + "/" + backupName + ".bak",
                                  nextTime,
                                  this->isCloud ? "是" : "否"));
    }

    ui->progressBar->setValue(90);

    clearBackupConfig();
    on_clearButton_clicked();

    ui->progressBar->setValue(100);
}

void Widget::on_settingButton_clicked()
{
    settingDialog* settings = new settingDialog(this);
    settings->exec();

}

void Widget::setBackupConfig(QLineEdit* backupName,
                             QLineEdit* backupDirectory,
                             QCheckBox* passwordCheckBox,
                             QLineEdit* password,
                             QRadioButton* once,
                             QRadioButton* day,
                             QRadioButton* week,
                             QCheckBox* isCloud)
{
    this->backupName = backupName->text();
    this->backupDirectory = backupDirectory->text();
    this->passwordCheckBox = passwordCheckBox->isChecked();
    this->password = password->text();
    this->once = once->isChecked();
    this->day = day->isChecked();
    this->week = week->isChecked();
    this->isCloud = isCloud->isChecked();
}

void Widget::clearBackupConfig()
{
    this->backupName = "";
    this->backupDirectory = "";
    this->passwordCheckBox = false;
    this->password = "";
    this->isCloud = false;
}

void Widget::showTasks(Tasks t)
{
    QTableWidgetItem* bakName = new QTableWidgetItem;
    QTableWidgetItem* freq = new QTableWidgetItem;
    QTableWidgetItem* isCode = new QTableWidgetItem;
    QTableWidgetItem* localPath = new QTableWidgetItem;
    QTableWidgetItem* isCloud = new QTableWidgetItem;

    bakName->setText(t.bakName);
    freq->setText(t.freq);
    isCode->setText(t.isCode == "" ? "否" : "是");
    localPath->setText(t.localPath);
    isCloud->setText(t.isCloud);

    int RowCount = ui->taskTableWidget->rowCount();
    ui->taskTableWidget->insertRow(RowCount);
    ui->taskTableWidget->setItem(RowCount, 0, bakName);
    ui->taskTableWidget->setItem(RowCount, 1, freq);
    ui->taskTableWidget->setItem(RowCount, 2, isCode);
    ui->taskTableWidget->setItem(RowCount, 3, localPath);
    ui->taskTableWidget->setItem(RowCount, 4, isCloud);

    return;
}

void Widget::setUserInfo(QLineEdit *username, QLineEdit *loginPwd)
{
    this->username = username->text();
    this->loginPwd = loginPwd->text();
}

int Widget::getUserId()
{
    return this->user_id;
}

int Widget::registerUser(QString username, QString pwd)
{
    QString sql = QString("select count(*) from user where username = '%1'").arg(username);
    QSqlQuery query;
    if(!query.exec(sql))
        qDebug()<<query.lastError().text();
    query.next();
    if(query.value(0).toInt() != 0) return 1;
    else
    {
        QString regPwd = QString::fromStdString(MD5().getMD5(pwd.toStdString()));
        sql = QString("insert into user(username, password) values('%1', '%2');").arg(username).arg(regPwd);
        if(!query.exec(sql))
            qDebug()<<query.lastError().text();
        else
           return 0;
    }
}

void Widget::on_addBackupFileButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(
                this,
                "选择一个备份文件",
                "",
                "备份文件 (*.bak)");
    if (file != "") {
        ui->backupFileLineEdit->setText(file);
    }
}

void Widget::on_chooseDirButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(
                            this,
                            tr("恢复到"),
                            "/home",
                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (dir != "") {
        ui->desDirLineEdit->setText(dir);
    }
}

void Widget::on_startRecoverButton_clicked()
{
    ui->progressBar_2->setValue(0);

    if (ui->backupFileLineEdit->text().trimmed() == "") {
        QMessageBox::information(this, "提示", "请选择要恢复的备份文件。", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    if (ui->desDirLineEdit->text().trimmed() == "") {
        QMessageBox::information(this, "提示", "请选择要恢复到的目录。", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    if (ui->pwdCheckBox->isChecked() && ui->pwdLineEdit->text().trimmed() == "") {
        QMessageBox::information(this, "提示", "请输入密码。", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }

    //解密解压
    Decompress decompressor;
    int errCode = decompressor.decompress(ui->backupFileLineEdit->text().toStdString(),
                                          ui->desDirLineEdit->text().toStdString() + "/",
                                          ui->pwdCheckBox->isChecked() ? ui->pwdLineEdit->text().toStdString() : "");
    if (errCode == 0)
    {
        qDebug() << "decompress complete" << endl;
    }
    else if(errCode == 2)
    {
        QMessageBox::warning(this, "警告", "密码错误！", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }

    ui->progressBar_2->setValue(30);

    QString temp = ui->desDirLineEdit->text() + "/" + QFileInfo(ui->backupFileLineEdit->text()).fileName();
    temp = temp.left(temp.length() - 3) + "tar";
//    qDebug() << temp << endl;

    //解包
    if(!Unpackage::unpackage(temp, ui->desDirLineEdit->text()))
    {
        qDebug() << "unpackage complete" << endl;
    }

    ui->progressBar_2->setValue(60);

    //删除临时文件
    QFile t(temp);
    t.remove();

    ui->progressBar_2->setValue(100);
}

void Widget::on_pwdCheckBox_stateChanged(int arg1)
{
    ui->pwdLineEdit->setEnabled(ui->pwdCheckBox->checkState());
}


void Widget::on_deleteTaskButton_clicked()
{
    int index = ui->taskTableWidget->currentRow();
    if (index != -1)
    {
        taskManager.deleteTask(index);
        ui->taskTableWidget->removeRow(index);
    }
}

void Widget::on_clearTaskButton_clicked()
{
    int RowCount = ui->taskTableWidget->rowCount();
    for(int i = RowCount - 1; i >= 0; i--)
    {
        ui->taskTableWidget->removeRow(i);
    }
    taskManager.clear();
}

void Widget::timeout_SLOT()
{
    //执行定时任务
    if (taskManager.getTaskList().count())
    {
        for(auto& t : taskManager.getTaskList())
        {
            //执行
            if (t.nextTime <= QDateTime::currentDateTime())
            {
                QStringList files;
                for (QString f : t.files) {
                    files.append(f);
                }

                //打包
                if (Package::pack(files, t.bakName + ".tar"))
                {
                    qDebug() <<"Task: "<< t.bakName << "package failed" << endl;
                }

                //压缩加密
                //压缩
                Compress compressor;
                if(compressor.compress(t.bakName.toStdString() + ".tar",
                                       t.localPath.toStdString().substr(0, t.localPath.toStdString().find_last_of("/")),
                                       t.isCode.toStdString()));
                {
                    qDebug() << "compress complete" << endl;
                }

                //删除中间文件
                QFile temp(t.bakName + ".tar");
                temp.remove();
                //云备份
                if(t.isCloud == "是")
                {
                    QDateTime now = QDateTime::currentDateTime();
                    QSqlQuery query;
                    QString sql = QString("insert into file(backupName, date, user_id) values('%1', '%2', '%3');").arg(t.bakName + ".bak").arg(now.toString("yyyy-MM-dd hh:mm:ss")).arg(user_id);
                    if(!query.exec(sql))
                        qDebug()<<query.lastError().text();

                    sql = QString("select id from file where user_id = '%1' AND backupName = '%2' AND date = '%3'").arg(user_id).arg(t.bakName + ".bak").arg(now.toString("yyyy-MM-dd hh:mm:ss"));
                    if(!query.exec(sql))
                        qDebug()<<query.lastError().text();
                    query.next();
                    QVariant file_id = query.value(0);
                    QByteArray data;
                    QFile cloudFile(t.localPath);
                    if(!cloudFile.open(QFile::ReadOnly))
                    {
                        qDebug() <<"update file open failed";
                    }
                    data = cloudFile.readAll();
                    cloudFile.close();
                    QVariant content(data);
                    sql = QString("insert into file_content(content, file_id) values(?, ?);");
                    query.prepare(sql);
                    query.addBindValue(content);
                    query.addBindValue(file_id);
                    if(!query.exec())
                        qDebug()<<query.lastError().text();
                }
                // 更新下一次备份时间
                int index;
                for(int i = 0; i < ui->taskTableWidget->rowCount(); i++)
                {
                    if(t.localPath == taskManager.getTaskList()[i].localPath)
                    {
                        index = i;
                        break;
                    }

                }
                taskManager.updateTime(index, t.nextTime.addDays(t.freq == "每日" ? 1 : 7));
                taskManager.writeJson();
            }
        }
    }
    timer.start(60 * 1000);
}

void Widget::on_refreshPushButton_clicked()
{
    int RowCount = ui->cloudFileTableWidget->rowCount();
    for(int i = RowCount - 1; i >= 0; i--)
    {
        ui->cloudFileTableWidget->removeRow(i);
    }
    QSqlQuery query;
    QString sql = QString("select backupName, date from file where user_id = '%1';").arg(this->user_id);
    query.exec(sql);
    while(query.next())
    {
        RowCount = ui->cloudFileTableWidget->rowCount();
        ui->cloudFileTableWidget->insertRow(RowCount);
        QTableWidgetItem* bkName = new QTableWidgetItem;
        QTableWidgetItem* bkDate = new QTableWidgetItem;
        bkName->setText(query.value(0).toString());
        bkDate->setText(query.value(1).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        ui->cloudFileTableWidget->setItem(RowCount, 0, bkName);
        ui->cloudFileTableWidget->setItem(RowCount, 1, bkDate);
    }
}


void Widget::on_loginPushButton_clicked()
{
    loginDialog* login = new loginDialog(this);
    login->exec();
    QString sql = QString("select password, id from user where username = '%1';").arg(username);
    QSqlQuery query;
    query.exec(sql);
    if(username==""||loginPwd=="") return;
    if(!query.next())
    {
        QMessageBox::information(this, "提示", "用户名不存在。", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    QString pwd = QString::fromStdString(MD5().getMD5(loginPwd.toStdString()));
    qDebug()<<pwd;
    if(query.value(0) != pwd)
    {
        QMessageBox::information(this, "提示", "密码错误", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    else
    {
        int RowCount = ui->cloudFileTableWidget->rowCount();
        for(int i = RowCount - 1; i >= 0; i--)
        {
            ui->cloudFileTableWidget->removeRow(i);
        }
        QVariant user_id = query.value(1);
        this->user_id = user_id.toInt();
        QMessageBox::information(this, "提示", "登录成功", QMessageBox::Yes, QMessageBox::Yes);
        QString sql = QString("select backupName, date from file where user_id = '%1';").arg(this->user_id);
        query.exec(sql);
        while(query.next())
        {
            RowCount = ui->cloudFileTableWidget->rowCount();
            ui->cloudFileTableWidget->insertRow(RowCount);
            QTableWidgetItem* bkName = new QTableWidgetItem;
            QTableWidgetItem* bkDate = new QTableWidgetItem;
            bkName->setText(query.value(0).toString());
            bkDate->setText(query.value(1).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
            ui->cloudFileTableWidget->setItem(RowCount, 0, bkName);
            ui->cloudFileTableWidget->setItem(RowCount, 1, bkDate);
        }
        return;
    }

}

void Widget::chooseCloudFile_SLOT()
{
    int index = ui->cloudFileTableWidget->currentRow();
    QString s = ui->cloudFileTableWidget->model()->index(index,0).data().toString();
    ui->chooseFileLineEdit->setText(s);
}


void Widget::on_cloudDirPushButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(
                            this,
                            tr("恢复到"),
                            "/home",
                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (dir != "") {
        ui->dirLineEdit->setText(dir);
    }
}


void Widget::on_pwdCheckBox_2_stateChanged(int arg1)
{
    ui->pwdLineEdit_2->setEnabled(ui->pwdCheckBox_2->checkState());
}


void Widget::on_cloudRecoverPushButton_clicked()
{
    int index = ui->cloudFileTableWidget->currentRow();
    QString bkName = ui->cloudFileTableWidget->model()->index(index,0).data().toString();
    QString time = ui->cloudFileTableWidget->model()->index(index,1).data().toString();
    QString sql = QString("select id from file where user_id = '%1' AND backupName = '%2' AND date = '%3'").arg(user_id).arg(bkName).arg(time);
    QSqlQuery query;
    if(!query.exec(sql))
        qDebug()<<query.lastError().text();
    query.next();
    QVariant file_id = query.value(0);
    sql = QString("select content from file_content where file_id = '%1'").arg(file_id.toInt());
    if(!query.exec(sql))
        qDebug()<<query.lastError().text();
    query.next();
    QString tempbak = ui->dirLineEdit->text() + "/" + ui->chooseFileLineEdit->text();
    QFile download(tempbak);
    if(!download.open(QFile::WriteOnly))
    {
        qDebug() <<"download file open failed";
    }
    download.write(query.value(0).toByteArray());
    download.close();
    //目标目录
    QString desDir = ui->dirLineEdit->text();

    //解密解压
    Decompress decompressor;
    int errCode = decompressor.decompress(tempbak.toStdString(),
                                          desDir.toStdString() + "/",
                                          ui->pwdCheckBox_2->isChecked() ? ui->pwdLineEdit_2->text().toStdString() : "");
    if (errCode == 0)
    {
        qDebug() << "decompress complete" << endl;
    }
    else if(errCode == 2)
    {
        QMessageBox::warning(this, "警告", "密码错误！", QMessageBox::Yes, QMessageBox::Yes);
    }

    QString temp = desDir + "/" + QFileInfo(tempbak).fileName();
    temp = temp.left(temp.length() - 3) + "tar";
//    qDebug() << temp << endl;

    //解包
    if(!Unpackage::unpackage(temp, desDir))
    {
        qDebug() << "unpackage complete" << endl;
    }

    //删除临时文件
    QFile t(temp);
    QFile t1(tempbak);
    t.remove();
    t1.remove();
}


void Widget::on_deleteCloudPushButton_clicked()
{
    int index = ui->cloudFileTableWidget->currentRow();
    QString bkName = ui->cloudFileTableWidget->model()->index(index,0).data().toString();
    QString time = ui->cloudFileTableWidget->model()->index(index,1).data().toString();
    QString sql = QString("delete from file where user_id = '%1' AND backupName = '%2' AND date = '%3'").arg(user_id).arg(bkName).arg(time);
    QSqlQuery query;
    if(!query.exec(sql))
        qDebug()<<query.lastError().text();
    ui->cloudFileTableWidget->removeRow(index);
}

