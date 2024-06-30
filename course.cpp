#include "course.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QDebug>
#include<QLabel>
#include <vector>
using namespace std;

void Write_course(vector<Course>& cour, int n)
{
    QString fileName = "course.txt"; // 替换为你的文件路径
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "ERROR! course.exe can't open!";
        abort();
    }
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_15); // 设置版本以保证兼容性
    qDebug()<<"write "<<n;
    out << n; // 写入学生数量

    for (int i = 0; i < n; ++i) {
        out.writeRawData(cour[i].id,sizeof(cour[i].id));
        out.writeRawData(cour[i].name,sizeof(cour[i].name));
        out<<cour[i].nature;
        out<<cour[i].hour;
        out<<cour[i].credir;
        out<<cour[i].count;
    }

    file.close();/*
    fstream myfile;
    myfile.open("course.txt", ios::out | ios::binary);
    if (!myfile)
    {
        cout << "ERROR!course.txt can't open." << endl;
        abort();
    }

    myfile << n << endl << endl;
    for (int i = 0; i < n; i++)
    {
        myfile << cour[i].id << "\t" << cour[i].name << "\t"
               << cour[i].nature << "\t" << cour[i].hour << "\t"
               << cour[i].credir << "\t" << cour[i].count << endl;
    }
    myfile.close();*/

}

int Read_course(vector<Course>& cour)
{
    cour.clear();
    QString fileName = "course.txt"; // 替换为你的文件路径
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        cout<<"cant open file!"<<endl;
        qDebug() << "ERROR! Unable to open file:" << fileName;
        return -1;
    }
    qDebug()<<"able to open file";
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_15); // 设置数据流版本

    int n;
    in >> n; // 读取学生数量
    if(n>1000){
        n=0;
    }
    qDebug()<<"n "<<n;

    for (int i = 0; i < n; ++i)
    {
        qDebug()<<i;
        Course temp;
        in.readRawData(temp.id,sizeof(temp.id));
        in.readRawData(temp.name,sizeof(temp.name));
        in>>temp.nature;
        in>>temp.hour;
        in>>temp.credir;
        in>>temp.count;
        cour.push_back(temp);
    }
    file.close();
    return n;
}
//�γ���ɾ���
bool Input_course(vector<Course>& cour,char* _id,char* _name,bool _nat, int _h, int cre)
{
    system("cls");
    //cour.clear();
    int i=Read_course(cour);
    Course temp;
    qDebug()<<"in input\n";
    strcpy(temp.id,_id);
    int c = 0;
    while (c < i)
    {
        c++;
        if (!strcmp(temp.id, cour[i - c].id))
        {
            //cout << "ID repeat, please input again." << endl;
            return false;
        }
    }

    //cout << "name: ";
    strcpy(temp.name,_name);
    temp.nature=_nat;
    temp.hour=_h;
    temp.credir=cre;
    temp.count=0;
    /*cin >> temp._name;
        temp._class=clas;
        cout << "class: ";
        cin >> temp._class;*/
    qDebug()<<temp.id<<' '<<temp.name<<' '<<temp.hour<<' '<<temp.credir;
    cour.push_back(temp);// push_back
    //cout << "whether continue(y or n): ";
    //cin >> sign;
    i++;
    Write_course(cour, i);
    return true;
}

int Delete_course(vector<Course>& cour,char*id)
{
    system("cls");
    int n = Read_course(cour);
    int i = 0;
    //char id[20];
    //cout << "=============== Delete the message of course ===============" << endl;
    //cout << "please input the ID of course which you want to delete: ";
    //cin >> id;
    while (i < n && strcmp(id, cour[i].id))
        i++;

    if (i == n)
    {
        //cout << "no fount." << endl;
        //system("pause");
        qDebug()<<"no id found\n";
        return -1;
    }
    /*else
    {
        if (cour[i].count)
        {
            cout << "��ѡ������Ϊ�㣬����ϵ����ѧ���˿κ����޸Ŀγ���Ϣ��" << endl;
            system("pause");
            return;
        }
    }*/

    for (int j = i; j < n - 1; j++)
        swap(cour[j], cour[j + 1]);

    // save
    //char sign;
    //cout << "whether delete(y or n): ";
    //cin >> sign;
    //if (sign != 'n' && sign != 'N')
    //{
    cour.erase(cour.end() - 1);
    Write_course(cour, n - 1);
    //cout << "=============== Delete succeed ===============" << endl;
    qDebug()<<"Delete succeed\n";
    return 1;
    //}
}

int Modify_course(vector<Course>& cour,char* id,char* name,bool nat, int h, int cre)
{
    system("cls");
    int n = Read_course(cour);                      // count of course
    //char id[20];
    int i = 0;

    //cout << "=============== Modify course ===============" << endl;
    //cout << "input the ID of course you want to modify: ";
    //cin >> id;
    while ( i < n && strcmp(id, cour[i].id))        // i < n Ҫ��ǰ�ж�
        i++;

    if (i == n)
    {
        //cout << "no found." << endl;
        //system("pause");
        qDebug()<<"no id found\n";
        return -1;
    }
    /*
    else
    {
        if (cour[i].count)
        {
            cout << "��ѡ������Ϊ�㣬����ϵ����ѧ���˿κ����޸Ŀγ���Ϣ��" << endl;
            system("pause");
            return;
        }
    }

    cout << "----------------------------------------------------" << endl;
    cout << "ID" << "\t" << "name" << "\t" << "nature" << "\t"
         << "hour" << "\t" << "credir" << "\t" << "count" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << cour[i].id << "\t" << cour[i].name << "\t" << cour[i].nature << "\t"
         << cour[i].hour << "\t" << cour[i].credir << "\t" << cour[i].count << endl;

    cout << "please reenter the message of course." << endl;
    cout << "name of course: ";
    cin >> cour[i].name;
    cout << "elective or compulsory(0 or 1): ";
    cin >> cour[i].nature;
    cout << "class hour: ";
    cin >> cour[i].hour;
    cout << "credir: ";
    cin >> cour[i].credir;
    */
    // save
    /*
    char sign;
    cout << "whether save the data(y or n): ";
    cin >> sign;
    if (sign != 'n' && sign != 'N')
    {
*/
    if(cour[i].nature==nat&&cour[i].hour==h&&cour[i].credir==cre&&!(strcmp(cour[i].name,name))){
        qDebug()<<"no change\n";
        return 0;
    }
    cour[i].nature=nat;
    cour[i].hour=h;
    cour[i].credir=cre;
    strcpy(cour[i].name,name);
    Write_course(cour, n);
    return 1;
        /*cout << "=============== Modify succeed ===============" << endl;
        system("pause");
    }
*/
}

int Lookup_course_id(vector<Course>& cour,char* id)
{
    system("cls");
    int n = Read_course(cour);
    int i = 0;
    /*cout << "=============== Lookup the course ===============" << endl;
    cout << "please input the course ID you want to seek: ";
    cin >> id;*/

    while (i < n && strcmp(id, cour[i].id))
        i++;

    if (i == n)
    {
        return -1;
    }
    else
    {
        string info="              ----------lookup course information----------      "+string("")+"\n"+"\n"+"\n"+
                "           course id: "+string(cour[i].id)+"\n"+
                "           course name: "+string(cour[i].name)+"\n";
        if(cour[i].nature==1) info+="           course nature: compulsory\n";
        else info+=string("course nature: elective\n");
        char weekday[2];
        weekday[0]=cour[i].hour/10+'0';
        char num[2];
        num[0]=cour[i].hour%10+'0';
        num[1]='\0';
        char credit[2];
        credit[0]=cour[i].credir+'0';
        credit[1]='\0';
        info+="           time: "+string("")+"周"+string(weekday)+" 第"+string(num)+"节 \n"+
            "           credit: "+string(credit)+"学分";
        QLabel* namelabel=new QLabel(NULL);
        namelabel->setText(QString::fromStdString(info));
        namelabel->setFont(QFont("仿宋", 14));
        namelabel->setGeometry(300,300,700,300);
        namelabel->setWindowFlags(Qt::WindowStaysOnTopHint);
        namelabel->show();
        /*
        cout << "---------------------------------------------" << endl;
        cout << "ID: " << cour[i].id << endl;
        cout << "name: " << cour[i].name << endl;
        cout << "nature: " << (cour[i].nature ? "compulsory" : "elective") << endl;
        cout << "class hour: " << cour[i].hour << endl;
        cout << "credir: " << cour[i].credir << endl;
        cout << "student count: " << cour[i].count << endl;*/
    }
    return i;
}
int Lookup_course_name(vector<Course>& cour,char* name){
    system("cls");
    int n = Read_course(cour);
    int i = 0;
    /*cout << "=============== Lookup the course ===============" << endl;
    cout << "please input the course ID you want to seek: ";
    cin >> id;*/

    while (i < n && strcmp(name, cour[i].name))
        i++;

    if (i == n)
    {
        return -1;
    }
    else
    {
        string info="              ----------lookup course information----------      "+string("")+"\n"+"\n"+"\n"+
                      "           course id: "+string(cour[i].id)+"\n"+
                      "           course name: "+string(cour[i].name)+"\n";
        if(cour[i].nature==1) info+="           course nature: compulsory\n";
        else info+=string("course nature: elective\n");
        char weekday[2];
        weekday[0]=cour[i].hour/10+'0';
        char num[2];
        num[0]=cour[i].hour%10+'0';
        num[1]='\0';
        char credit[2];
        credit[0]=cour[i].credir+'0';
        credit[1]='\0';
        info+="           time: "+string("")+"周"+string(weekday)+" 第"+string(num)+"节 \n"+
                "           credit: "+string(credit)+"学分";
        QLabel* namelabel=new QLabel(NULL);
        namelabel->setText(QString::fromStdString(info));
        namelabel->setFont(QFont("仿宋", 14));
        namelabel->setGeometry(300,300,700,300);
        namelabel->setWindowFlags(Qt::WindowStaysOnTopHint);
        namelabel->show();
        /*
        cout << "---------------------------------------------" << endl;
        cout << "ID: " << cour[i].id << endl;
        cout << "name: " << cour[i].name << endl;
        cout << "nature: " << (cour[i].nature ? "compulsory" : "elective") << endl;
        cout << "class hour: " << cour[i].hour << endl;
        cout << "credir: " << cour[i].credir << endl;
        cout << "student count: " << cour[i].count << endl;*/
    }
    return i;
}
void Show_course(vector<Course>& cour)
{
    system("cls");
    int n = Read_course(cour);

    cout << "================ display all course ================" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "ID" << "\t" << "name" << "\t" << "nature" << "\t"
         << "hour" << "\t" << "credir" << "\t" << "count" << endl;

    cout << "----------------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << cour[i].id << "\t" << cour[i].name << "\t" << cour[i].nature << "\t" << cour[i].hour << "\t" << cour[i].credir << "\t" << cour[i].count << endl;
    }
    system("pause");
}

void Add_course(vector<Course>& cour)
{
    system("cls");
    int n = Read_course(cour);
    char sign = '0';
    Course temp;

    cout << "=============== add course ===============" << endl;
    while (sign != 'n' && sign != 'N')
    {
    loop:
        cout << "ID: ";
        cin >> temp.id;
        int c = 0;
        while (c < n)
        {
            c++;
            if (!strcmp(temp.id, cour[n - c].id))
            {
                cout << "ID repeat, please input again." << endl;
                goto loop;
            }
        }

        cout << "name of course: ";
        cin >> temp.name;
        cout << "elective or compulsory(0 or 1): ";
        cin >> temp.nature;
        cout << "class hour: ";
        cin >> temp.hour;
        cout << "credir: ";
        cin >> temp.credir;
        temp.count = 0;

        n++;

        cour.push_back(temp);

        cout << "whether continue(y or n): ";
        cin >> sign;
    }

    // save
    Write_course(cour, n);
}
