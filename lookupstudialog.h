#ifndef LOOKUPSTUDIALOG_H
#define LOOKUPSTUDIALOG_H

#include <QDialog>

namespace Ui {
class lookupstudialog;
}

class lookupstudialog : public QDialog
{
    Q_OBJECT

public:
    explicit lookupstudialog(QWidget *parent = nullptr);
    ~lookupstudialog();

private slots:
    void on_idbutton_clicked();

    void on_stubutton_clicked();

private:
    Ui::lookupstudialog *ui;
};

#endif // LOOKUPSTUDIALOG_H
