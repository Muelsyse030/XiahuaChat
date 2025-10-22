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
    qDebug() << "RegsiterDialog: connected to HttpMgr instance:" << HttpMgr::GetInstance().get();
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
    qDebug() << "slot_reg_mod_finish called:" << id << res << err;
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
    _handlers.insert(ReqId::ID_GET_VARIFY_CODE,[this](const QJsonObject& jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCESS){
            return;
        }
        auto email = jsonObj["email"].toString();
        showTip(tr("验证码已经发送到邮箱"),true);
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

