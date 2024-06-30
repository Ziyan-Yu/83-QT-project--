#include "inputcourdialog.h"
#include "ui_inputcourdialog.h"
#include "qmessagebox.h"
#include "student.h"
#include "course.h"
#include <iostream>
using namespace std;

InputCourDialog::InputCourDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InputCourDialog)
{
    ui->setupUi(this);
}

InputCourDialog::~InputCourDialog()
{
    delete ui;
}

void InputCourDialog::on_pushButton_clicked()
{
    qDebug()<<"in clicked";
    char* inid;
    char* name;
    bool nature;
    int hour;
    int credir;
    QString inname=ui->namelineEdit->text();
    QByteArray baa=inname.toLatin1();
    name=baa.data();
    QString id=ui->idlineEdit->text();
    QByteArray ba=id.toLatin1();
    inid=ba.data();
    hour=ui->timelineEdit->text().toInt();
    credir=ui->creditlineEdit->text().toInt();
    //qDebug()<<"id:"<<inid<<"\n"<<"name:"<<name<<"\n"<<"hour:"<<hour<<"\n"<<"credit:"<<credir<<"\n";
    int nnature=ui->typelineEdit->text().toInt();
    if(nnature==0) nature=false;
    else nature=true;
    extern vector<Course> cour;
    qDebug()<<"id:"<<inid<<"\n"<<"name"<<name<<"\n"<<"nature:"<<nature<<"\n"<<"hour:"<<hour<<"\n"<<"credit:"<<credir<<"\n";
    if(Input_course(cour,inid,name,nature,hour,credir)){
        QMessageBox::information(this,tr("通知"),tr("成功！"),QMessageBox::Ok);
    }
    else{
        QMessageBox::warning(this,tr("警告"),tr("已存在课程！"),QMessageBox::Ok);
    }
}

