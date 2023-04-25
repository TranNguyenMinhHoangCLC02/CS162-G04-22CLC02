#include "../Header/Student.h"
#include "../Header/Staff.h"

int numOfStudent(Course* course)
{
    int count = 0;
    Student* currrent = course->student_head;
    while (currrent != NULL)
    {
        count ++;
        currrent = currrent->student_next;
    }
    return count;
}

bool isStudentInCourse(Course* course, Student* student)
{
    Student* current = course->student_head;
    while (current != NULL)
    {
        if (current->student_ID == student->student_ID)
            return true;
        current = current->student_next;
    }
    return false;
}

Student* findStudentInClass(Class* class_head, string studentID) 
{
    while (class_head != nullptr) 
    {
        Student* student_head = class_head->student_head;
        while (student_head != nullptr) 
        {
            if (student_head->student_ID == studentID)
            {
                Student* new_student = new Student;

                new_student->student_ID = student_head->student_ID;
                new_student->student_socialID = student_head->student_socialID;
                new_student->student_fisrtname = student_head->student_fisrtname;
                new_student->student_lastname = student_head->student_lastname;
                new_student->gender = student_head->gender;
                new_student->DOB = student_head->DOB;
                new_student->student_class.class_name = student_head->student_class.class_name;
                new_student->course_head = student_head->course_head;
                new_student->student_next = nullptr;

                return new_student;
            }
            student_head = student_head->student_next;
        }
        
        class_head = class_head->next_class;
    }
    return nullptr;
}

void addCourseToStudent(Student* &student, Course* course) 
{
    if (student->course_head == nullptr) 
        student->course_head = course;
    else 
    {
        Course* current_course = student->course_head;
        while (current_course->course_next != nullptr) 
            current_course = current_course->course_next;
        current_course->course_next = course;
    }
}


void addStudentToCourse(string username, Course* &course, Year* &year_head, Semester* semester_head) 
{
    ofstream ofs;

    string studentID;
    cout << "Input ID of student that you want to add: ";
    cin >> studentID; 
    
    Student* student = findStudentInClass(year_head->class_head , studentID);

    // Check if the Course has reached maxNumStudents or not
    if (numOfStudent(course) == course->maxNumStudents)
    {
        system ("cls");
        cout << "This course has reached its maximum limit of students.";
        addStudentToCourse(username, course, year_head, semester_head);
        return;
    }

    else if (numOfStudent(course) < course->maxNumStudents)
    {
        // Check if the student is already in the course
        if (isStudentInCourse(course, student))
        {
            system ("cls");
            cout << "This student is already in the course.";
            addStudentToCourse(username, course, year_head, semester_head);
            return;
        }

        // Add the course to the student's list of courses
        addCourseToStudent(student, course);
        
        // Add the student to the course's list of students
        if (course->student_head == NULL)
            course->student_head = student;
        else 
        {
            Student* current = course->student_head;
            while (current->student_next != NULL) 
                current = current->student_next;
            current->student_next = student;
        }
    }

    // Add student infomation to file
    string file_name = course->course_ID + "_Semester" + (char)(semester_head->Semester_Ord + 48) + "_" + year_head->year_name + "_student.csv";
    file_name = "../Txt_Csv/" + file_name;
    ofs.open(file_name, ios::app);
    if (!ofs.is_open())
    {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }
    
    ofs << "\n";
    ofs << student->student_ID << "," << student->student_socialID << ",";
    ofs << student->student_fisrtname << "," << student->student_lastname << ",";
    ofs << student->gender << "," << student->student_class.class_name << ",";
    ofs << student->DOB.day << "/" << student->DOB.month << "/" << student->DOB.year;

    cout << "Student added successfully.\n\n";

    int option;
    cout << "Do you want to add another student? (1 for Yes, 0 for No): ";
    cin >> option;
    while (option != 0 && option != 1){
        cout << "Invalid input. Please enter again: ";
        cin >> option;
        cin.ignore();
    }
    if (option == 1)
    {
        system ("cls");
        addStudentToCourse(username, course, year_head, semester_head);
        return;
    }   
    else
    {
        accessCourse(username, year_head, semester_head, course);
        return;
    }

}