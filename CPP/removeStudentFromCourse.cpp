#include "../Header/Staff.h"

string printDate(Date a)
{
    string tmp;
    if (a.day < 10)
        tmp += "0" + to_string(a.day) + "/";
    else
        tmp += to_string(a.day) + "/";      
    if (a.month < 10)
        tmp += "0" + to_string(a.month) + "/";
    else
        tmp += to_string(a.month) + '/';
    tmp += to_string(a.year);
    return tmp;
}

void printStudentList(Student* student_head) 
{
    cout << setw(15) << left << "ID"
         << setw(15) << left << "Social ID"
         << setw(25) << left << "First Name"
         << setw(25) << left << "Last Name"
         << setw(10) << left << "Gender"
         << setw(10) << left << "Class"
         << setw(10) << left << "DOB" << endl;
    
    Student* current_student = student_head;
    while (current_student != nullptr) {
        cout << setw(15) << left << current_student->student_ID
             << setw(15) << left << current_student->student_socialID
             << setw(25) << left << current_student->student_fisrtname
             << setw(25) << left << current_student->student_lastname
             << setw(10) << left << (current_student->gender == 0 ? "Male" : "Female")
             << setw(10) << left << current_student->student_class.class_name
             << setw(10) << left << printDate(current_student->DOB) << endl;
        
        current_student = current_student->student_next;
    }
}

Student* findStudentByID(string studentID, Student* head)
{
    Student* current = head; 
    while (current != nullptr) 
    {
        if (current->student_ID == studentID) 
            return current;  
        current = current->student_next; 
    }
    return nullptr; 
}


void removeStudentFromCourse(Course* &course) 
{
    // Print list of student in the Course
    printStudentList(course->student_head);

    string StudentID;
    cout<< "Input StudentID that will remove: ";
    cin>> StudentID;
    // Find the Student using the StudentID entered from the keyboard
    Student* student = findStudentByID(StudentID, course->student_head);

    if (student == nullptr) 
    {
        cout << "Student does not exist." << endl;
        return;
    }

    Student* currentStudent = course->student_head;
    Student* previousStudent = nullptr;
    while (currentStudent != nullptr) 
    {
        if (currentStudent == student) 
        {
            // Remove the student from the course's list of students
            if (previousStudent == nullptr) 
                course->student_head = currentStudent->student_next;
            else 
                previousStudent->student_next = currentStudent->student_next;
            // Remove the course from the student's list of courses
            Course* currentCourse = student->course_head;
            Course* previousCourse = nullptr;
            while (currentCourse != nullptr) 
            {
                if (currentCourse == course) 
                {
                    if (previousCourse == nullptr) 
                        student->course_head = currentCourse->course_next;
                    else 
                        previousCourse->course_next = currentCourse->course_next;
                    cout << "Student " << student->student_ID << " removed from course " << course->course_name << endl;
                    delete currentStudent;
                    delete currentCourse;
                    return;
                }
                previousCourse = currentCourse;
                currentCourse = currentCourse->course_next;
            }
            return;
        }
        previousStudent = currentStudent;
        currentStudent = currentStudent->student_next;
    }
    cout << "Student " << student->student_ID << " is not enrolled in course " << course->course_name << endl;
}


