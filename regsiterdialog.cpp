#include "regsiterdialog.h"
#include "ui_regsiterdialog.h"
#include "global.h"
#include <QRegularExpression>
RegsiterDialog::RegsiterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegsiterDialog)
{
    ui->setupUi(this);
    ui->password_edit->setEchoMode(QLineEdit::Password);
    ui->comfirm_edit->setEchoMode(QLineEdit::Password);
    ui->err_tip->setProperty("state","normal");
    repolish(ui->err_tip);
}

RegsiterDialog::~RegsiterDialog()
{
    delete ui;
}

void RegsiterDialog::on_varify_btn_clicked()
{
    auto email = ui->email_edit->text();
    QRegularExpression regex(R"([A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,})");
    bool match = regex.match(email).hasMatch();
    if(match){
        //发送http验证码
    }else{
        showTip(tr("邮箱地址不正确"),false);
    }
}
void RegsiterDialog::showTip(const QString &str , bool b_ok){
    if(b_ok){
        ui->err_tip->setProperty("state","normal");
    }else{
        ui->err_tip->setProperty("state","err");
    }
    ui->err_tip->setText(str);
    repolish(ui->err_tip);
}

