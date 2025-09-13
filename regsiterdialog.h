#ifndef REGSITERDIALOG_H
#define REGSITERDIALOG_H

#include <QDialog>
#include <QRegularExpression>
#include "global.h"
namespace Ui {
class RegsiterDialog;
}

class RegsiterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegsiterDialog(QWidget *parent = nullptr);
    ~RegsiterDialog();

private slots:
    void on_varify_btn_clicked();
    void slot_reg_mod_finish(ReqId id , QString res , ErrorCodes err);

private:
    void initHttpHandlers();
    void showTip(const QString& str,bool b_ok);
    Ui::RegsiterDialog *ui;
    QMap<ReqId, std::function<void(const QJsonObject&)>> _handlers;

};

#endif // REGSITERDIALOG_H
