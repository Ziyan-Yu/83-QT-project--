#include "teadialog.h"
#include "ui_teadialog.h"
#include "qmessagebox.h"
#include "teafuncdialog.h"
#include "qinputdialog.h"

TeaDialog::TeaDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TeaDialog)
{
    ui->setupUi(this);
}

TeaDialog::~TeaDialog()
{
    delete ui;
}

void TeaDialog::on_pushButton_clicked()
{
    int inputkey= QInputDialog::getInt(this,tr("教师认证"),tr("请输入教师密码"));
    if(inputkey==23000130){
        TeaFuncDialog* tfd=new TeaFuncDialog(this);
        tfd->show();
    }
    else{
        int ret=QMessageBox::warning(this,tr("警告"),tr("密码错误！不要假扮老师！"),QMessageBox::Ok);
    }
}

