#ifndef DELETSTUDIALOG_H
#define DELETSTUDIALOG_H

#include <QDialog>

namespace Ui {
class deletstudialog;
}

class deletstudialog : public QDialog
{
    Q_OBJECT

public:
    explicit deletstudialog(QWidget *parent = nullptr);
    ~deletstudialog();

private slots:
    //void on_idline_cursorPositionChanged(int arg1, int arg2);

    //void on_frame_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_clicked();

private:
    Ui::deletstudialog *ui;
};

#endif // DELETSTUDIALOG_H
