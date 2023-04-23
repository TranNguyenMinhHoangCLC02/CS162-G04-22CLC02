#include "../Header/Staff.h"
#include "../Header/Design.h"

Student *getStudentCourseFromFile(string username, Year* &year_head, Semester* &semester_head, Course* &course_head){
    ifstream ifs;
    //convert semester_head->Semester_Ord to string
    char ch_semester = static_cast<char>(semester_head->Semester_Ord + 48);
    string filename = "../Txt_Csv/" + course_head->course_ID + "_Semester" + ch_semester + "_" + year_head->year_name  + ".csv";
    ifs.open(filename);
    if (!ifs.is_open())
    {
        cerr << "ERROR: UNABLE TO OPEN FILE FOR READING\n";
        return nullptr;
    }
    course_head->student_head = nullptr;
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

        addTail(course_head->student_head, new_student);
    }

    ifs.close();
    return course_head->student_head;
}