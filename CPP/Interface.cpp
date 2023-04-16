#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

int firstScreen(bool &check)
{
    SetScreenBufferSize(1000,1000);
    system("color E0");
    check = true;

    gotoXY(32,2);
    std::cout << " ___  ___ ___  _   _  ___  _____ ________  ________ _   _ _____   _______   _______ _____ ________  ___";
    gotoXY(32,3);
    std::cout << " |  \\/  |/ _ \\| \\ | |/ _ \\|  __ \\  ___|  \\/  |  ___| \\ | |_   _| /  ___\\ \\ / /  ___|_   _|  ___|  \\/  |";
    gotoXY(32,4);
    std::cout << " | .  . / /_\\ \\  \\| / /_\\ \\ |  \\/ |__ | .  . | |__ |  \\| | | |   \\ `--. \\ V /\\ `--.  | | | |__ | .  . |";
    gotoXY(32,5);
    std::cout << " | |\\/| |  _  | . ` |  _  | | __|  __|| |\\/| |  __|| . ` | | |    `--. \\ \\ /  `--. \\ | | |  __|| |\\/| |";
    gotoXY(32,6);
    std::cout << " | |  | | | | | |\\  | | | | |_\\ \\ |___| |  | | |___| |\\  | | |   /\\__/ / | | /\\__/ / | | | |___| |  | |";
    gotoXY(32,7);
    std::cout << " \\_|  |_|_| |_|_| \\_|_| |_/\\____|____/\\_|  |_|____/\\_| \\_/ \\_/   \\____/  \\_/ \\____/  \\_/ \\____/\\_|  |_/";

    Create_A_Box_1(67,10,2,30,14,14,0,"            STAFF");
    Create_A_Box_1(67,12,2,30,14,14,0,"           STUDENT");
    gotoXY(67,12); std::cout << (char)(195);
    gotoXY(97,12); std::cout << (char)(180);

    Create_A_Box_1(67,14,2,30,14,14,0,"         OUT PROGRAM");
    gotoXY(67,14); std::cout << (char)(195);
    gotoXY(97,14); std::cout << (char)(180);
    ShowConsoleCursor(false);

    int x_temp = 67; int y_temp = 10;
    bool flag = true;
    while (check == true)
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
                std::cout << "            STAFF";
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
                std::cout << "           STUDENT";
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
                std::cout << "         OUT PROGRAM";
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
                    std::cout << "            STAFF";
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
                    std::cout << "           STUDENT";
                    ShowConsoleCursor(false);
                }
                else
                {
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "         OUT PROGRAM";
                    ShowConsoleCursor(false);
                }

                flag = true;

                if (c == UP)
                {
                    if (y_temp == 10)
                        y_temp = 14;
                    else
                        y_temp -= 2;
                }
                else if (c == DOWN)
                {
                    if (y_temp == 14)
                        y_temp = 10;
                    else
                        y_temp += 2;
                }
                else if (c == ENTER)
                {
                    ShowConsoleCursor(true);
                    if (y_temp == 14)
                        check = false;
                    else if (y_temp == 12)
                        return 2;
                    else
                        return 1;
                    break;
                }
            }
        }
    }
    return 0;
}

void Main_Staff_Screen(string &username, Year* &year_head)
{
    SetScreenBufferSize(1000,1000);
    system("color E0");

    gotoXY(66,2);
    std::cout << "   _____ _____ ___ ____________";
    gotoXY(66,3);
    std::cout << "  /  ___|_   _/ _ \\|  ___|  ___|";
    gotoXY(66,4);
    std::cout << "  \\ `--.  | |/ /_\\ \\ |_  | |_";
    gotoXY(66,5);
    std::cout << "   `--. \\ | ||  _  |  _| |  _|";
    gotoXY(66,6);
    std::cout << "  /\\__/ / | || | | | |   | |";
    gotoXY(66,7);
    std::cout << "  \\____/  \\_/\\_| |_|_|   \\_|";

    Create_A_Box_1(67,10,2,30,14,14,0,"           LOG OUT");
    Create_A_Box_1(67,12,2,30,14,14,0,"         VIEW PROFILE");
    gotoXY(67,12); std::cout << (char)(195);
    gotoXY(107,12); std::cout << (char)(180);
    Create_A_Box_1(67,14,2,40,14,14,0,"            ACCESS SCHOOL YEAR");
    gotoXY(67,14); std::cout << (char)(195);
    gotoXY(107,14); std::cout << (char)(180);
    Create_A_Box_1(67,16,2,40,14,14,0,"            CHANGE PASSWORD");
    gotoXY(67,16); std::cout << (char)(195);
    gotoXY(107,16); std::cout << (char)(180);

    Create_A_Box_1(67,18,2,40,14,14,0,"            LOG OUT PROGRAM");
    gotoXY(67,18); std::cout << (char)(195);
    gotoXY(107,18); std::cout << (char)(180);
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
                std::cout << "            VIEW PROFILE";
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
                std::cout << "            ADD NEW SCHOOL YEAR";
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
                std::cout << "            ACCESS SCHOOL YEAR";
                ShowConsoleCursor(false);
            }
            else if(y_temp == 16)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "            CHANGE PASSWORD";
                ShowConsoleCursor(false);
            }
            else if(y_temp == 18)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "            LOG OUT PROGRAM";
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
                system("color E0");
                if (y_temp == 10)
                {
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "           LOG OUT";
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
                    std::cout << "            ADD NEW SCHOOL YEAR";
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
                    std::cout << "            ACCESS SCHOOL YEAR";
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
                    std::cout << "            CHANGE PASSWORD";
                    ShowConsoleCursor(false);
                }
                else
                {
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "            LOG OUT PROGRAM";
                    ShowConsoleCursor(false);
                }

                flag = true;

                if (c == UP)
                {
                    if (y_temp == 10)
                    {
                        y_temp = 18;
                    }
                    else
                    {
                        y_temp -= 2;
                    }
                }
                else if (c == 80)
                {
                    if (y_temp == 18)
                    {
                        y_temp = 10;
                    }
                    else
                    {
                        y_temp += 2;
                }
                else if (c == ENTER)
                {
                    ShowConsoleCursor(true);
                    if (y_temp == 10)
                    {
                        system("cls");
                        main();
                        return;
                    }
                    else if (y_temp == 12)
                    {
                        system("cls");
                        staff_info(username, year_head);
                        return;
                    }
                    else if (y_temp == 14)
                    {
                        system("cls");
                        year_head = getYearListFromFile();
                        addNewSchoolYear(year_head);
                        deallocateYears(year_head);
                        system("cls");
                        Main_Staff_Screen(username, year_head);
                        return;
                    }
                    else if (y_temp == 16)
                    {
                        system("cls");
                        year_head = getYearListFromFile();
                        viewSchoolYear_Screen(username, year_head);
                        deallocateYears(year_head);
                        return;
                    }
                    else
                    {
                        system("cls");
                        int opt = 1;
                        changePass(username, false, opt);
                        
                        if (opt)
                            Myinterface(1, year_head);
                        else
                        {
                            system("cls");
                            Main_Staff_Screen(username, year_head);
                        }

                        return;
                    }

                    break;
                }
            }
        }
    }
    return 0;
}

void Main_Student_Screen(string username)
{
    cout << "------------------STUDENT---------------\n";
    int option; bool check;
    cout << "0." << setw(2) << right << "Log out\n";
    cout << "1." << setw(2) << right << "View profile\n";
    cout << "2." << setw(2) << right << "View courses\n";
    cout << "3." << setw(2) << right << "Change password\n";
    cout << "4." << setw(2) << right << "View Scoreboard\n";
    do
    {
        cout << "Input option: ";
        cin >> option;
    } while (option != 0 && option != 1 && option != 2 && option != 3 && option!=4);

    if (option == 0){
        system("cls");
        main();
        return;
    }
    else if(option == 1)
    {
        system("cls");
        student_info(username);
        system("cls");
        Main_Student_Screen(username);
        return;
    }
    else if (option == 2)
    {
        
    }
    else if (option == 3)
    {
        Year* year_head = nullptr;

        system("cls");
        int opt = 1;
        changePass(username, true, opt);

        if (opt)
            Myinterface(0, year_head);
        else
        {
            system("cls");
            Main_Student_Screen(username);
        }

        return;
    }
    else if (option == 4)
    {
        viewScoreBoard_Student(username);
    }
}

void Myinterface(int option, Year* &year_head)
{
    system("cls");
    string username;
    if (option == 1)
    {
        bool opt;
        login(option - 1, username, opt);

        if (opt == 1)
        {
            system("cls");
            Main_Staff_Screen(username, year_head);
        }

        return;
    }
    else
    {
        bool opt;
        login(option - 1, username, opt);
        
        if (opt == 1)
        {
            system("cls");
            Main_Student_Screen(username);
        }

        return;
    }
}