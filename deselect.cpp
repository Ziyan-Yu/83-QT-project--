#include "deselect.h"
#include "student.h"
#include "course.h"
#include<iostream>
using namespace std;
#include<string.h>
//��ѡ
void Deselect(vector<Course>& cour, vector<Student>& stu)
{
    system("cls");
    int n_cour = Read_course(cour);
    int n_stu = Read_stu(stu);
    int i = 0;              // student
    int j = 0;              // course

    char id_c[20];          // course
    char id_s[20];          // student
    cout << "============ deselect system ============" << endl;
    cout << "please input the ID of student: ";
    cin >> id_s;
    while (i < n_stu && strcmp(stu[i]._id, id_s))
        i++;

    if (i == n_stu)
    {
        cout << "no found." << endl;
        system("pause");
        return;
    }

    cout << ("please input the ID of course you want to deselect: ");
    cin >> id_c;
    while (j < n_cour && strcmp(cour[j].c_id(), id_c))
        j++;

    if (j == n_cour)
    {
        cout << "no found." << endl;
        system("pause");
        return;
    }

    if (stu[i].num_compulsory)
    {
        int c = stu[i].num_compulsory - 1;
        while (c >= 0)
        {
            if (!strcmp(stu[i].cour_compulsory[c].id, id_c))
            {
                cour[j].count--;
                stu[i].num_compulsory--;
                strcpy(stu[i].cour_compulsory[c].id, "None");
                strcpy(stu[i].cour_compulsory[c].name, "None");

                // ��������
                for (; c < stu[i].num_compulsory; c++)
                    swap(stu[i].cour_compulsory[c], stu[i].cour_compulsory[c + 1]);

                Write_stu(stu, n_stu);
                Write_course(cour, n_cour);
                cout << "��ѡ�ɹ���" << endl;
                system("pause");
                return;
            }
            c--;
        }

        if (stu[i].cour_elective)
        {
            int c = stu[i].num_elective - 1;
            while (c >= 0)
            {
                if (!strcmp(stu[i].cour_elective[c].id, id_c))
                {
                    cour[j].count--;
                    stu[i].num_elective--;
                    strcpy(stu[i].cour_elective[c].id, "None");
                    strcpy(stu[i].cour_elective[c].name, "None");

                    for (; c < stu[i].num_elective; c++)
                        swap(stu[i].cour_elective[c], stu[i].cour_elective[c + 1]);

                    Write_stu(stu, n_stu);
                    Write_course(cour, n_cour);
                    cout << "��ѡ�ɹ���" << endl;
                    system("pause");
                    return;
                }
                c--;
            }
            cout << "�㲢δѡ��ÿγ̡�" << endl;
            system("pause");
            return;
        }
    }

    if (stu[i].cour_elective)
    {
        int c = stu[i].num_elective - 1;
        while (c >= 0)
        {
            if (!strcmp(stu[i].cour_elective[c].id, id_c))
            {
                cour[j].count--;
                stu[i].num_elective--;
                strcpy(stu[i].cour_elective[c].id, "None");
                strcpy(stu[i].cour_elective[c].name, "None");

                for (; c < stu[i].num_elective; c++)
                    swap(stu[i].cour_elective[c], stu[i].cour_elective[c + 1]);

                Write_stu(stu, n_stu);
                Write_course(cour, n_cour);
                cout << "��ѡ�ɹ���" << endl;
                system("pause");
                return;
            }
            c--;
        }
        cout << "�㲢δѡ��ÿγ̡�" << endl;
        system("pause");
        return;
    }
}

