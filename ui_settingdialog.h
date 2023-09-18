/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingDialog
{
public:
    QPushButton *chooseDirectoryButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *backupNameLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *backupDirectoryLineEdit;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QRadioButton *onceRadioButton;
    QRadioButton *dayRadioButton;
    QRadioButton *weekRadioButton;
    QHBoxLayout *horizontalLayout;
    QCheckBox *cloudCheckBox;
    QCheckBox *passwordCheckBox;
    QLineEdit *passwordLineEdit;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *saveButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;

    void setupUi(QDialog *settingDialog)
    {
        if (settingDialog->objectName().isEmpty())
            settingDialog->setObjectName(QString::fromUtf8("settingDialog"));
        settingDialog->resize(460, 290);
        settingDialog->setMinimumSize(QSize(460, 290));
        settingDialog->setMaximumSize(QSize(460, 290));
        chooseDirectoryButton = new QPushButton(settingDialog);
        chooseDirectoryButton->setObjectName(QString::fromUtf8("chooseDirectoryButton"));
        chooseDirectoryButton->setGeometry(QRect(369, 87, 85, 29));
        widget = new QWidget(settingDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 40, 301, 81));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label);

        backupNameLineEdit = new QLineEdit(widget);
        backupNameLineEdit->setObjectName(QString::fromUtf8("backupNameLineEdit"));

        horizontalLayout_4->addWidget(backupNameLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_2);

        backupDirectoryLineEdit = new QLineEdit(widget);
        backupDirectoryLineEdit->setObjectName(QString::fromUtf8("backupDirectoryLineEdit"));
        backupDirectoryLineEdit->setEnabled(false);

        horizontalLayout_3->addWidget(backupDirectoryLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        widget1 = new QWidget(settingDialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(40, 130, 348, 62));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_4);

        onceRadioButton = new QRadioButton(widget1);
        onceRadioButton->setObjectName(QString::fromUtf8("onceRadioButton"));
        onceRadioButton->setChecked(true);

        horizontalLayout_2->addWidget(onceRadioButton);

        dayRadioButton = new QRadioButton(widget1);
        dayRadioButton->setObjectName(QString::fromUtf8("dayRadioButton"));

        horizontalLayout_2->addWidget(dayRadioButton);

        weekRadioButton = new QRadioButton(widget1);
        weekRadioButton->setObjectName(QString::fromUtf8("weekRadioButton"));

        horizontalLayout_2->addWidget(weekRadioButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cloudCheckBox = new QCheckBox(widget1);
        cloudCheckBox->setObjectName(QString::fromUtf8("cloudCheckBox"));

        horizontalLayout->addWidget(cloudCheckBox);

        passwordCheckBox = new QCheckBox(widget1);
        passwordCheckBox->setObjectName(QString::fromUtf8("passwordCheckBox"));

        horizontalLayout->addWidget(passwordCheckBox);

        passwordLineEdit = new QLineEdit(widget1);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setEnabled(false);

        horizontalLayout->addWidget(passwordLineEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        widget2 = new QWidget(settingDialog);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(90, 214, 261, 31));
        horizontalLayout_5 = new QHBoxLayout(widget2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        saveButton = new QPushButton(widget2);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout_5->addWidget(saveButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        cancelButton = new QPushButton(widget2);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_5->addWidget(cancelButton);


        retranslateUi(settingDialog);

        QMetaObject::connectSlotsByName(settingDialog);
    } // setupUi

    void retranslateUi(QDialog *settingDialog)
    {
        settingDialog->setWindowTitle(QCoreApplication::translate("settingDialog", "Dialog", nullptr));
        chooseDirectoryButton->setText(QCoreApplication::translate("settingDialog", "\346\265\217\350\247\210", nullptr));
        label->setText(QCoreApplication::translate("settingDialog", "\345\244\207\344\273\275\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("settingDialog", "\345\244\207\344\273\275\345\210\260", nullptr));
        label_4->setText(QCoreApplication::translate("settingDialog", "\345\244\207\344\273\275\351\242\221\347\216\207", nullptr));
        onceRadioButton->setText(QCoreApplication::translate("settingDialog", "\345\215\225\346\254\241", nullptr));
        dayRadioButton->setText(QCoreApplication::translate("settingDialog", "\346\257\217\346\227\245", nullptr));
        weekRadioButton->setText(QCoreApplication::translate("settingDialog", "\346\257\217\345\221\250", nullptr));
        cloudCheckBox->setText(QCoreApplication::translate("settingDialog", "\344\272\221\345\244\207\344\273\275", nullptr));
        passwordCheckBox->setText(QCoreApplication::translate("settingDialog", "\345\212\240\345\257\206\345\244\207\344\273\275", nullptr));
        saveButton->setText(QCoreApplication::translate("settingDialog", "\344\277\235\345\255\230", nullptr));
        cancelButton->setText(QCoreApplication::translate("settingDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingDialog: public Ui_settingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
