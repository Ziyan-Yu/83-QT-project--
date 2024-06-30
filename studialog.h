#ifndef STUDIALOG_H
#define STUDIALOG_H

#include <QDialog>

namespace Ui {
class StuDialog;
}

class StuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StuDialog(QWidget *parent = nullptr);
    ~StuDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::StuDialog *ui;
};

#endif // STUDIALOG_H
