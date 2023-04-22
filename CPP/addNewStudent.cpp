#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"
void addNewStudent(string username, Year* &year_head, Class* cur)
{
    string filename = cur->class_name + "-" + year_head->year_name + ".txt";
    cout << filename << "\n";
    filename = "../Txt_Csv/" + filename;
    ofstream ofs;
    ofs.open(filename, ios::app);
    if (!ofs.is_open()) {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }
    Student* temp = year_head->class_head->student_head;
    while (temp != nullptr)
    {
        if (temp->student_class.class_name == cur->class_name)
        {
            ofs << temp->student_ID << "," << temp->student_socialID << ",";
            ofs << temp->student_fisrtname << "," << temp->student_lastname << ",";
            ofs << temp->gender << "," << temp->student_class.class_name << ",";
            ofs << temp->DOB.day << "/" << temp->DOB.month << "/" << temp->DOB.year << "\n";

        }
        temp = temp->student_next;
    }
    ofs.close();
    Create_A_Box_1(67,15 ,2,30,14,14,0,"          RETURN BACK");
    while (true)
    {
        if (_kbhit())
            {
                char c = _getch();
                system("color E0");
                SetColor1(15,0);
                gotoXY(68,15); 
                std::cout << "          RETURN BACK";
                if (c == 13)
                {
                    system("cls");
                    accessClass(username, year_head, cur);
                    return;
                }
            }
    }
}