#ifndef TEAFUNCDIALOG_H
#define TEAFUNCDIALOG_H

#include <QDialog>

namespace Ui {
class TeaFuncDialog;
}

class TeaFuncDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TeaFuncDialog(QWidget *parent = nullptr);
    ~TeaFuncDialog();

private slots:
    void on_inputstuButton_clicked();

    void on_deletestuButton_clicked();

    void on_modifystuButton_clicked();

    void on_lookupstuButton_clicked();

    void on_inputcourButton_clicked();

    void on_lookupcourButton_clicked();

    void on_deletecoutButton_clicked();

    void on_modifycourButton_clicked();

private:
    Ui::TeaFuncDialog *ui;
};

#endif // TEAFUNCDIALOG_H
