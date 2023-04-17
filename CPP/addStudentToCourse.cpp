#include "../Header/Student.h"

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

Student* createStudent() 
{
    string student_ID, student_socialID, student_first, student_lastname, class_name;
    bool gender;
    Date DOB;

    cout << "Enter student ID: ";
    cin >> student_ID;

    cout << "Enter student social ID: ";
    cin >> student_socialID;

    cout << "Enter student first name: ";
    cin >> student_first;

    cout << "Enter student last name: ";
    cin >> student_lastname;

    cout << "Enter student class name: ";
    cin >> class_name;

    cout << "Enter student gender (0 for Male, 1 for Female): ";
    cin >> gender;

    cout << "Enter student date of birth (DD MM YYYY): ";
    cin >> DOB.day >> DOB.month >> DOB.year;

    // create a new student object
    Student* student = new Student;
    student->student_ID = student_ID;
    student->student_socialID = student_socialID;
    student->student_fisrtname = student_first;
    student->student_lastname = student_lastname;
    student->gender = gender;
    student->DOB = DOB;
    student->student_class.class_name = class_name;
    student->student_next = NULL;

    // return the pointer to the new student object
    return student;
}

void addStudentToCourse(string username, Course* &course, Year* &year_head, Semester* semester_head) 
{
    ofstream ofs;

    Student* student = createStudent();

    // Check if the Course has reached maxNumStudents or not
    if (numOfStudent(course) == course->maxNumStudents)
    {
        cout << "This course has reached its maximum limit of students.";
        return;
    }

    else if (numOfStudent(course) < course->maxNumStudents)
    {
        // Check if the student is already in the course
        if (isStudentInCourse(course, student))
        {
            cout << "This student is already in the course.";
            return;
        }

        // Add the course to the student's list of courses
        student->course_head = course;

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
    string file_name = course->course_ID + "_Semester" + (char)(semester_head->Semester_Ord + 48) + "_" + year_head->year_name + ".csv";
    file_name = "../Txt_Csv/" + file_name;
    ofs.open(file_name);
    if (!ofs.is_open())
    {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }

    ofs << student->student_ID << "," << student->student_socialID << ",";
    ofs << student->student_fisrtname << "," << student->student_lastname << ",";
    ofs << student->gender << "," << student->student_class.class_name << ",";
    ofs << student->DOB.day << "/" << student->DOB.month << "/" << student->DOB.year << "\n";

    cout << "Student added successfully.";

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
    }   
    else
        return;

}

