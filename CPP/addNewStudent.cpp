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
        // cerr << "Error: Unable to open file for writing\n";
        Create_A_Box_1(1, 1, 2, 40, 14, 14, 0, "Error: Unable to open file for writing");
        return;
    }
    Student* temp = cur->student_head;
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
    Create_A_Box_1(1, 2, 2, 50, 14, 14, 0, "YOU HAVE SUCCESSFULLY IMPORTED STUDENTS TO FILE!");
    Create_A_Box_1(1, 8, 2, 12, 14, 14, 0,"RETURN BACK");
    SetColor1(15,0);
    for (int i = 1 + 1; i <= 13; ++i)
    {
        gotoXY(i, 8+1);
        std::cout << " ";
    }
    gotoXY(1 + 1, 8+1);
    std::cout << "RETURN BACK";
    ShowConsoleCursor(false);
    while (true)
    {
        if (_kbhit())
        {
            char c = _getch();
            if (c == ENTER)
            {
                break;
            }
        }
    }
    accessClass(username, year_head, cur);
    return;
}