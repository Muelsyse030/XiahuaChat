#include "mainwindow.h"
#include <QFile>
#include <QApplication>
#include <QDebug>

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

    MainWindow w;
    w.show();
    return a.exec();
}
