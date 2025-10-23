#include "regsiterdialog.h"
#include "ui_regsiterdialog.h"
#include "global.h"
#include <QRegularExpression>
#include "httpmgr.h"
RegsiterDialog::RegsiterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegsiterDialog)
{
    ui->setupUi(this);
    ui->password_edit->setEchoMode(QLineEdit::Password);
    ui->comfirm_edit->setEchoMode(QLineEdit::Password);
    ui->err_tip->setProperty("state","normal");
    repolish(ui->err_tip);
    connect(HttpMgr::GetInstance().get() , &HttpMgr::sig_reg_mod_finish,
            this , &RegsiterDialog::slot_reg_mod_finish);
    initHttpHandlers();
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
        QJsonObject json_obj;
        json_obj["email"] = email;
        HttpMgr::GetInstance()->PostHttpReq(QUrl(gate_url_prefix+"/get_varifycode"),
            json_obj , ReqId::ID_GET_VARIFY_CODE , Modules::REGISTERMOD);
    }else{
        showTip(tr("邮箱地址不正确"),false);
    }
}

void RegsiterDialog::slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err)
{
    if(err != ErrorCodes::SUCCESS){
        showTip(tr("网络请求错误"),false);
        return;
    }
    //解析json 字符串 res 转化为qbytearry

    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    if(jsonDoc.isEmpty()){
        showTip(tr("json解析失败"),false);
        return;
    }
    //解析错误
    if(!jsonDoc.isObject()){
        showTip(tr("json解析失败"),false);
        return;
    }

    QJsonObject obj = jsonDoc.object();
    _handlers[id](obj);
    return;
}

void RegsiterDialog::initHttpHandlers()
{
    //注册获取验证码回包的逻辑
    _handlers.insert(ReqId::ID_GET_VARIFY_CODE,[this](const QJsonObject& json_obj){
        int error = json_obj["error"].toInt();
        if(error != ErrorCodes::SUCCESS){
            return;
        }
        auto email = json_obj["email"].toString();
        showTip(tr("验证码已经发送到邮箱"),true);
        qDebug() << "email is " << email ;
    });
    //注册注册用户回包的逻辑
    _handlers.insert(ReqId::ID_REG_USER , [this](const QJsonObject& json_obj){
        int error = json_obj["error"].toInt();
        if(error != ErrorCodes::SUCCESS){
            return;
        }
        auto email = json_obj["email"].toString();
        showTip(tr("用户注册成功"),true);
        qDebug() << "email is " << email ;
    });
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


void RegsiterDialog::on_sure_btn_clicked()
{
    if(ui->user_edit->text() == ""){
        showTip(tr("用户名不能为空") , false);
            return;
    }
    auto email = ui->email_edit->text();
    QRegularExpression regex(R"([A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,})");
    bool match = regex.match(email).hasMatch();
    if(!match){
        showTip(tr("邮箱地址格式不正确"),false);
    }
    if(ui->email_edit->text() == ""){
        showTip(tr("邮箱不能为空"),false);
        return;
    }
    if(ui->password_edit->text() == ""){
        showTip(tr("密码不能为空"),false);
        return;
    }
    if(ui->comfirm_label->text() == ""){
        showTip(tr("确认密码不能为空"),false);
        return;
    }
    if(ui->password_edit->text() != ui->comfirm_edit->text()){
        showTip(tr("确认密码和密码不一致"),false);
        return;
    }
    if(ui->varify_edit->text() == ""){
        showTip(tr("验证码不能为空"),false);
            return;
    }
    QJsonObject json_obj;
    json_obj["user_name"] = ui->user_edit->text();
    json_obj["email"] = ui->email_edit->text();
    json_obj["password"] = ui->password_edit->text();
    json_obj["comfirm_password"] = ui->comfirm_edit->text();
    json_obj["varify"] = ui->varify_edit->text();
    HttpMgr::GetInstance()->PostHttpReq(QUrl(gate_url_prefix + "/user_register"),
                         json_obj,ReqId::ID_REG_USER , Modules::REGISTERMOD);
}

