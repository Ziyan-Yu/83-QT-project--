#ifndef COURSE_H
#define COURSE_H
#include <vector>

using namespace std;

class Course //�γ�
{
public:
    friend bool Input_course(vector<Course>& cour,char* _id,char* _name,bool _nat, int _h, int cre);
    //friend void Input_course(vector<Course>& cour);//�ӿ�
    friend int Delete_course(vector<Course>& cour,char*id);//ɾ��
    friend int Modify_course(vector<Course>& cour,char* _id,char* _name,bool _nat, int _h, int cre);
    friend int Lookup_course_id(vector<Course>& cour,char* id);
    friend int Lookup_course_name(vector<Course>& cour,char* name);
    friend void Show_course(vector<Course>& cour);
    friend void Add_course(vector<Course>& cour);
    //���
    friend int Read_course(vector<Course>& cour);//��ȡ
    friend void Write_course(vector<Course>& cour, int n);//¼��

    friend void Paper_course(vector<Course>& cour,int n);

    const char* c_id() { return id; }
    const char* c_name() { return name; }
    /*const*/ bool c_nature() { return nature; }

    Course():id("None"),name("None"),count(0){}//��ʼ��


    //�γ̱�š��γ������γ����ͣ�ѡ��/���ޣ���ѧʱ��ѧ�֡��Լ�ѡ������
    char id[20];
    char name[20];
    bool nature;//ͨ��0��1�жϱ�����ѡ��
    int hour;
    int credir;
public:
    int count;
};

#endif // COURSE_H
