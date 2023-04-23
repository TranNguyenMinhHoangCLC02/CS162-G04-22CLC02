#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

void viewStudentInCourse(string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{
    system("cls");
    SetColor1(14,0);
    gotoXY(67,2); std::cout << "     _____ ____  _    _ _____   _____ ______   _____  ______ _______       _____ _      ";
    gotoXY(67,3); std::cout << "    / ____/ __ \\| |  | |  __ \\ / ____|  ____| |  __ \\|  ____|__   __|/\\   |_   _| |     ";
    gotoXY(67,4); std::cout << "   | |   | |  | | |  | | |__) | (___ | |__    | |  | | |__     | |  /  \\    | | | |     ";
    gotoXY(67,5); std::cout << "   | |   | |  | | |  | |  _  / \\___ \\|  __|   | |  | |  __|    | | / /\\ \\   | | | |     ";
    gotoXY(67,6); std::cout << "   | |___| |__| | |__| | | \\ \\ ____) | |____  | |__| | |____   | |/ ____ \\ _| |_| |____ ";
    gotoXY(67,7); std::cout << "    \\_____\\____/ \\____/|_|  \\_\\_____/|______| |_____/|______|  |_/_/    \\_\\_____|______|";
    gotoXY(67,8); std::cout << " ";
    gotoXY(67,9); std::cout << "--------------------------------" << course_head->course_name << "--" << course_head->class_name << "-----------------------------";
    //Show list of students the staff has added before
    int numStudents = 0;
    if (course_head->student_head == nullptr) //Data is empty
    {
        gotoXY(67,11); std::cout << "THERE IS NO STUDENT IN THIS COURSE";
    }
    else
    {   
        Student* cur = course_head->student_head;
        gotoXY(67,11);
        while (cur)
        {
            cur = cur->student_next;
            numStudents += 2;
        }
        cur = course_head->student_head;
        Create_A_Box_1(67,13,numStudents,50,14,14,0,"");
        int i = 0;
        int count = 0;
        while(cur)
        {
            gotoXY(69,14 + i); cout << count + 1 << "." << setw(2) << right << cur->student_fisrtname << " " << cur->student_lastname;
            cur = cur->student_next;
            count++;
            i = i+2;
        }
    }


    gotoXY(67,15 + numStudents); 
    Create_A_Box_1(67,15 + numStudents,2,30,14,14,0,"          RETURN BACK");
    while (true)
    {
        if (_kbhit())
            {
                char c = _getch();
                system("color E0");
                SetColor1(15,0);
                gotoXY(68,15 + numStudents + 1); 
                std::cout << "          RETURN BACK";
                if (c == 13)
                {
                    system("cls");
                    accessCourse(username, year_head, semester_head, course_head);
                    return;
                }
            }
    }
}