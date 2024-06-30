#include "inputstudialog.h"
#include "ui_inputstudialog.h"
#include "qmessagebox.h"
#include "stu.h"

InputStuDialog::InputStuDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InputStuDialog)
{
    ui->setupUi(this);
}

InputStuDialog::~InputStuDialog()
{
    delete ui;
}

void InputStuDialog::on_pushButton_clicked()
{
    char* inid;
    char* name;
    char* clas;
    QString inname=ui->namelineEdit->text();
    QByteArray baa=inname.toLatin1();
    name=baa.data();
    QString id=ui->idlineEdit->text();
    QByteArray ba=id.toLatin1();
    inid=ba.data();
    QString inclas=ui->classlineEdit->text();
    QByteArray baaa=inclas.toLatin1();
    clas=baaa.data();
    qDebug()<<"name:"<<name<<"\n"<<"id:"<<inid<<"\n"<<"clas:"<<clas<<"\n";
    extern vector<Student> stu;
    if(Input_stu(stu,inid,name,clas)){
        QMessageBox::information(this,tr("通知"),tr("成功！"),QMessageBox::Ok);
    }
    else{
        QMessageBox::warning(this,tr("警告"),tr("已存在学号！"),QMessageBox::Ok);
    }
}

