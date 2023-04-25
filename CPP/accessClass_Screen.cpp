#include "../Header/Staff.h"
#include "../Header/Design.h"

int CLASS_Interface(string &username, Year* &year_head, Class *class_head){

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
    int a = 3;
    Create_A_Box_1(72,10 + a,2,50,14,14,0,"            IMPORT NEW STUDENT TO .CSV FILE");
    Create_A_Box_1(72,12 + a,2,50,14,14,0,"            VIEW ALL STUDENTS IN THIS CLASS");
    gotoXY(72,15); std::cout << (char)(195);
    gotoXY(122,15); std::cout << (char)(180);
    Create_A_Box_1(72,14 + a,2,50,14,14,0,"            VIEW SCOREBOARD FOR THIS CLASS");
    gotoXY(72,17); std::cout << (char)(195);
    gotoXY(122,17); std::cout << (char)(180);
    Create_A_Box_1(72,16 + a,2,50,14,14,0,"            RETURN BACK");
    gotoXY(72,19); std::cout << (char)(195);
    gotoXY(122,19); std::cout << (char)(180);

    ShowConsoleCursor(false);
    int x_temp = 72, y_temp = 13;
    bool flag = true;
    while (true)
    {
        if (flag == true)
        {
            if (y_temp == 13)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "            IMPORT NEW STUDENT TO .CSV FILE";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 15)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "            VIEW ALL STUDENTS IN THIS CLASS";
                ShowConsoleCursor(false);
            }
            else if(y_temp == 17)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "            VIEW SCOREBOARD FOR THIS CLASS";
                ShowConsoleCursor(false);
            }
            else
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "            RETURN BACK";
                ShowConsoleCursor(false);
            }
            flag = false;
        }
        else
        {
            if (_kbhit())
            {
                char c = _getch();

                system("color E0");
                if (y_temp == 13)
                {
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "            IMPORT NEW STUDENT TO .CSV FILE";
                    ShowConsoleCursor(false);
                }
                else if (y_temp == 15)
                {
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "            VIEW ALL STUDENTS IN THIS CLASS";
                    ShowConsoleCursor(false);
                }
                else if (y_temp == 17)
                {
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "            VIEW SCOREBOARD FOR THIS CLASS";
                    ShowConsoleCursor(false);
                }
                else if (y_temp == 19)
                {
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "            RETURN BACK";
                    ShowConsoleCursor(false);
                }

                flag = true;

                if (c == 72)
                {
                    if (y_temp == 13)
                    {
                        y_temp = 19;
                    }
                    else
                    {
                        y_temp -= 2;
                    }
                }
                else if (c == 80)
                {
                    if (y_temp == 19)
                    {
                        y_temp = 13;
                    }
                    else
                    {
                        y_temp += 2;
                    }
                }
                else if (c == 13)
                {
                    if (y_temp == 13)
                    {
                        system("cls");
                        return 1;
                    }
                    else if (y_temp == 15)
                    {
                        system("cls");
                        return 2;
                    }
                    else if (y_temp == 17)
                    {
                        system("cls");
                        return 3;
                    }
                    else
                    {
                        system("cls");
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

void accessClass(string username, Year* &year_head, Class *class_head)
{
    system("cls");

    int option = CLASS_Interface(username, year_head, class_head);

    if (option == 0)
    {
        system("cls");
        accessSchoolYear(username, year_head);
        return;
    }
    else if (option == 1)
    {
        system("cls");
        class_head->student_head = getStudentListFromFile(year_head, class_head);
        addNewStudent(username, year_head, class_head);
        // deallocateStudents(class_head->student_head);
        return;
    }
    else if(option == 2)
    {
        viewStudentInClass(username, year_head, class_head);
    }
    else if (option == 3)
    {
        system("cls");
        viewScoreBoard_Class(username, year_head, class_head);
    }
    system("cls");
    accessSchoolYear(username, year_head);
    return;
}