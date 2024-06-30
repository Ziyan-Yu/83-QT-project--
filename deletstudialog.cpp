#include "deletstudialog.h"
#include "ui_deletstudialog.h"
#include"QMessageBox"
#include"stu.h"
#include<QDebug>

deletstudialog::deletstudialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::deletstudialog)
{
    ui->setupUi(this);

}

deletstudialog::~deletstudialog()
{
    delete ui;
}


void deletstudialog::on_pushButton_clicked()
{
    char* id;
    char* stud;
    char* clas;
    QString instu=ui->stuline->text();
    QByteArray baa=instu.toLatin1();
    stud=baa.data();
    QString inid=ui->idline->text();
    QByteArray ba=inid.toLatin1();
    id=ba.data();
    QString inclas=ui->classline->text();
    QByteArray b=inclas.toLatin1();
    clas=b.data();
    extern vector<Student>stu;
    if(!Delete_stu(stu,id,stud,clas)){
        qDebug()<<"dialog:"<<"failed";
        QMessageBox::information(this,tr("提示"),tr("未在此课程查询到该学生"),QMessageBox::Ok);
    }
    else{
        qDebug()<<"dialog:"<<"success";
        QMessageBox::warning(this,tr("通知"),tr("删除成功"),QMessageBox::Ok);
    }

}

