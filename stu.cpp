#include "stu.h"
#include "student.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include <string>
#include <QCoreApplication>
#include <QFile>
#include<QLabel>
#include <QDataStream>
#include <QDebug>
#include <vector>
#include <QtCore/Qt>
using namespace std;
// ѧ�����ݵ��ļ�����
void Write_stu(vector<Student>& stuu, int n)
{
    QString fileName = "student.txt"; // 替换为你的文件路径
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        //qDebug() << "ERROR! student.exe can't open!";
        abort();
    }
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_15); // 设置版本以保证兼容性
    //qDebug()<<"write "<<n;
    out << n; // 写入学生数量

    for (int i = 0; i < n; ++i) {
        out.writeRawData(stuu[i]._id,sizeof(stuu[i]._id));
        out.writeRawData(stuu[i]._class,sizeof(stuu[i]._class));
        out.writeRawData(stuu[i]._name,sizeof(stuu[i]._name));
    }

    file.close();
    /*
    fstream myfile;
    myfile.open("student.txt", ios::out | ios::binary);
    if (!myfile)
    {
        cout << "ERROR! student.txt can't open!" << endl;
        abort();
    }

    myfile << n << endl << endl;
    for (int i = 0; i < n; i++)
    {
        myfile << stuu[i]._id << "\t" << stuu[i]._class << "\t"
               << stuu[i]._name << "\t"
               << stuu[i].cour_compulsory[0].c_id()   << "\t"
               << stuu[i].cour_compulsory[0].c_name() << "\t"
               << stuu[i].cour_compulsory[1].c_id()   << "\t"
               << stuu[i].cour_compulsory[1].c_name() << "\t"
               << stuu[i].cour_elective[0].c_id()     << "\t"
               << stuu[i].cour_elective[0].c_name()   << "\t"
               << stuu[i].num_compulsory << "\t" << stuu[i].num_elective << endl;
    }

    myfile.close();*/
}

int Read_stu(vector<Student>& stuu)
{
    qDebug()<<"in read";
    stuu.clear();
    QString fileName = "student.txt"; // 替换为你的文件路径
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        cout<<"cant open file!"<<endl;
        //qDebug() << "ERROR! Unable to open file:" << fileName;
        return -1;
    }
    //qDebug()<<"able to open file";
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_15); // 设置数据流版本

    int n;
    in >> n; // 读取学生数量
    if(n>1000){
        n=0;
    }
    qDebug()<<"read:n "<<n;

    for (int i = 0; i < n; ++i)
    {
        //qDebug()<<"i "<<i;
        Student temp;
        in.readRawData(temp._id,sizeof(temp._id));
        //qDebug()<<"id "<<temp._id;
        in.readRawData(temp._class,sizeof(temp._class));
        //qDebug()<<"class"<<temp._class;
        in.readRawData(temp._name,sizeof(temp._name));
        //qDebug()<<"name "<<temp._name;//>> temp._id >> temp._class >> temp._name;*/
        /*in >> temp.cour_compulsory[0].id >> temp.cour_compulsory[0].name;
        in >> temp.cour_compulsory[1].id >> temp.cour_compulsory[1].name;
        in >> temp.cour_elective[0].id >> temp.cour_elective[0].name;
        in >> temp.cour_elective[1].id >> temp.cour_elective[1].name;
        in >> temp.num_compulsory >> temp.num_elective;*/
        stuu.push_back(temp);
    }

    file.close();
    /*ifstream myfile;
    myfile.open("student.txt", ios::in | ios::binary);
    if (!myfile)
    {
        cout << "ERROR! student.txt can't open!" << endl;
        abort();
    }

    int n;
    myfile.seekg(0);
    myfile >> n;

    Student temp;

    for (int i = 0; i < n; i++)
    {
        myfile >> temp._id >> temp._class
            >> temp._name
            >> temp.cour_compulsory[0].id
            >> temp.cour_compulsory[0].name
            >> temp.cour_compulsory[1].id
            >> temp.cour_compulsory[1].name
            >> temp.cour_elective[0].id
            >> temp.cour_elective[0].name
            >> temp.num_compulsory >> temp.num_elective;
        stuu.push_back(temp);
    }

    myfile.close();*/
    return n;
}
//ѧ����ɾ���
bool Input_stu(vector<Student>& stuu,char* id, char* name,char* clas)
{   qDebug()<<"newid:"<<id<<"\n";
    system("cls");
    stuu.clear();
    int i=Read_stu(stuu);
    Student temp;
    //qDebug()<<"in input\n";
    //cout << "============ please input the message ============" << endl;
    //cout << "student ID: ";
    //cin >> temp._id;
    strcpy(temp._id,id);
    int c = 0;
    while (c < i)
    {
        c++;
        qDebug()<<"tmp.id:"<<temp._id<<"\n";
        qDebug()<<"stu.id"<<stu[i-c]._id<<"\n";
        if (!strcmp(temp._id, stuu[i - c]._id))
        {   qDebug()<<"same as:"<<i-c<<"\n";
            //cout << "ID repeat, please input again." << endl;
            return false;
        }
    }

    //cout << "name: ";
    strcpy(temp._name,name);
    strcpy(temp._class,clas);
    /*cin >> temp._name;
        temp._class=clas;
        cout << "class: ";
        cin >> temp._class;*/
    //qDebug()<<temp._name<<temp._class;
    stuu.push_back(temp);            // push_back
    //cout << "whether continue(y or n): ";
    //cin >> sign;
    i++;
    Write_stu(stuu, i);
    return true;
}

bool Delete_stu(vector<Student>& stuu,char* id, char* name,char* clas)
{
    system("cls");
    int n = Read_stu(stuu); //number of student
    qDebug()<<"n: "<<n;
    //int m = Read_course(cour);  // number of course
    int i = 0;
    Student tmp;
    qDebug()<<"in delete\n";
    strcpy(tmp._id,id);
    strcpy(tmp._name,name);
    strcpy(tmp._class,clas);
    qDebug()<<tmp._id<<' '<<tmp._name<<" "<<tmp._class;
    //cout << "============ delete student ============" << endl;
    //cout << "please input the ID of student who you want to delete: ";
    //cin >> id;
    qDebug()<<"start to find\n";
    while (i < n && strcmp(tmp._id,stu[i]._id))
        i++;

    if (i == n)
    {
        cout << "no this student." << endl;
        qDebug()<<"not found.\n";
        //system("pause");
        return false;
    }
    //有compulsory功能
    /*
    if (stuu[i].num_compulsory)
    {
        while (stuu[i].num_compulsory > 0)
        {
            stuu[i].num_compulsory--;

            int c = 0;
            while (c < m)
            {
                if (!strcmp(stuu[i].cour_compulsory[stuu[i].num_compulsory].id, cour[c].id))
                {
                    cour[c].count--;
                    qDebug()<<"compulsory found\n";
                    break;
                }
                c++;
            }
            qDebug()<<"compulsory not found\n";
        }
    }
    else if (stuu[i].num_elective)
    {
        while (stuu[i].num_elective > 0)
        {
            stuu[i].num_elective--;

            int c = 0;
            while (c < m)
            {
                if (!strcmp(stuu[i].cour_elective[stuu[i].num_elective].id, cour[c].id))
                {
                    cour[c].count--;
                    qDebug()<<"elective found\n";
                    break;
                }
                c++;
            }
            qDebug()<<"elective not found\n";
        }
    }
    */
    //没有compulsory功能
    /*
    if(m){
        int c=0;
        while(c<m){
            if(!strcmp(clas,cour[c].name)){
                cour[c].count--;
                qDebug()<<"course found\n";
                break;
            }
            c++;
        }
    }
*/
    if(!strcmp(clas,stuu[i]._class)){
        qDebug()<<"course found\n";
        //return true;
    }
    else{
        qDebug()<<"student not in this course\n";
        return false;
    }
    for (int j = i; j < n - 1; j++)
        swap(stuu[j], stuu[j + 1]);//把要被删除的学生挪到最后一个

    // save
    //char sign;
    //cout << "whether delete(y or n): ";
    //cin >> sign;
    //if (sign != 'n' && sign != 'N')
    //{
    stuu.erase(stuu.end() - 1);
    Write_stu(stuu, n - 1);
    //Write_course(cour, m);
    qDebug()<<"sucess";
    return true;
    //cout << "============ delete succeed ============" << endl;
    //system("pause");
    //}
}

int Modify_stu(vector<Student>& stuu,char* id, char* name,char* clas)
{
    system("cls");
    int n = Read_stu(stuu);
    int i = 0;

    //cout << "============ Modify the message of student ============" << endl;
    //cout << "please input the ID of student who you want to modify: ";
    //cin >> id;

    while (i < n && strcmp(id, stuu[i]._id))
        i++;

    if (i == n)
    {
        qDebug()<<"no id found\n";
        return -1;
        //cout << "no found." << endl;
        //system("pause");
    }

    //cout << "-------------------------------------------------------" << endl;
    //cout << "ID: " << stuu[i]._id << endl;
    //cout << "class: " << stuu[i]._class << endl;
    //cout << "name: " << stuu[i]._name << endl;
    //cout << "-------------------------------------------------------" << endl;

    //cout << "please reenter the message." << endl;
    //cout << "class: ";
    //cin >> stuu[i]._class;
    //cout << "name: ";
    //cin >> stuu[i]._name;

    // save
    //char sign;
    //cout << "whether save the data(y or n): ";
    //cin >> sign;
    if((!strcmp(stuu[i]._name,name))&&(!strcmp(stuu[i]._class,clas))){
        qDebug()<<"no change\n";
        return 0;
    }
    strcpy(stuu[i]._name,name);
    strcpy(stuu[i]._class,clas);
    //if (sign != 'n' && sign != 'N')
    //{
    qDebug()<<"modify succeed\n";
    //cout << "modify succeed." << endl;
    Write_stu(stuu, n);
    //system("pause");
    //}

    return 1;
}
int Lookup_stu(vector<Student>& stuu,char* id, bool print)
{
    system("cls");
    int n = Read_stu(stuu);
    Read_course(cour);
    int i = 0;

    while (i < n && strcmp(id, stuu[i]._id))
        i++;

    if (i == n)
    {
        //cout << "no found." << endl;
        qDebug()<<"no id found\n";
        return -1;
    }
    else{
        /*
        if(print)
        {
            cout << "ID: " << stuu[i]._id << endl;
            cout << "class: " << stuu[i]._class << endl;
            cout << "name: " << stuu[i]._name << endl;
            cout << "compulsory: " << (!strcmp(stuu[i].cour_compulsory[0].id, "None") ? "None" : stuu[i].cour_compulsory[0].c_name())
                 << " "
                 << (!strcmp(stuu[i].cour_compulsory[1].id, "None") ? "None" : stuu[i].cour_compulsory[1].c_name())
                 << endl;
            cout << "elective: "
                 << (!strcmp(stuu[i].cour_elective[0].id, "None") ? "None" : stuu[i].cour_elective[0].c_name())
                 << endl;
        }
        return i;
*/
        string info="          ----------------look up result---------------- " +string("")+ "\n"+"\n"+"\n"+
                    "           ID: "+string(stuu[i]._id)+"\n"+"           class: "+string(stuu[i]._class)+"\n"+"           name: "+string(stuu[i]._name)+"\n"
                    "           compulsory: "+string(!strcmp(stuu[i].cour_compulsory[0].id, "None") ? "None" : stuu[i].cour_compulsory[0].c_name())+"\n"+
                    "           elective: "+string(!strcmp(stuu[i].cour_elective[0].id, "None") ? "None" : stuu[i].cour_elective[0].c_name())+"\n";
        QLabel* namelabel=new QLabel(NULL);
        namelabel->setText(QString::fromStdString(info));
        namelabel->setFont(QFont("仿宋", 14));
        namelabel->setGeometry(300,300,700,300);
        namelabel->setWindowFlags(Qt::WindowStaysOnTopHint);
        namelabel->show();
        return 1;
    }
    //system("pause");
}

int Lookup_stu_name(vector<Student>& stuu,char* name, bool print){
    system("cls");
    int n = Read_stu(stuu);
    Read_course(cour);
    int i = 0;

    while (i < n && strcmp(name, stuu[i]._name))
        i++;

    if (i == n)
    {
        //cout << "no found." << endl;
        qDebug()<<"no id found\n";
        return -1;
    }
    else{
        /*
        if(print)
        {
            cout << "ID: " << stuu[i]._id << endl;
            cout << "class: " << stuu[i]._class << endl;
            cout << "name: " << stuu[i]._name << endl;
            cout << "compulsory: " << (!strcmp(stuu[i].cour_compulsory[0].id, "None") ? "None" : stuu[i].cour_compulsory[0].c_name())
                 << " "
                 << (!strcmp(stuu[i].cour_compulsory[1].id, "None") ? "None" : stuu[i].cour_compulsory[1].c_name())
                 << endl;
            cout << "elective: "
                 << (!strcmp(stuu[i].cour_elective[0].id, "None") ? "None" : stuu[i].cour_elective[0].c_name())
                 << endl;
        }
        return i;
*/
        string info="          ----------------look up result---------------- " +string("")+ "\n"+"\n"+"\n"+
                    "           ID: "+string(stuu[i]._id)+"\n"+"           class: "+string(stuu[i]._class)+"\n"+"           name: "+string(stuu[i]._name)+"\n"
                    "           compulsory: "+string(!strcmp(stuu[i].cour_compulsory[0].id, "None") ? "None" : stuu[i].cour_compulsory[0].c_name())+"\n"+
                    "           elective: "+string(!strcmp(stuu[i].cour_elective[0].id, "None") ? "None" : stuu[i].cour_elective[0].c_name())+"\n";
        QLabel* namelabel=new QLabel(NULL);
        namelabel->setText(QString::fromStdString(info));
        namelabel->setFont(QFont("仿宋", 14));
        namelabel->setGeometry(300,300,700,300);
        namelabel->setWindowFlags(Qt::WindowStaysOnTopHint);
        namelabel->show();
        return 1;
    }
    //system("pause");
}
void Add_stu(vector<Student>& stuu)
{
    system("cls");
    int n = Read_stu(stuu);
    char sign = '0';
    Student temp;

    cout << "============ add student ============" << endl;
    while (sign != 'n' && sign != 'N')
    {
    loop:
        cout << "student ID: ";
        cin >> temp._id;

        int c = 0;
        while (c < n)
        {
            c++;
            if (!strcmp(temp._id, stuu[n - c]._id))
            {
                cout << "ID repeat, please input again." << endl;
                goto loop;
            }
        }

        cout << "class: ";
        cin >> temp._class;
        cout << "name: ";
        cin >> temp._name;
        n++;

        stuu.push_back(temp);                    // push_back

        cout << "whether continue(y or n): ";
        cin >> sign;
    }

    // save
    Write_stu(stuu, n);
}

void Show_stu(vector<Student>& stuu)
{
    system("cls");
    int n = Read_stu(stuu);

    cout << "============================ diplay all student ==========================" << endl;
    cout << "ID" << "\t" << "class" << "\t" << "name" << "\t"
         << "compulsory" << "\t\t" << "elective" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << stuu[i]._id << "\t" << stuu[i]._class << "\t" << stuu[i]._name << "\t"
             << (!strcmp(stuu[i].cour_compulsory[0].id, "None") ? "None" : stuu[i].cour_compulsory[0].name)
             << " "
             << (!strcmp(stuu[i].cour_compulsory[1].id, "None") ? "None" : stuu[i].cour_compulsory[1].c_name())
             << "\t"
             << (!strcmp(stuu[i].cour_elective[0].id, "None") ? "None" : stuu[i].cour_elective[0].c_name())
             << endl;
    }

    system("pause");
}

