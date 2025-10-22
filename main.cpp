#include "mainwindow.h"
#include <QFile>
#include <QApplication>
#include <QDebug>
#include "global.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/style/stylesheet.qss");   // 确保 qrc 路径正确
    if (qss.open(QFile::ReadOnly)) {
        qDebug() << "QSS open success";
        QString style = qss.readAll();
        a.setStyleSheet(style);
    } else {
        qDebug() << "QSS open failed";
    }

    QString fileName = "config.ini";
    QString app_path = QCoreApplication::applicationDirPath();
    QString config_path = QDir::toNativeSeparators(app_path + QDir::separator() + fileName);
    QSettings settings(config_path , QSettings::IniFormat);
    QString gate_host = settings.value("GateServer/host").toString();
    QString gate_port = settings.value("GateServer/port").toString();
    gate_url_prefix = "http://" + gate_host + ":" + gate_port;

    MainWindow w;
    w.show();
    return a.exec();
}
