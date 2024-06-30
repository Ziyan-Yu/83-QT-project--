#include "select.h"
#include "stu.h"
#include "student.h"
#include "course.h"
#include<iostream>
using namespace std;
#include<string.h>
//ѡ��
void Select(vector<Course>& cour, vector<Student>& stu)
{
    system("cls");
    int n_cour = Read_course(cour);
    int n_stu = Read_stu(stu);
    int i = 0;              // student
    int j = 0;              // course

    char id_c[20];          // course
    char id_s[20];          // student
    cout << "============ select system ============" << endl;
    cout << "please input the ID of student: ";
    cin >> id_s;
    while ( i < n_stu && strcmp(stu[i]._id, id_s))
        i++;

    if (i == n_stu)
    {
        cout << "no found." << endl;
        system("pause");
        return;
    }

    cout << ("please input the ID of course you want to select: ");
    cin >> id_c;
    while ( j < n_cour && strcmp(cour[j].c_id(), id_c))
        j++;


    if (j == n_cour)
    {
        cout << "no found." << endl;
        system("pause");
        return;
    }

/*    if(j != n_cour&&j == cour_elective)
    {
        int paper=0;
        cin>>paper;
    }*/

    if (cour[j].count >= 60)
    {
        cout << "student number full, select failed." << endl;
        system("pause");
    }
    else
    {
        if (cour[j].c_nature())
            if (stu[i].num_compulsory < 2)
            {
                int c = 0;
                while (c < stu[i].num_compulsory && strcmp(cour[j].id, stu[i].cour_compulsory[c].id))
                    c++;

                if (c < stu[i].num_compulsory)
                {
                    cout << "course repeat." << endl;
                    system("pause");
                    return;
                }
                stu[i].cour_compulsory[stu[i].num_compulsory] = cour[j];
                stu[i].num_compulsory++;
                cour[j].count++;
                Write_course(cour, n_cour);
                Write_stu(stu, n_stu);
                cout << "select succeed." << endl;
                system("pause");
            }
            else
            {
                cout << "class number upper limit, select failed." << endl;
                system("pause");
            }
        else
        {
            if (stu[i].num_elective < 1)
            {
                int c = 0;
                while (c < stu[i].num_elective && strcmp(cour[j].id, stu[i].cour_elective[c].id))
                    c++;

                if (c < stu[i].num_elective)
                {
                    cout << "course repeat." << endl;
                    system("pause");
                    return;
                }

                stu[i].cour_elective[stu[i].num_elective] = cour[j];
                stu[i].num_elective++;
                cour[j].count++;
                Write_course(cour, n_cour);
                Write_stu(stu, n_stu);
                cout << "select succeed." << endl;
                system("pause");
            }
            else
            {
                cout << "class number upper limit, select failed." << endl;
                system("pause");
            }
        }
    }
}


