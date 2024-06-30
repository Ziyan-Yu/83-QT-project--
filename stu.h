#ifndef STU_H
#define STU_H
#include "student.h"

//void Input_stu(vector<Student>& stuu);//����
bool Input_stu(vector<Student>& stuu,char* id, char* name,char* clas);
bool Delete_stu(vector<Student>& stuu,char* id,char* name,char* clas);//ɾ��
int Modify_stu(vector<Student>& stuu,char* id,char* name,char* clas);
int Lookup_stu(vector<Student>& stuu,char* id,bool print);
int Lookup_stu_name(vector<Student>& stuu,char* name,bool print);
void Add_stu(vector<Student>& stuu);
void Show_stu(vector<Student>& stuu);
int Read_stu(vector<Student>& stuu);
void Write_stu(vector<Student>& stuu, int n);
//ͬ��
//void Select(vector<Course>& cour, vector<Student>& stu);//��ѡ
//void Deselect(vector<Course>& cour, vector<Student>& stu);//ѡ��

#endif // STU_H
