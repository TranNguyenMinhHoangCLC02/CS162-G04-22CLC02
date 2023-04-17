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
    
    Create_A_Box_1(67,10,2,50,14,14,0,"            IMPORT NEW STUDENT TO .CSV FILE");
    Create_A_Box_1(67,12,2,50,14,14,0,"            VIEW ALL STUDENTS IN THIS CLASS");
    gotoXY(67,12); std::cout << (char)(195);
    gotoXY(117,12); std::cout << (char)(180);
    Create_A_Box_1(67,14,2,50,14,14,0,"            VIEW SCOREBOARD FOR THIS CLASS");
    gotoXY(67,14); std::cout << (char)(195);
    gotoXY(117,14); std::cout << (char)(180);
    Create_A_Box_1(67,16,2,50,14,14,0,"            RETURN BACK");
    gotoXY(67,16); std::cout << (char)(195);
    gotoXY(117,16); std::cout << (char)(180);

    ShowConsoleCursor(false);
    int x_temp = 67, y_temp = 10;
    bool flag = true;
    while (true)
    {
        if (flag == true)
        {
            if (y_temp == 10)
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
            else if (y_temp == 12)
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
            else if(y_temp == 14)
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
                if (y_temp == 10)
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
                else if (y_temp == 12)
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
                else if (y_temp == 14)
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
                else if (y_temp == 16)
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
                    if (y_temp == 10)
                    {
                        y_temp = 16;
                    }
                    else
                    {
                        y_temp -= 2;
                    }
                }
                else if (c == 80)
                {
                    if (y_temp == 16)
                    {
                        y_temp = 10;
                    }
                    else
                    {
                        y_temp += 2;
                    }
                }
                else if (c == 13)
                {
                    if (y_temp == 10)
                    {
                        system("cls");
                        return 1;
                    }
                    else if (y_temp == 12)
                    {
                        system("cls");
                        return 2;
                    }
                    else if (y_temp == 14)
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
        year_head->class_head->student_head = getStudentListFromFile(year_head, class_head);
        addNewStudent(username, year_head, class_head);
        deallocateStudents(year_head->class_head->student_head);
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
}