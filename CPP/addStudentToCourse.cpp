#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

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
    resizeConsole(1920,920);
    system("color E0");
    gotoXY(40,2);
    std::cout << "        ___ ____________   _____ _____ _   _______ _____ _   _ _____   _____ _____   _____ _____ _   _______  _____ _____";
    gotoXY(40,3);
    std::cout << "       / _ \\|  _  \\  _  \\ /  ___|_   _| | | |  _  \\  ___| \\ | |_   _| |_   _|  _  | /  __ \\  _  | | | | ___ \\/  ___|  ___|";
    gotoXY(40,4);
    std::cout << "      / /_\\ \\ | | | | | | \\ `--.  | | | | | | | | | |__ |  \\| | | |     | | | | | | | /  \\/ | | | | | | |_/ /\\ `--.| |__  ";
    gotoXY(40,5);
    std::cout << "      |  _  | | | | | | |  `--. \\ | | | | | | | | |  __|| . ` | | |     | | | | | | | |   | | | | | | |    /  `--. \\  __| ";
    gotoXY(40,6);
    std::cout << "      | | | | |/ /| |/ /  /\\__/ / | | | |_| | |/ /| |___| |\\  | | |     | | \\ \\_/ / | \\__/\\ \\_/ / |_| | |\\ \\ /\\__/ / |___ ";
    gotoXY(40,7);
    std::cout << "      \\_| |_/___/ |___/   \\____/  \\_/  \\___/|___/ \\____/\\_| \\_/ \\_/     \\_/  \\___/   \\____/\\___/ \\___/\\_| \\_|\\____/\\____/ ";

  
    ofstream ofs;
    string studentID = "";
    Create_A_Box_2(70,15,2,30,14,14,0,"INPUT STUDENT_ID");
    Create_A_Box_1(55,20,2,20,14,14,0,"    RETURN BACK");
    ShowConsoleCursor(false);
    int count = 0;
    int x_temp = 70; int y_temp = 15; int y_old; int xp = x_temp; int yp = y_temp; int pos = 0;
    while (count < 1)
    {
        system("color E0");

        if (y_temp == 15)
        {
            gotoXY(xp + 2, yp + 1);
            ShowConsoleCursor(true);

            char c;
            while (true)
            {
                c = _getch();

                if (c == ENTER)
                {
                    if (studentID != "")
                        count++;

                    xp = 70;
                    yp = y_temp;
                    break;
                }
                else if (c == DOWN)
                {
                    ShowConsoleCursor(false);
                    y_old = y_temp;
                    y_temp = 20;
                    xp = x_temp + studentID.size();
                    yp = y_old;
                    break;
                }
                else if (c == BACKSPACE)
                {
                    if (studentID != "" && pos > 0)
                    {
                        std::cout << "\b \b";
                        studentID.pop_back();
                    }
                }
                else if (c == LEFT)
                {
                    if (pos > 0)
                    {
                        pos--;
                        gotoXY(x_temp + pos + 2, y_temp + 1);
                    }

                    continue;
                }
                else if (c == RIGHT)
                {
                    int len = studentID.size();

                    if (pos < len)
                    {
                        pos++;
                        gotoXY(x_temp + pos + 2, y_temp + 1);
                    }

                    continue;
                }
                else
                {
                    int len = studentID.size();

                    if (c == 45 || (c >= '0' && c <= '9') && len < 26)
                    {
                        pos++;
                        studentID += c;
                        std::cout << c;
                    }
                }
            }
        }
        else
        {
            SetColor1(15,0);
            for (int i = 56; i <= 74; ++i)
            {
                gotoXY(i, y_temp + 1);
                std::cout << " ";
            }

            gotoXY(56, y_temp + 1);
            std::cout << "    RETURN BACK";
            ShowConsoleCursor(false);

            if (_kbhit())
            {
                char c = _getch();

                if (c == UP)
                {
                    ShowConsoleCursor(true);
                    y_temp = y_old;
                }
                else if (c == ENTER)
                {
                    pos = 0; bool check = false;
                    accessCourse(username, year_head, semester_head, course);
                    system("cls");
                    return;
                }
            }
        }
    }

    
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
    
    ofs << '\n' << student->student_ID << "," << student->student_socialID << ","
        << student->student_fisrtname << "," << student->student_lastname << ","
        << student->gender << "," << student->student_class.class_name << ","
        << student->DOB.day << "/" << student->DOB.month << "/" << student->DOB.year;
    ofs.close();

    Create_A_Box_1(68,29,2,39,14,14,0,"   Add Student successfully ");
    for (int i = 0; i < 3; ++i)
    {
        gotoXY(97 + i,30);
        ShowConsoleCursor(false);
        std::cout << "." << flush;
        Sleep(500);
    }

    system("cls");
    accessCourse(username, year_head, semester_head, course);
    return;

}