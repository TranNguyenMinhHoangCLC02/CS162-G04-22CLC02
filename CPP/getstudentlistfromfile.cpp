#include "../Header/Staff.h"

Student* getStudentListFromFile(Year *year_head)
{
    ifstream ifs;
    ifs.open("../Txt_Csv/student_info.csv");
    if (!ifs.is_open())
    {
        cerr << "Error: Unable to open file for reading\n";
        return nullptr;
    }
    year_head->class_head->student_head = nullptr;
    Student* temp = nullptr;
    string dummy;
    getline(ifs, dummy);
    string first_name, last_name, student_class, student_ID, social_ID, DOB, gender;
    while (!ifs.eof())
    {
        if (ifs.eof())
            break;
        
        Student* new_student = new Student;
        getline(ifs, student_ID, ',');
        new_student->student_ID = student_ID;
        getline(ifs, social_ID, ',');
        new_student->student_socialID = social_ID;
        getline(ifs, first_name, ',');
        new_student->student_fisrtname = first_name;
        getline(ifs, last_name, ',');
        new_student->student_lastname = last_name;
        getline(ifs, gender, ',');
        new_student->gender=stoi(gender);
        getline(ifs, student_class, ',');
        new_student->student_class.class_name = student_class;
        getline(ifs, DOB, '\n');
        getDate(new_student, DOB);
        new_student->course_head = nullptr;
        new_student->student_next = nullptr;

        // if (!year_head->class_head->student_head)
        // {
        //     year_head->class_head->student_head = new_student;
        //     temp = year_head->class_head->student_head;
        // }
        // else
        // {
        //     temp->student_next = new_student;
        //     temp = temp->student_next;
        // }
        addTail(year_head->class_head->student_head, new_student);
    }

    ifs.close();
    return year_head->class_head->student_head;
}