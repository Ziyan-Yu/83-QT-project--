#ifndef STUDENT_H
#define STUDENT_H
#include<vector>
using namespace std;
#include "course.h"

class Student//ѧ��
{
public:
    Student(){}
    friend bool Input_stu(vector<Student>& stuu,char* id, char* name,char* clas);
    //friend void Input_stu(vector<Student>& stu);//����
    friend bool Delete_stu(vector<Student>& stu,char* id, char* name,char* clas);//ɾ��
    friend int Modify_stu(vector<Student>& stu,char* id, char* name,char* clas);
    friend int Lookup_stu(vector<Student>& stuu,char* id,bool print);
    friend int Lookup_stu_name(vector<Student>& stuu,char* name,bool print);
    friend void Add_stu(vector<Student>& stu);
    friend void Show_stu(vector<Student>& stu);
    friend int Read_stu(vector<Student>& stu);
    friend void Write_stu(vector<Student>& stu, int n);
    //ͬ��
    friend void Select(vector<Course>& cour, vector<Student>& stu);//��ѡ
    friend void Deselect(vector<Course>& cour, vector<Student>& stu);//ѡ��


    //ѧ�š��༶����������ѡ��ı��޿���Ϣ����ѡ��ѡ�޿���Ϣ����ѡ���޿���������ѡѡ�޿�����
    char _id[20];
    char _class[20];
    char _name[20];

    int num_compulsory = 0;
    int num_elective = 0;
    Course cour_compulsory[100];//���޿�
    Course cour_elective[];//ѡ��
};

extern vector<Course> cour;
extern vector<Student> stu;
//�������ӵ���ģ��
//�Ժ�����ʽ����
//û�����ô�趨
#endif // STUDENT_H
