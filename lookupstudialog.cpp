#include "lookupstudialog.h"
#include "student.h"
#include "ui_lookupstudialog.h"
#include"QMessageBox"
#include"stu.h"
#include<QDebug>

lookupstudialog::lookupstudialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::lookupstudialog)
{
    ui->setupUi(this);
}

lookupstudialog::~lookupstudialog()
{
    delete ui;
}

void lookupstudialog::on_idbutton_clicked()
{
    char* id;
    QString inid=ui->idline->text();
    QByteArray baa=inid.toLatin1();
    id=baa.data();
    extern vector<Student>stu;
    if(Lookup_stu(stu,id,true)==-1){
        qDebug()<<"dialog:"<<"failed:no id\n";
        QMessageBox::warning(this,tr("提示"),tr("学号不存在！"),QMessageBox::Ok);
    }
    else{

    }
}


void lookupstudialog::on_stubutton_clicked()
{
    char* name;
    QString inname=ui->stuline->text();
    QByteArray ba=inname.toLatin1();
    name=ba.data();
    extern vector<Student>stu;
    if(Lookup_stu_name(stu,name,true)==-1){
        qDebug()<<"dialog:"<<"failed:no name\n";
        QMessageBox::warning(this,tr("提示"),tr("姓名不存在！"),QMessageBox::Ok);
    }
    else{

    }
}

