/*#include "menu.h"
#include "stu.h"
#include "student.h"
#include<iostream>
using namespace std;
#include<string.h>
//��¼
int flag=0;
int choose_user()
{
loop:
    system("cls");
    int c = 0;
    cout << "=================================================================" << endl;
    cout << "-------------- welcome to course selection system ---------------" << endl;
    cout << "please choose your identity, admin or student(1 or 2)(input 0 to exit): ";
    cin >> c;

    char passwd[20];
    if (c == 1)
    {
        cout << "please input password: ";
        cin >> passwd;
        if (!strcmp(passwd, "123456"))
        {
            flag = 1;
            cout << "log on succeed." << endl;
            system("pause");
        }
        else
        {
            cout << "password error." << endl;
            system("pause");
            goto loop;
        }
    }
    else
        flag = 0;

    if (c < 0 || c > 2)
    {
        cout << "please input 0-2." << endl;
        system("pause");
        goto loop;
    }

    return c;
}

void menu_course()
{
    int c = 0;
    while (1)
    {
        system("cls");
        cout << "============ menu of course ============" << endl;
        cout << "               1. input                 " << endl;
        cout << "               2. delete                " << endl;
        cout << "               3. modify                " << endl;
        cout << "               4. lookup                " << endl;
        cout << "               5. add                   " << endl;
        cout << "               6. show all              " << endl;
        cout << "               0. return                " << endl;
        cout << "----------------------------------------" << endl;
        cout << "please choose your operation(0-6): ";
        cin >> c;
        switch (c)
        {
        case 1:
            if (flag)
                Input_course(cour);
            else
            {
                cout << "request denied." << endl;
                system("pause");
            }
            break;
        case 2:
            if (flag)
                Delete_course(cour);
            else
            {
                cout << "request denied." << endl;
                system("pause");
            }
            break;
        case 3:
            if (flag)
                Modify_course(cour);
            else
            {
                cout << "request denied." << endl;
                system("pause");
            }
            break;
        case 4:
            Lookup_course(cour);
            break;
        case 5:
            if (flag)
                Add_course(cour);
            else
            {
                cout << "request denied." << endl;
                system("pause");
            }
            break;
        case 6:
            Show_course(cour);
            break;
        case 0:
            cout << "------------ return succeed ------------" << endl;
            system("pause");
            return;
        default:
            cout << "please input 0-6." << endl;
            system("pause");
            break;
        }
    }
}

void menu_student()
{
    int c = 0;
    while (1)
    {
        system("cls");
        cout << "============ menu of student ============" << endl;
        cout << "               1. input                 " << endl;
        cout << "               2. delete                " << endl;
        cout << "               3. modify                " << endl;
        cout << "               4. lookup                " << endl;
        cout << "               5. add                   " << endl;
        cout << "               6. show all              " << endl;
        cout << "               7. select course         " << endl;
        cout << "               8. deselect              " << endl;
        cout << "               0. return                " << endl;
        cout << "----------------------------------------" << endl;
        cout << "please choose your operation(0-6): ";
        cin >> c;
        switch (c)
        {
        case 1:
            if (flag)
                Input_stu(stu);
            else
            {
                cout << "request denied." << endl;
                system("pause");
            }
            break;
        case 2:
            if (flag)
                Delete_stu(stu);
            else
            {
                cout << "request denied." << endl;
                system("pause");
            }
            break;
        case 3:
            if (flag)
                Modify_stu(stu);
            else
            {
                cout << "request denied." << endl;
                system("pause");
            }
            break;
        case 4:
            char id[3]={'2','3'};};
            Lookup_stu(stu,id,false);
            break;

        case 5:
            if (flag)
                Add_stu(stu);
            else
            {
                cout << "request denied." << endl;
                system("pause");
            }
            break;
        case 6:
            Show_stu(stu);
            break;
        case 7:
            Select(cour, stu);
            break;
        case 8:
            Deselect(cour, stu);
            break;
        case 0:
            cout << "------------ return succeed ------------" << endl;
            system("pause");
            return;
        default:
            cout << "please input 0-6." << endl;
            system("pause");
            break;
        }
    }
}

int menu_main()
{
    int c = 0;
    while (1)
    {
        system("cls");
        cout << "====================================================" << endl;
        cout << "               1. course message                    " << endl;
        cout << "               2. student message                   " << endl;
        cout << "               0. go back to higher-level menu       " << endl;
        cout << "choose your operation: ";
        cin >> c;

        if (c < 0 || c > 2)
        {
            cout << "please input 0-2." << endl;
            system("pause");
        }
        else
            break;
    }

    return c;
}


int main()
{
    cour.reserve(100);
    stu.reserve(100);
    while (1)
    {
    loop:
        if (!choose_user())
        {
            cout << "=============== thank you for using ===============" << endl;
            return 0;
        }
        while (1)
        {
            switch (menu_main())
            {
            case 1:
                menu_course();
                break;
            case 2:
                menu_student();
                break;
            case 0:
                cout << "=============== return scceed ===============" << endl;
                system("pause");
                goto loop;
            default:
                cout << "please input 0-2." << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
*/
