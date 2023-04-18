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

void deleteStudent(Student *&student_head, string studentID)
{
    // Find the student with the given studentID
    Student *current = student_head;
    Student *previous = nullptr;
    while (current != nullptr && current->student_ID != studentID) {
        previous = current;
        current = current->student_next;
    }

    // If the student is found, delete it
    if (current != nullptr) {
        // If the student is the first in the list
        if (previous == nullptr) 
            student_head = current->student_next;
        else
            previous->student_next = current->student_next;
        delete current;
    }
}

Student* getListStuFromFile(string filename)
{
    ifstream ifs;
    ifs.open(filename);
    if (!ifs.is_open())
    {
        cerr << "Error: Unable to open file for reading\n";
        return nullptr;
    }
    Student* student_head = nullptr;
    // string dummy;
    // getline(ifs, dummy);
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

        addTail(student_head, new_student);
    }

    ifs.close();
    return student_head;
}

void removeStudent(string filename, string studentID) 
{
    ifstream fin(filename); // Open the file for reading
    ofstream fout("temp.txt"); // Open a temporary file for writing


    Student* tmp = getListStuFromFile(filename);
    deleteStudent(tmp, studentID);
    
    while (tmp != nullptr) {
        fout << tmp->student_ID << "," << tmp->student_socialID << ","
             << tmp->student_fisrtname << "," << tmp->student_lastname << ","
             << tmp->gender << "," << tmp->student_class.class_name << "," << printDate(tmp->DOB) << "\n";
        tmp = tmp->student_next;
    }
    
    fin.close(); // Close the input file
    fout.close(); // Close the temporary file
    
    remove(filename.c_str()); // Delete the original file
    rename("temp.txt", filename.c_str()); // Rename the temporary file to the original filename
}

void removeStudentFromCourse(string username, Course* &course, Year* &year_head, Semester* semester_head) 
{
    ofstream ofs;
    // Print list of student in the Course
    printStudentList(course->student_head);

    string studentID;
    cout<< "Input StudentID that will remove: ";
    cin>> studentID;
    // Find the Student using the StudentID entered from the keyboard
    Student* student = findStudentInClass(year_head->class_head , studentID);

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

    // remove student from file
    string file_name = course->course_ID + "_Semester" + (char)(semester_head->Semester_Ord + 48) + "_" + year_head->year_name + ".csv";
    file_name = "../Txt_Csv/" + file_name;
    removeStudent(file_name, studentID);
    ofs.open(file_name);
    if (!ofs.is_open())
    {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }
}
