#ifndef REGSITERDIALOG_H
#define REGSITERDIALOG_H

#include <QDialog>
#include <QRegularExpression>

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

private:
    void showTip(const QString& str,bool b_ok);
    Ui::RegsiterDialog *ui;
};

#endif // REGSITERDIALOG_H
