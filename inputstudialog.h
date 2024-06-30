#ifndef INPUTSTUDIALOG_H
#define INPUTSTUDIALOG_H

#include <QDialog>

namespace Ui {
class InputStuDialog;
}

class InputStuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputStuDialog(QWidget *parent = nullptr);
    ~InputStuDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InputStuDialog *ui;
};

#endif // INPUTSTUDIALOG_H
