#ifndef STUFUNCDIALOG_H
#define STUFUNCDIALOG_H

#include <QDialog>

namespace Ui {
class StuFuncDialog;
}

class StuFuncDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StuFuncDialog(QWidget *parent = nullptr);
    ~StuFuncDialog();
private slots:
    void on_idssButton_clicked();
    void select();

private:
    Ui::StuFuncDialog *ui;
};

#endif // STUFUNCDIALOG_H
