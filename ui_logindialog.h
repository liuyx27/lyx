/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
public:
    QFrame *frame;
    QLabel *label_3;
    QPushButton *loginPushButton;
    QPushButton *registerPushButton;
    QLineEdit *userNameLineEdit;
    QLineEdit *pwdLineEdit;
    QLabel *label_4;
    QLabel *label_5;
    QToolButton *toolButton;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QString::fromUtf8("loginDialog"));
        loginDialog->resize(520, 800);
        loginDialog->setMinimumSize(QSize(520, 800));
        loginDialog->setMaximumSize(QSize(520, 800));
        loginDialog->setStyleSheet(QString::fromUtf8("*{\n"
"	\n"
"}\n"
"\n"
"#frame\n"
"{\n"
"	background:rgba(0,0,0,0.7);\n"
"	border-radius:15px;\n"
"}\n"
"\n"
"#loginDialog\n"
"{\n"
"	background:url(:/img/login_background.jpeg);\n"
"}\n"
"\n"
"\n"
"#loginPushButton,#registerPushButton\n"
"{\n"
"	color:white;\n"
"	background:red;\n"
"	border-radius:15px;\n"
"	font-family:century gothic;\n"
"	font-size:24px;\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton#loginPushButton:hover,#registerPushButton:hover\n"
"{\n"
"	background:rgb(172, 6, 1);\n"
"}\n"
"\n"
"#toolButton\n"
"{\n"
"	background:red;\n"
"	border-radius:60px;\n"
"}\n"
"\n"
"QLabel#label_3,#label_4,#label_5\n"
"{\n"
"	color:white;\n"
"	background:transparent;\n"
"	font-family:century gothic;\n"
"	font-size:24px;\n"
"}\n"
"\n"
"QLineEdit#pwdLineEdit,#userNameLineEdit\n"
"{\n"
"	background:transparent;\n"
"	border:none;\n"
"	color:rgb(113, 112, 114);\n"
"	border-bottom:1px solid #717072;\n"
"	font-family:century gothic;\n"
"	font-size:24px;\n"
"}"));
        frame = new QFrame(loginDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(65, 105, 390, 620));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 80, 110, 20));
        label_3->setAlignment(Qt::AlignCenter);
        loginPushButton = new QPushButton(frame);
        loginPushButton->setObjectName(QString::fromUtf8("loginPushButton"));
        loginPushButton->setGeometry(QRect(55, 415, 280, 50));
        loginPushButton->setCursor(QCursor(Qt::PointingHandCursor));
        registerPushButton = new QPushButton(frame);
        registerPushButton->setObjectName(QString::fromUtf8("registerPushButton"));
        registerPushButton->setGeometry(QRect(55, 500, 280, 50));
        registerPushButton->setCursor(QCursor(Qt::PointingHandCursor));
        userNameLineEdit = new QLineEdit(frame);
        userNameLineEdit->setObjectName(QString::fromUtf8("userNameLineEdit"));
        userNameLineEdit->setGeometry(QRect(55, 185, 280, 40));
        pwdLineEdit = new QLineEdit(frame);
        pwdLineEdit->setObjectName(QString::fromUtf8("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(55, 300, 280, 40));
        pwdLineEdit->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(55, 155, 131, 20));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(54, 270, 121, 20));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        toolButton = new QToolButton(loginDialog);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(200, 40, 120, 120));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/user.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(50, 50));

        retranslateUi(loginDialog);

        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QCoreApplication::translate("loginDialog", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("loginDialog", "LOGIN", nullptr));
        loginPushButton->setText(QCoreApplication::translate("loginDialog", "Login", nullptr));
        registerPushButton->setText(QCoreApplication::translate("loginDialog", "Register", nullptr));
        userNameLineEdit->setText(QString());
        userNameLineEdit->setPlaceholderText(QCoreApplication::translate("loginDialog", "Username", nullptr));
        pwdLineEdit->setPlaceholderText(QCoreApplication::translate("loginDialog", "Password", nullptr));
        label_4->setText(QCoreApplication::translate("loginDialog", "Username", nullptr));
        label_5->setText(QCoreApplication::translate("loginDialog", "Password", nullptr));
        toolButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
