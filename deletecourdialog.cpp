#include "deletecourdialog.h"
#include "ui_deletecourdialog.h"
#include"student.h"
#include"stu.h"
#include"QMessageBox"
#include<QDebug>

deletecourdialog::deletecourdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::deletecourdialog)
{
    ui->setupUi(this);
}

deletecourdialog::~deletecourdialog()
{
    delete ui;
}

void deletecourdialog::on_pushButton_clicked()
{
    char* id;
    QString inid=ui->idline->text();
    QByteArray baa=inid.toLatin1();
    id=baa.data();
    extern vector<Course>cour;
    if(Delete_course(cour,id)==-1){
        qDebug()<<"dialog:"<<"failed:no id\n";
        QMessageBox::warning(this,tr("提示"),tr("课程不存在！"),QMessageBox::Ok);
    }
    else{
        QMessageBox::information(this,tr("通知"),tr("删除成功！"),QMessageBox::Ok);
    }
}

