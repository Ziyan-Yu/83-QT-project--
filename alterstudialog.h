#ifndef ALTERSTUDIALOG_H
#define ALTERSTUDIALOG_H

#include <QDialog>

namespace Ui {
class alterstudialog;
}

class alterstudialog : public QDialog
{
    Q_OBJECT

public:
    explicit alterstudialog(QWidget *parent = nullptr);
    ~alterstudialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::alterstudialog *ui;
};

#endif // ALTERSTUDIALOG_H
