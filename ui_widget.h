/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *backupFileList;
    QPushButton *startButton;
    QProgressBar *progressBar;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addFileButton;
    QPushButton *addFoldButton;
    QPushButton *deleteButton;
    QPushButton *clearButton;
    QPushButton *settingButton;
    QWidget *tab_2;
    QLabel *label;
    QLineEdit *backupFileLineEdit;
    QPushButton *addBackupFileButton;
    QLabel *label_2;
    QLineEdit *desDirLineEdit;
    QPushButton *chooseDirButton;
    QLineEdit *pwdLineEdit;
    QPushButton *startRecoverButton;
    QCheckBox *pwdCheckBox;
    QProgressBar *progressBar_2;
    QLabel *label_11;
    QWidget *tab_3;
    QTableWidget *taskTableWidget;
    QPushButton *deleteTaskButton;
    QPushButton *clearTaskButton;
    QWidget *tab_4;
    QLabel *label_3;
    QPushButton *refreshPushButton;
    QTableWidget *cloudFileTableWidget;
    QLabel *label_4;
    QLabel *label_5;
    QCheckBox *pwdCheckBox_2;
    QPushButton *loginPushButton;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLineEdit *pwdLineEdit_2;
    QLineEdit *chooseFileLineEdit;
    QPushButton *deleteCloudPushButton;
    QPushButton *cloudDirPushButton;
    QPushButton *cloudRecoverPushButton;
    QLineEdit *dirLineEdit;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(890, 580);
        Widget->setMinimumSize(QSize(890, 580));
        Widget->setMaximumSize(QSize(890, 580));
        Widget->setAutoFillBackground(false);
        Widget->setStyleSheet(QString::fromUtf8(""));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 904, 600));
        tabWidget->setMinimumSize(QSize(904, 600));
        tabWidget->setMaximumSize(QSize(904, 600));
        tabWidget->setCursor(QCursor(Qt::ArrowCursor));
        tabWidget->setStyleSheet(QString::fromUtf8("#tab,#tab_2,#tab_3,#tab_4\n"
"{\n"
"border-image:url(:/img/main_background.jpeg)\n"
"}\n"
"\n"
"#backupFileList\n"
"{\n"
"background:rgba(0,0,0,0.1);\n"
"}\n"
"\n"
"#taskTableWidget\n"
"{\n"
"color:white;\n"
"background:rgba(0,0,0,0.1);\n"
"}\n"
"\n"
"#loginPushButton\n"
"{\n"
"border-radius:16px;\n"
"background:transparent;\n"
"}\n"
"\n"
"#loginPushButton:hover\n"
"{\n"
"border-radius:17px;\n"
"background:rgba(0,0,0,0.3);\n"
"}\n"
"\n"
"#cloudFileTableWidget\n"
"{\n"
"background:rgba(0,0,0,0.1);\n"
"}\n"
"\n"
"#addFileButton,#addFoldButton,#deleteButton,#clearButton,#settingButton,#startButton,#addBackupFileButton,#chooseDirButton,#startRecoverButton\n"
"{\n"
"color:white;\n"
"font-size:16px;\n"
"font-weight:bold;\n"
"background:transparent;\n"
"}\n"
"#addFileButton:hover,#addFoldButton:hover,#deleteButton:hover,#clearButton:hover,#settingButton:hover,#startButton:hover,\n"
"#addBackupFileButton:hover,#chooseDirButton:hover,#startRecoverButton:hover\n"
"{\n"
"background:rgba(0,0,0,0.1);\n"
"\n"
"}\n"
"#progre"
                        "ssBar\n"
"{\n"
"background:transparent;\n"
"}\n"
"\n"
"QLineEdit#backupFileLineEdit,#desDirLineEdit,#pwdLineEdit\n"
"{\n"
"	background:transparent;\n"
"	border:none;\n"
"	color:white;\n"
"	border-bottom:1px solid #717072;\n"
"	font-family:times new roman;\n"
"	font-size:20px;\n"
"font-weight:bold;\n"
"}\n"
"QLabel#label,#label_2,#label_11\n"
"{\n"
"	color:white;\n"
"	background:transparent;\n"
"	font-family:century gothic;\n"
"	font-size:20px;\n"
"font-weight:bold;\n"
"}\n"
"\n"
""));
        tabWidget->setIconSize(QSize(20, 20));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        backupFileList = new QTableWidget(tab);
        if (backupFileList->columnCount() < 2)
            backupFileList->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        backupFileList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        backupFileList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        backupFileList->setObjectName(QString::fromUtf8("backupFileList"));
        backupFileList->setGeometry(QRect(32, 22, 820, 340));
        backupFileList->setMinimumSize(QSize(820, 340));
        backupFileList->setMaximumSize(QSize(820, 340));
        backupFileList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        startButton = new QPushButton(tab);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(730, 445, 121, 39));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        startButton->setIcon(icon);
        startButton->setIconSize(QSize(30, 30));
        progressBar = new QProgressBar(tab);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(47, 448, 651, 35));
        progressBar->setValue(24);
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(190, 380, 661, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addFileButton = new QPushButton(widget);
        addFileButton->setObjectName(QString::fromUtf8("addFileButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/addFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        addFileButton->setIcon(icon1);
        addFileButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(addFileButton);

        addFoldButton = new QPushButton(widget);
        addFoldButton->setObjectName(QString::fromUtf8("addFoldButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/addFold.png"), QSize(), QIcon::Normal, QIcon::Off);
        addFoldButton->setIcon(icon2);
        addFoldButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(addFoldButton);

        deleteButton = new QPushButton(widget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon3);
        deleteButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(deleteButton);

        clearButton = new QPushButton(widget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearButton->setIcon(icon4);
        clearButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(clearButton);

        settingButton = new QPushButton(widget);
        settingButton->setObjectName(QString::fromUtf8("settingButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingButton->setIcon(icon5);
        settingButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(settingButton);

        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/backup.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon6, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(51, 121, 91, 21));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        backupFileLineEdit = new QLineEdit(tab_2);
        backupFileLineEdit->setObjectName(QString::fromUtf8("backupFileLineEdit"));
        backupFileLineEdit->setEnabled(false);
        backupFileLineEdit->setGeometry(QRect(160, 106, 500, 39));
        addBackupFileButton = new QPushButton(tab_2);
        addBackupFileButton->setObjectName(QString::fromUtf8("addBackupFileButton"));
        addBackupFileButton->setGeometry(QRect(700, 109, 121, 39));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/browser.png"), QSize(), QIcon::Normal, QIcon::Off);
        addBackupFileButton->setIcon(icon7);
        addBackupFileButton->setIconSize(QSize(30, 30));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(69, 184, 71, 20));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        desDirLineEdit = new QLineEdit(tab_2);
        desDirLineEdit->setObjectName(QString::fromUtf8("desDirLineEdit"));
        desDirLineEdit->setEnabled(false);
        desDirLineEdit->setGeometry(QRect(160, 169, 500, 39));
        chooseDirButton = new QPushButton(tab_2);
        chooseDirButton->setObjectName(QString::fromUtf8("chooseDirButton"));
        chooseDirButton->setGeometry(QRect(700, 172, 121, 39));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/dir.png"), QSize(), QIcon::Normal, QIcon::Off);
        chooseDirButton->setIcon(icon8);
        chooseDirButton->setIconSize(QSize(30, 30));
        pwdLineEdit = new QLineEdit(tab_2);
        pwdLineEdit->setObjectName(QString::fromUtf8("pwdLineEdit"));
        pwdLineEdit->setEnabled(false);
        pwdLineEdit->setGeometry(QRect(160, 230, 500, 39));
        startRecoverButton = new QPushButton(tab_2);
        startRecoverButton->setObjectName(QString::fromUtf8("startRecoverButton"));
        startRecoverButton->setGeometry(QRect(700, 290, 121, 39));
        startRecoverButton->setIcon(icon);
        startRecoverButton->setIconSize(QSize(30, 30));
        pwdCheckBox = new QCheckBox(tab_2);
        pwdCheckBox->setObjectName(QString::fromUtf8("pwdCheckBox"));
        pwdCheckBox->setGeometry(QRect(76, 242, 21, 31));
        pwdCheckBox->setLayoutDirection(Qt::LeftToRight);
        progressBar_2 = new QProgressBar(tab_2);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(160, 300, 500, 27));
        progressBar_2->setValue(24);
        progressBar_2->setInvertedAppearance(false);
        progressBar_2->setTextDirection(QProgressBar::TopToBottom);
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(90, 241, 51, 31));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/recover.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon9, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        taskTableWidget = new QTableWidget(tab_3);
        if (taskTableWidget->columnCount() < 5)
            taskTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        taskTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        taskTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        taskTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        taskTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        taskTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem6);
        taskTableWidget->setObjectName(QString::fromUtf8("taskTableWidget"));
        taskTableWidget->setGeometry(QRect(20, 20, 820, 430));
        taskTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        deleteTaskButton = new QPushButton(tab_3);
        deleteTaskButton->setObjectName(QString::fromUtf8("deleteTaskButton"));
        deleteTaskButton->setGeometry(QRect(625, 480, 93, 28));
        clearTaskButton = new QPushButton(tab_3);
        clearTaskButton->setObjectName(QString::fromUtf8("clearTaskButton"));
        clearTaskButton->setGeometry(QRect(747, 480, 93, 28));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/img/task.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_3, icon10, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(28, 19, 69, 20));
        refreshPushButton = new QPushButton(tab_4);
        refreshPushButton->setObjectName(QString::fromUtf8("refreshPushButton"));
        refreshPushButton->setGeometry(QRect(95, 11, 60, 34));
        refreshPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background:transparent;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"background:rgba(0,0,0,0.3);\n"
"}"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/img/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        refreshPushButton->setIcon(icon11);
        cloudFileTableWidget = new QTableWidget(tab_4);
        if (cloudFileTableWidget->columnCount() < 2)
            cloudFileTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        cloudFileTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        cloudFileTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        cloudFileTableWidget->setObjectName(QString::fromUtf8("cloudFileTableWidget"));
        cloudFileTableWidget->setGeometry(QRect(25, 51, 820, 291));
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(35, 369, 61, 20));
        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(34, 425, 61, 20));
        pwdCheckBox_2 = new QCheckBox(tab_4);
        pwdCheckBox_2->setObjectName(QString::fromUtf8("pwdCheckBox_2"));
        pwdCheckBox_2->setGeometry(QRect(27, 482, 61, 19));
        loginPushButton = new QPushButton(tab_4);
        loginPushButton->setObjectName(QString::fromUtf8("loginPushButton"));
        loginPushButton->setGeometry(QRect(805, 11, 34, 34));
        loginPushButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/img/user.png"), QSize(), QIcon::Normal, QIcon::Off);
        loginPushButton->setIcon(icon12);
        widget1 = new QWidget(tab_4);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(95, 365, 741, 141));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pwdLineEdit_2 = new QLineEdit(widget1);
        pwdLineEdit_2->setObjectName(QString::fromUtf8("pwdLineEdit_2"));
        pwdLineEdit_2->setEnabled(false);

        gridLayout->addWidget(pwdLineEdit_2, 4, 0, 1, 1);

        chooseFileLineEdit = new QLineEdit(widget1);
        chooseFileLineEdit->setObjectName(QString::fromUtf8("chooseFileLineEdit"));
        chooseFileLineEdit->setEnabled(false);

        gridLayout->addWidget(chooseFileLineEdit, 0, 0, 1, 1);

        deleteCloudPushButton = new QPushButton(widget1);
        deleteCloudPushButton->setObjectName(QString::fromUtf8("deleteCloudPushButton"));

        gridLayout->addWidget(deleteCloudPushButton, 0, 1, 1, 1);

        cloudDirPushButton = new QPushButton(widget1);
        cloudDirPushButton->setObjectName(QString::fromUtf8("cloudDirPushButton"));

        gridLayout->addWidget(cloudDirPushButton, 2, 1, 1, 1);

        cloudRecoverPushButton = new QPushButton(widget1);
        cloudRecoverPushButton->setObjectName(QString::fromUtf8("cloudRecoverPushButton"));

        gridLayout->addWidget(cloudRecoverPushButton, 4, 1, 1, 1);

        dirLineEdit = new QLineEdit(widget1);
        dirLineEdit->setObjectName(QString::fromUtf8("dirLineEdit"));
        dirLineEdit->setEnabled(false);

        gridLayout->addWidget(dirLineEdit, 2, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 1, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 3, 0, 1, 1);

        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/img/cloud.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_4, icon13, QString());

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        QTableWidgetItem *___qtablewidgetitem = backupFileList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "\346\226\207\344\273\266\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = backupFileList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "\350\267\257\345\276\204", nullptr));
        startButton->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\345\244\207\344\273\275", nullptr));
        addFileButton->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\346\226\207\344\273\266", nullptr));
        addFoldButton->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\346\226\207\344\273\266\345\244\271", nullptr));
        deleteButton->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        clearButton->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
        settingButton->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Widget", "\345\244\207\344\273\275", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\244\207\344\273\275\345\220\215", nullptr));
        addBackupFileButton->setText(QCoreApplication::translate("Widget", "\346\265\217\350\247\210", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\201\242\345\244\215\345\210\260", nullptr));
        chooseDirButton->setText(QCoreApplication::translate("Widget", "\351\200\211\346\213\251\347\233\256\345\275\225", nullptr));
        startRecoverButton->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\346\201\242\345\244\215", nullptr));
        pwdCheckBox->setText(QString());
        label_11->setText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Widget", "\346\201\242\345\244\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = taskTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Widget", "\345\244\207\344\273\275\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = taskTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Widget", "\345\244\207\344\273\275\351\242\221\347\216\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = taskTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Widget", "\345\212\240\345\257\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = taskTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Widget", "\346\234\254\345\234\260\350\267\257\345\276\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = taskTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Widget", "\344\272\221\345\244\207\344\273\275", nullptr));
        deleteTaskButton->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        clearTaskButton->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Widget", "\346\210\221\347\232\204\344\273\273\345\212\241", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\344\272\221\347\253\257\345\244\207\344\273\275", nullptr));
        refreshPushButton->setText(QString());
        QTableWidgetItem *___qtablewidgetitem7 = cloudFileTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Widget", "\346\226\207\344\273\266\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = cloudFileTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Widget", "\346\227\245\346\234\237", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\267\262\351\200\211\346\213\251", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\346\201\242\345\244\215\345\210\260", nullptr));
        pwdCheckBox_2->setText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
        loginPushButton->setText(QString());
        deleteCloudPushButton->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        cloudDirPushButton->setText(QCoreApplication::translate("Widget", "\346\265\217\350\247\210", nullptr));
        cloudRecoverPushButton->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\346\201\242\345\244\215", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Widget", "\346\210\221\347\232\204\344\272\221\345\244\207\344\273\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
