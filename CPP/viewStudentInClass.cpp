#include "../Header/Staff.h"
#include "../Header/Design.h"


void viewStudentInClass(string username, Year* &year_head, Class *class_head)
{
    system("cls");
    SetColor1(14,0);
    gotoXY(67,2); std::cout << "     _____ _                _____ _____   _____   ____   ____  __  __ ";
    gotoXY(67,3); std::cout << "    / ____| |        /\\    / ____/ ____| |  __ \\ / __ \\ / __ \\|  \\/  |";
    gotoXY(67,4); std::cout << "   | |    | |       /  \\  | (___| (___   | |__) | |  | | |  | | \\  / |";
    gotoXY(67,5); std::cout << "   | |    | |      / /\\ \\   \\___ \\___ \\  |  _  /| |  | | |  | | |\\/| |";
    gotoXY(67,6); std::cout << "   | |____| |____ / ____ \\ ____) |___) | | | \\ \\| |__| | |__| | |  | |";
    gotoXY(67,7); std::cout << "    \\_____|______/_/    \\_\\_____/_____/  |_|  \\_\\\\____/ \\____/|_|  |_|";
    gotoXY(67,8); std::cout << " ";
    gotoXY(67,9); std::cout << "----------------------------CLASS-" << class_head->class_name << "-----------------------------";
    //Show list of students the staff has added before
    int numStudents = 0;
    if (class_head->student_head == nullptr) //Data is empty
    {
        gotoXY(67,11); std::cout << "There is no student in this class";
    }
    else
    {   
        Student* cur = class_head->student_head;
        gotoXY(67,11);
        while (cur)
        {
            cur = cur->student_next;
            numStudents += 2;
        }
        cur = class_head->student_head;
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
                    accessClass(username, year_head, class_head);
                    return;
                }
            }
    }
}