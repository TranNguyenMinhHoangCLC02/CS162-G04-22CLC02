#include "../Header/Staff.h"

void uploadStudentFileToCourse (string username, Year* year_head, Semester* semester_head, Course* course_head)
{
    cout << "(You can input 0 for returning back)" << "\n\n";

    string file_name;
    cin.ignore();
    cout << "Name of file for uploading: ";
    getline(cin, file_name);

    if (file_name == "0")
    {
        system("cls");
        accessCourse(username, year_head, semester_head, course_head);
        return;
    }

    ifstream ifs;

    //Open file
    ifs.open (file_name);
    while (!ifs.is_open())
    {
        system("cls");
        cerr << "Error: Unable to open file for reading. Try to input again!\n\n";

        cout << "Name of file for uploading: ";
        getline(cin, file_name);

        if (file_name == "0")
        {
            system("cls");
            accessCourse(username, year_head, semester_head, course_head);
            return;
        }
    }

    Student* temp = nullptr;
    string line;
    getline(ifs, line);

    while (getline(ifs, line))
    {
        Student* new_student = new Student;
        string tmp;
        stringstream ss(line);

        getline(ss, tmp, ',');
        new_student->student_ID = tmp;
        getline(ss, tmp, ',');
        new_student->student_socialID = tmp; 
        getline(ss, tmp, ','); 
        new_student->student_fisrtname = tmp;
        getline(ss, tmp, ',');
        new_student->student_lastname = tmp;
        getline(ss, tmp, ',');
        new_student->student_class.class_name = tmp;
        getline(ss, tmp, ',');
        new_student->gender = stoi(tmp);
        getline(ss, tmp, '\n');
        getDate(new_student, tmp);
        
        new_student->course_head = nullptr;
        new_student->student_next = nullptr;

        if (!year_head->semester_head->course_head->student_head)
        {
            year_head->semester_head->course_head->student_head = new_student;
            temp = year_head->semester_head->course_head->student_head;
        }
        else
        {
            temp->student_next = new_student;
            temp = temp->student_next;
        }
    }

    //Close file
    ifs.close();

    //Require user input 0 for returning back
    string option;
    cout << "\n" << "You uploaded successfully, please input 0 for returning back: ";
    getline(cin, option);

    while (option != "0")
    {
        cout << "The number is different from 0, please input again: ";
        getline(cin, option);
    }

    accessCourse(username, year_head, semester_head, course_head);
}