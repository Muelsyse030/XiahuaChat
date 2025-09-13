/********************************************************************************
** Form generated from reading UI file 'regsiterdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGSITERDIALOG_H
#define UI_REGSITERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegsiterDialog
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_8;
    QLabel *err_tip;
    QHBoxLayout *horizontalLayout_6;
    QLabel *user_label;
    QLineEdit *user_edit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *email_label;
    QLineEdit *email_edit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *password_label;
    QLineEdit *password_edit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *comfirm_label;
    QLineEdit *comfirm_edit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *varify_label;
    QLineEdit *varify_edit;
    QPushButton *varify_btn;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *confirm_btn;
    QPushButton *cencel_btn;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_2;

    void setupUi(QDialog *RegsiterDialog)
    {
        if (RegsiterDialog->objectName().isEmpty())
            RegsiterDialog->setObjectName("RegsiterDialog");
        RegsiterDialog->resize(300, 500);
        RegsiterDialog->setMinimumSize(QSize(300, 500));
        RegsiterDialog->setMaximumSize(QSize(300, 500));
        verticalLayout_6 = new QVBoxLayout(RegsiterDialog);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        stackedWidget = new QStackedWidget(RegsiterDialog);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_7 = new QVBoxLayout(page);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        widget = new QWidget(page);
        widget->setObjectName("widget");
        verticalLayout_8 = new QVBoxLayout(widget);
        verticalLayout_8->setObjectName("verticalLayout_8");
        err_tip = new QLabel(widget);
        err_tip->setObjectName("err_tip");
        err_tip->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_8->addWidget(err_tip);


        verticalLayout_7->addWidget(widget);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        user_label = new QLabel(page);
        user_label->setObjectName("user_label");
        user_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_6->addWidget(user_label);

        user_edit = new QLineEdit(page);
        user_edit->setObjectName("user_edit");
        user_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_6->addWidget(user_edit);


        verticalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        email_label = new QLabel(page);
        email_label->setObjectName("email_label");
        email_label->setMinimumSize(QSize(0, 25));
        email_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_7->addWidget(email_label);

        email_edit = new QLineEdit(page);
        email_edit->setObjectName("email_edit");
        email_edit->setMinimumSize(QSize(0, 25));
        email_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_7->addWidget(email_edit);


        verticalLayout_7->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        password_label = new QLabel(page);
        password_label->setObjectName("password_label");
        password_label->setMinimumSize(QSize(0, 25));
        password_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(password_label);

        password_edit = new QLineEdit(page);
        password_edit->setObjectName("password_edit");
        password_edit->setMinimumSize(QSize(0, 25));
        password_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(password_edit);


        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        comfirm_label = new QLabel(page);
        comfirm_label->setObjectName("comfirm_label");
        comfirm_label->setMinimumSize(QSize(0, 25));
        comfirm_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_9->addWidget(comfirm_label);

        comfirm_edit = new QLineEdit(page);
        comfirm_edit->setObjectName("comfirm_edit");
        comfirm_edit->setMinimumSize(QSize(0, 25));
        comfirm_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_9->addWidget(comfirm_edit);


        verticalLayout_7->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        varify_label = new QLabel(page);
        varify_label->setObjectName("varify_label");
        varify_label->setMinimumSize(QSize(0, 25));
        varify_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_10->addWidget(varify_label);

        varify_edit = new QLineEdit(page);
        varify_edit->setObjectName("varify_edit");
        varify_edit->setMinimumSize(QSize(0, 25));
        varify_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_10->addWidget(varify_edit);

        varify_btn = new QPushButton(page);
        varify_btn->setObjectName("varify_btn");
        varify_btn->setMinimumSize(QSize(0, 25));
        varify_btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_10->addWidget(varify_btn);


        verticalLayout_7->addLayout(horizontalLayout_10);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        confirm_btn = new QPushButton(page);
        confirm_btn->setObjectName("confirm_btn");
        confirm_btn->setMinimumSize(QSize(0, 25));
        confirm_btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_11->addWidget(confirm_btn);

        cencel_btn = new QPushButton(page);
        cencel_btn->setObjectName("cencel_btn");
        cencel_btn->setMinimumSize(QSize(0, 25));
        cencel_btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_11->addWidget(cencel_btn);


        verticalLayout_7->addLayout(horizontalLayout_11);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        verticalLayout_5->addWidget(stackedWidget);


        verticalLayout_6->addLayout(verticalLayout_5);


        retranslateUi(RegsiterDialog);

        QMetaObject::connectSlotsByName(RegsiterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegsiterDialog)
    {
        RegsiterDialog->setWindowTitle(QCoreApplication::translate("RegsiterDialog", "Dialog", nullptr));
        err_tip->setText(QCoreApplication::translate("RegsiterDialog", "\351\224\231\350\257\257\346\217\220\347\244\272", nullptr));
        user_label->setText(QCoreApplication::translate("RegsiterDialog", "\347\224\250\346\210\267", nullptr));
        email_label->setText(QCoreApplication::translate("RegsiterDialog", "\351\202\256\347\256\261", nullptr));
        password_label->setText(QCoreApplication::translate("RegsiterDialog", "\345\257\206\347\240\201", nullptr));
        comfirm_label->setText(QCoreApplication::translate("RegsiterDialog", "\347\241\256\350\256\244", nullptr));
        varify_label->setText(QCoreApplication::translate("RegsiterDialog", "\351\252\214\350\257\201\347\240\201", nullptr));
        varify_btn->setText(QCoreApplication::translate("RegsiterDialog", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", nullptr));
        confirm_btn->setText(QCoreApplication::translate("RegsiterDialog", "\347\241\256\350\256\244", nullptr));
        cencel_btn->setText(QCoreApplication::translate("RegsiterDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegsiterDialog: public Ui_RegsiterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGSITERDIALOG_H
