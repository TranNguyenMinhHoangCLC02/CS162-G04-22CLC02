#include "../Header/Staff.h"

Student* getStudentListFromFile(Year *year_head, Class* class_head)
{
    ifstream ifs;
    ifs.open("../Txt_Csv/student_info.csv");
    if (!ifs.is_open())
    {
        // cerr << "Error: Unable to open file for reading\n";
        return nullptr;
    }
    class_head->student_head = nullptr;
    Student* temp = nullptr;
    string dummy;
    getline(ifs, dummy);
    
    string line;
    while (getline(ifs, line))
    {
        string tmp;
        stringstream ss(line);

        Student* new_student = new Student;
        getline(ss, tmp, ',');
        new_student->student_ID = tmp;
        getline(ss, tmp, ',');
        new_student->student_socialID = tmp;
        getline(ss, tmp, ',');
        new_student->student_fisrtname = tmp;
        getline(ss, tmp, ',');
        new_student->student_lastname = tmp;
        getline(ss, tmp, ',');
        new_student->gender = stoi(tmp);
        getline(ss, tmp, ',');
        new_student->student_class.class_name = tmp;
        getline(ss, tmp, '\n');
        getDate(new_student, tmp);
        new_student->course_head = nullptr;
        new_student->student_next = nullptr;

        if (class_head->class_name == new_student->student_class.class_name)
            addTail(class_head->student_head, new_student);
    }

    ifs.close();
    return class_head->student_head;
}