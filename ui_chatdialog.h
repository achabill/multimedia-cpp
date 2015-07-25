/********************************************************************************
** Form generated from reading UI file 'chatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIALOG_H
#define UI_CHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ChatDialog
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QSplitter *splitter;
    QTextEdit *textEdit;
    QListWidget *listWidget;

    void setupUi(QDialog *ChatDialog)
    {
        if (ChatDialog->objectName().isEmpty())
            ChatDialog->setObjectName(QStringLiteral("ChatDialog"));
        ChatDialog->resize(533, 355);
        label = new QLabel(ChatDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 319, 46, 16));
        lineEdit = new QLineEdit(ChatDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(62, 319, 461, 20));
        splitter = new QSplitter(ChatDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(10, 10, 511, 301));
        splitter->setOrientation(Qt::Horizontal);
        textEdit = new QTextEdit(splitter);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setFocusPolicy(Qt::NoFocus);
        textEdit->setReadOnly(true);
        splitter->addWidget(textEdit);
        listWidget = new QListWidget(splitter);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMaximumSize(QSize(180, 16777215));
        listWidget->setFocusPolicy(Qt::NoFocus);
        splitter->addWidget(listWidget);

        retranslateUi(ChatDialog);

        QMetaObject::connectSlotsByName(ChatDialog);
    } // setupUi

    void retranslateUi(QDialog *ChatDialog)
    {
        ChatDialog->setWindowTitle(QApplication::translate("ChatDialog", "Chat", 0));
        label->setText(QApplication::translate("ChatDialog", "Message:", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatDialog: public Ui_ChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H
