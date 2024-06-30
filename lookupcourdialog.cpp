#include "lookupcourdialog.h"
#include "ui_lookupcourdialog.h"
#include "course.h"
#include "student.h"
#include "qmessagebox.h"

lookupcourDialog::lookupcourDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::lookupcourDialog)
{
    ui->setupUi(this);
}

lookupcourDialog::~lookupcourDialog()
{
    delete ui;
}

/*void lookupcourDialog::on_idspushButton_clicked()
{

}


void lookupcourDialog::on_namespushButton_clicked()
{

}
*/

void lookupcourDialog::on_idbutton_clicked()
{
    char* inid;
    QString id=ui->idline->text();
    QByteArray ba=id.toLatin1();
    inid=ba.data();
    extern vector<Course> cour;
    if(Lookup_course_id(cour,inid)){

    }
    else{
        QMessageBox::warning(this,tr("警告"),tr("不存在该序号课程！"),QMessageBox::Ok);
    }
}


void lookupcourDialog::on_namebutton_clicked()
{
    char* name;
    QString inname=ui->courline->text();
    QByteArray ba=inname.toLatin1();
    name=ba.data();
    extern vector<Course> cour;
    qDebug()<<"name:"<<name<<"\n";
    int ans=Lookup_course_name(cour,name);
    qDebug()<<"ans:"<<ans<<"\n";
    if(ans==-1){
        QMessageBox::warning(this,tr("警告"),tr("不存在该序号课程！"),QMessageBox::Ok);
    }
    else{

    }
}

