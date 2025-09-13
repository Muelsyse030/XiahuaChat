#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _logindialog = new loginDialog(this);
    setCentralWidget(_logindialog);


    //创建和注册消息链接

    connect(_logindialog,&loginDialog::SwitchRegister,this,&MainWindow::SlotSwitchRegister);
    _registerdialog = new RegsiterDialog(this);

    _logindialog->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    _registerdialog->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    _registerdialog->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
    if(_logindialog){
        delete _logindialog;
        _logindialog = nullptr;
    }
    if(_registerdialog){
        delete _registerdialog;
        _registerdialog = nullptr;
    }
}

void MainWindow::SlotSwitchRegister()
{
    setCentralWidget(_registerdialog);
    _logindialog->hide();
    _registerdialog->show();
}
