#include "alterstudialog.h"
#include "ui_alterstudialog.h"
#include"QMessageBox"
#include"stu.h"
#include<QDebug>

alterstudialog::alterstudialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::alterstudialog)
{
    ui->setupUi(this);
}

alterstudialog::~alterstudialog()
{
    delete ui;
}

void alterstudialog::on_pushButton_clicked()
{
    char* id;
    char* newstud;
    char* newclas;
    QString instu=ui->stuline->text();
    qDebug()<<"instu:"<<instu;
    QByteArray baa=instu.toLatin1();
    newstud=baa.data();
    QString inid=ui->idline->text();
    QByteArray ba=inid.toLatin1();
    id=ba.data();
    QString inclas=ui->classline->text();
    QByteArray b=inclas.toLatin1();
    newclas=b.data();
    extern vector<Student>stu;
    QMessageBox::information(this,tr("提示"),tr("确认修改信息吗？"),QMessageBox::Ok);
    int ans=Modify_stu(stu,id,newstud,newclas);
    if(!ans){
        qDebug()<<"dialog:"<<"failed:no change";
        QMessageBox::warning(this,tr("提示"),tr("请确认与原信息不同"),QMessageBox::Ok);
    }
    else if(ans==1){
        qDebug()<<"dialog:"<<"success";
        QMessageBox::information(this,tr("通知"),tr("修改成功！"),QMessageBox::Ok);
    }
    else{
        qDebug()<<"dialog:"<<"failed:no id";
        QMessageBox::warning(this,tr("提示"),tr("成员不存在！"),QMessageBox::Ok);
    }
}
