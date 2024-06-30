#ifndef DELETECOURDIALOG_H
#define DELETECOURDIALOG_H

#include <QDialog>

namespace Ui {
class deletecourdialog;
}

class deletecourdialog : public QDialog
{
    Q_OBJECT

public:
    explicit deletecourdialog(QWidget *parent = nullptr);
    ~deletecourdialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::deletecourdialog *ui;
};

#endif // DELETECOURDIALOG_H
