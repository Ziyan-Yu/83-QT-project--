#include "modifycourdialog.h"
#include "ui_modifycourdialog.h"
#include "student.h"
#include "stu.h"
#include"QMessageBox"
#include<QDebug>

modifycourdialog::modifycourdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::modifycourdialog)
{
    ui->setupUi(this);
}

modifycourdialog::~modifycourdialog()
{
    delete ui;
}

void modifycourdialog::on_pushButton_clicked()
{
    char* inid;
    char* name;
    bool nature;//ͨ��0��1�жϱ�����ѡ��
    int hour;
    int credir;
    QString inname=ui->courline->text();
    QByteArray baa=inname.toLatin1();
    name=baa.data();
    QString id=ui->idline->text();
    QByteArray ba=id.toLatin1();
    inid=ba.data();
    hour=ui->timeline->text().toInt();
    credir=ui->creditline->text().toInt();
    int nnature=ui->natureline->text().toInt();
    if(nnature==0) nature=false;
    else nature=true;
    extern vector<Course> cour;
    QMessageBox::information(this,tr("提示"),tr("确认修改信息吗？"),QMessageBox::Ok);
    int ans=Modify_course(cour,inid,name,nature,hour,credir);
    if(!ans){
        QMessageBox::warning(this,tr("警告"),tr("请确认与原信息不同"),QMessageBox::Ok);
    }
    else if(ans==-1){
        QMessageBox::warning(this,tr("警告"),tr("该课程不存在！"),QMessageBox::Ok);
    }
    else{
        QMessageBox::information(this,tr("通知"),tr("修改成功"),QMessageBox::Ok);
    }
}

