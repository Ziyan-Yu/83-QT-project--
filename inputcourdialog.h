#ifndef INPUTCOURDIALOG_H
#define INPUTCOURDIALOG_H

#include <QDialog>

namespace Ui {
class InputCourDialog;
}

class InputCourDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputCourDialog(QWidget *parent = nullptr);
    ~InputCourDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InputCourDialog *ui;
};

#endif // INPUTCOURDIALOG_H
