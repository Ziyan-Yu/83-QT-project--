#include "stufuncdialog.h"
#include "ui_stufuncdialog.h"
#include "student.h"
#include "qmessagebox.h"
#include "stu.h"
#include "string.h"

StuFuncDialog::StuFuncDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StuFuncDialog)
{
    ui->setupUi(this);
}

StuFuncDialog::~StuFuncDialog()
{
    delete ui;
}
void StuFuncDialog::on_idssButton_clicked()
{
    //找这个课程的序号
    char* inid;
    QString id=ui->idsslineEdit->text();
    QByteArray ba=id.toLatin1();
    inid=ba.data();
    extern vector<Course> cour;
    int i=Lookup_course_id(cour,inid);
    if(i>=0){
        //找到了
        //输出课程
        QDialog* courseselectwidget= new QDialog(this);
        courseselectwidget->setFixedSize(640,320);
        string info=string(cour[i].id)+string(" ")+string(cour[i].name)+string(" ");
        if(cour[i].nature==1) info+=string("compulsory ");
        else info+=string("elective ");
        char weekday[2];
        weekday[0]=cour[i].hour/10+'0';
        weekday[1]='\0';
        char num[2];
        num[0]=cour[i].hour%10+'0';
        num[1]='\0';
        char credit[2];
        credit[0]=cour[i].credir+'0';
        credit[1]='\0';
        info+=(string("周")+string(weekday)+" 第"+string(num)+"节 "+string(credit)+"学分");
        QLabel* namelabel=new QLabel(courseselectwidget);
        namelabel->setText(QString::fromStdString(info));
        courseselectwidget->show();
        namelabel->setGeometry(30,20,500,30);
        namelabel->show();
        //找学生序号
        char* stuid;
        QString idd=ui->stuidlineEdit->text();
        QByteArray baa=idd.toLatin1();
        stuid=baa.data();
        extern vector<Student> stu;
        int j=Lookup_stu(stu,stuid,false);
        //看看学生选这个课了吗
        bool hasselected=false;
        for(int k=0;k<stu[j].num_compulsory;j++)
        {
            if(strcmp(stu[j].cour_compulsory[k].id,inid)==0){
                hasselected=true;
            }
        }
        for(int k=0;k<stu[j].num_elective;j++)
        {
            if(strcmp(stu[j].cour_elective[k].id,inid)==0){
                hasselected=true;
            }
        }
        if(hasselected==true){
            QLabel* hassel=new QLabel(courseselectwidget);
            hassel->setText("已选√");
            hassel->show();
        }
        else{
            QPushButton* selectbutton=new QPushButton(courseselectwidget);
            selectbutton->setText("选择");
            selectbutton->setGeometry(500,60,50,30);
            selectbutton->show();
            QLineEdit* note=new QLineEdit(courseselectwidget);
            note->setText("输入小纸条");
            note->setGeometry(250,60,200,30);
            note->show();
        }



        /*    int num_compulsory = 0;
                int num_elective = 0;
        Course cour_compulsory[100];//���޿�
        Course cour_elective[];//ѡ��*/
    }
    else{
        //没找着
        QMessageBox::warning(this,tr("警告"),tr("不存在该序号课程！"),QMessageBox::Ok);
    }
}
void StuFuncDialog::select(){
    qDebug()<<"inhere";
    QMessageBox::information(this,tr("通知"),tr("选课成功"),QMessageBox::Ok);
}


