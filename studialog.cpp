#include "studialog.h"
#include "ui_studialog.h"
#include "qinputdialog.h"
#include "qmessagebox.h"
#include "stufuncdialog.h"
#include "stu.h"

StuDialog::StuDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StuDialog)
{
    ui->setupUi(this);
}

StuDialog::~StuDialog()
{
    delete ui;
}

void StuDialog::on_pushButton_clicked()
{
    QString inputid= QInputDialog::getText(this,tr("学生登录"),tr("请输入学号"),QLineEdit::Normal,tr("admin"));
    char* inid;
    QByteArray ba = inputid.toLatin1();
    inid=ba.data();
    //vector<Student> stuvec;
    if(Lookup_stu(stu,inid,false)){
        StuFuncDialog* stufuncdialog=new StuFuncDialog(this);
        stufuncdialog->show();
    }
    else{
        int ret=QMessageBox::warning(this,tr("警告"),tr("学号不存在！"),QMessageBox::Ok);

    }
}

