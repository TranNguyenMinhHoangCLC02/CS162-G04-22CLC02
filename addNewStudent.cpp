#include "Staff.h"
#include "Student.h"

void addNewStudent(string username, Year *&year_head, Class *cur)
{
    string filename= cur->class_name + "-" + year_head->year_name + ".txt";
    cout << filename << "\n";
    ofstream ofs;
    ofs.open(filename, ios::app);
     if (!ofs.is_open()) {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }
    Student *temp= year_head->class_head->student_head;
    while (temp!=nullptr)
    {
        if (temp->student_class.class_name==cur->class_name)
        {
            ofs << temp->student_ID << "," << temp->student_socialID << ",";
            ofs << temp->student_fisrtname << "," << temp->student_lastname << ",";
            ofs << temp->gender << "," << temp->student_class.class_name << ",";
            ofs << temp->DOB.day << "/" << temp->DOB.month << "/" << temp->DOB.year << "\n";

        }
        temp = temp->student_next;
    }

    string option;
    cout << "Please type the number 0 for returning back: ";
    cin >> option;
    cin.ignore();
    while (option != "0") 
    {
        cout << "The number is different from 0, please input again: ";
        cin >> option;
        cin.ignore();
    }
    if (option == "0") 
    {
        system ("cls");
        accessClass(username, year_head, cur);
    }
}