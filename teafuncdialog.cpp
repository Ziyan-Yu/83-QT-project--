#include "teafuncdialog.h"
#include "inputcourdialog.h"
#include "ui_teafuncdialog.h"
#include "inputstudialog.h"
#include "deletstudialog.h"
#include "alterstudialog.h"
#include "inputcourdialog.h"
#include "lookupstudialog.h"
#include "lookupcourdialog.h"
#include "deletecourdialog.h"
#include "modifycourdialog.h"

TeaFuncDialog::TeaFuncDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TeaFuncDialog)
{
    ui->setupUi(this);
}

TeaFuncDialog::~TeaFuncDialog()
{
    delete ui;
}

void TeaFuncDialog::on_inputstuButton_clicked()
{
    InputStuDialog* inputstudialog=new InputStuDialog(this);
    inputstudialog->show();
}


void TeaFuncDialog::on_deletestuButton_clicked()
{
    deletstudialog* Deletstudialog=new deletstudialog(this);
    Deletstudialog->show();
}

void TeaFuncDialog::on_modifystuButton_clicked()
{
    alterstudialog* Alterstudialog=new alterstudialog(this);
    Alterstudialog->show();
}


void TeaFuncDialog::on_lookupstuButton_clicked()
{
    lookupstudialog* Lookupstudialog=new lookupstudialog(this);
    Lookupstudialog->show();
}


void TeaFuncDialog::on_inputcourButton_clicked()
{
    InputCourDialog* inputcourdialog=new InputCourDialog(this);
    inputcourdialog->show();
}


void TeaFuncDialog::on_lookupcourButton_clicked()
{
    lookupcourDialog* Lookupcourdialog=new lookupcourDialog(this);
    Lookupcourdialog->show();
}


void TeaFuncDialog::on_deletecoutButton_clicked()
{
    deletecourdialog* Deletecourdialog=new deletecourdialog();
    Deletecourdialog->show();
}


void TeaFuncDialog::on_modifycourButton_clicked()
{
    modifycourdialog* Modifycourdialog=new modifycourdialog();
    Modifycourdialog->show();
}

