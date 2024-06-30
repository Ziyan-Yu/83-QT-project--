#ifndef LOOKUPCOURDIALOG_H
#define LOOKUPCOURDIALOG_H

#include <QDialog>

namespace Ui {
class lookupcourDialog;
}

class lookupcourDialog : public QDialog
{
    Q_OBJECT

public:
    explicit lookupcourDialog(QWidget *parent = nullptr);
    ~lookupcourDialog();

private slots:
    //void on_idspushButton_clicked();

    //void on_namespushButton_clicked();

    void on_idbutton_clicked();

    void on_namebutton_clicked();

private:
    Ui::lookupcourDialog *ui;
};

#endif // LOOKUPCOURDIALOG_H
