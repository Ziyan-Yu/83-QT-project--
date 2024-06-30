#ifndef TEADIALOG_H
#define TEADIALOG_H

#include <QDialog>

namespace Ui {
class TeaDialog;
}

class TeaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TeaDialog(QWidget *parent = nullptr);
    ~TeaDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TeaDialog *ui;
};

#endif // TEADIALOG_H
