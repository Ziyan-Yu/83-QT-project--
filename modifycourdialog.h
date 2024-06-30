#ifndef MODIFYCOURDIALOG_H
#define MODIFYCOURDIALOG_H

#include <QDialog>

namespace Ui {
class modifycourdialog;
}

class modifycourdialog : public QDialog
{
    Q_OBJECT

public:
    explicit modifycourdialog(QWidget *parent = nullptr);
    ~modifycourdialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::modifycourdialog *ui;
};

#endif // MODIFYCOURDIALOG_H
