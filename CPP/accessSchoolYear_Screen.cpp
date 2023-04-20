#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

// void accessSchoolYear(string username, Year* &year_head)
// {
//     system("cls");
//     cout << "\n";
//     cout << "------------"<< year_head->year_name <<"--------------\n";
//     cout << "0." << setw(2) << right << "Return back\n";
//     cout << "1." << setw(2) << right << "Add a semester\n";
//     cout << "2." << setw(2) << right << "Access a semester\n";
//     cout << "3." << setw(2) << right << "Add a class\n";
//     cout << "4." << setw(2) << right << "Access a class\n";

//     int option;
//     do
//     {
//         cout << "Input option: ";
//         cin >> option;
//     } while (option < 0 || option > 4);

//     if (option == 0)
//     {
//         system("cls");
//         viewSchoolYear_Screen(username, getYearListFromFile());
//         return;
//     }

//     if (option == 1)
//     {
//         system("cls");
//         year_head->semester_head = getSemesterListFromFile(year_head);
//         addNewSemester(username, year_head);
//         deallocateSemesters(year_head->semester_head);
//         return;
//     }

//     if (option == 2)
//     {
//         system("cls");
//         year_head->semester_head = getSemesterListFromFile(year_head);
//         viewSemester_Screen(username, year_head);
//         deallocateSemesters(year_head->semester_head);
//         return;
//     }

//     if (option == 3)
//     {
//         system("cls");
//         string filename;
//         filename = "class.txt"; 
//         filename = "../Txt_Csv/" + filename;      
//         year_head->class_head = getClassListFromFile(year_head, filename);
//         addNewClass(year_head, username);
//         deallocateClasses(year_head->class_head);
//         return;
//     }
    
//     system("cls");
//     viewClass_Screen(username, year_head);
// }

void accessSchoolYear(string username, Year* &year_head)
{
    system("cls");
    SetScreenBufferSize(1000,1000);
    SetColor1(14,0);
    gotoXY(45,1); std::cout <<"   _____  _____  _   _  _____  _____  _      __   __ _____  ___  ______"; 
    gotoXY(45,2); std::cout <<"  /  ___|/  __ \\| | | ||  _  ||  _  || |     \\ \\ / /|  ___|/ _ \\ | ___ \\";
    gotoXY(45,3); std::cout <<"  \\ `--. | /  \\/| |_| || | | || | | || |      \\ V / | |__ / /_\\ \\| |_/ /";
    gotoXY(45,4); std::cout <<"   `--. \\| |    |  _  || | | || | | || |       \\ /  |  __||  _  ||    /"; 
    gotoXY(45,5); std::cout <<"  /\\__/ /| \\__/\\| | | |\\ \\_/ /\\ \\_/ /| |____   | |  | |___| | | || |\\ \\"; 
    gotoXY(45,6); std::cout <<"  \\____/  \\____/\\_| |_/ \\___/  \\___/ \\_____/   \\_/  \\____/\\_| |_/\\_| \\_|";
    gotoXY(66, 8); std::cout << "------------" << year_head->year_name << "--------------\n";
    Create_A_Box_1(67,10,2,30,14,14,0,"          RETURN BACK");
    Create_A_Box_1(67,12,2,30,14,14,0,"        ADD A SEMESTER");
    gotoXY(67,12); std::cout << (char)(195);
    gotoXY(97,12); std::cout << (char)(180);

    Create_A_Box_1(67,14,2,30,14,14,0,"      ACCESS A SEMESTER");
    gotoXY(67,14); std::cout << (char)(195);
    gotoXY(97,14); std::cout << (char)(180);

    Create_A_Box_1(67,16,2,30,14,14,0,"         ADD A CLASS");
    gotoXY(67,16); std::cout << (char)(195);
    gotoXY(97,16); std::cout << (char)(180);

    Create_A_Box_1(67,18,2,30,14,14,0,"        ACCESS A CLASS");
    gotoXY(67,18); std::cout << (char)(195);
    gotoXY(97,18); std::cout << (char)(180);
    ShowConsoleCursor(false);

    int x_temp = 67; int y_temp = 10;
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
                std::cout << "          RETURN BACK";
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
                std::cout << "        ADD A SEMESTER";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 14)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "      ACCESS A SEMESTER";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 16)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "         ADD A CLASS";
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
                std::cout << "        ACCESS A CLASS";
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
                    std::cout << "          RETURN BACK";
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
                    std::cout << "        ADD A SEMESTER";
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
                    std::cout <<"      ACCESS A SEMESTER";
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
                    std::cout << "         ADD A CLASS";
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
                    std::cout << "        ACCESS A CLASS";
                    ShowConsoleCursor(false);
                }

                flag = true;

                if (c == UP)
                {
                    if (y_temp == 10)
                        y_temp = 18;
                    else
                        y_temp -= 2;
                }
                else if (c == DOWN)
                {
                    if (y_temp == 18)
                        y_temp = 10;
                    else
                        y_temp += 2;
                }
                else if (c == ENTER)
                {
                    ShowConsoleCursor(true);
                    if (y_temp == 10)
                    {
                        system("cls");
                        viewSchoolYear_Screen(username, getYearListFromFile());
                        return;
                    }
                    else if (y_temp == 12)
                    {
                        system("cls");
                        year_head->semester_head = getSemesterListFromFile(year_head);
                        addNewSemester(username, year_head);
                        deallocateSemesters(year_head->semester_head);
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
                        string filename;
                        filename = "class.txt"; 
                        filename = "../Txt_Csv/" + filename;      
                        year_head->class_head = getClassListFromFile(year_head, filename);
                        addNewClass(year_head, username);
                        deallocateClasses(year_head->class_head);
                        return;
                    }
                    else
                    {
                        system("cls");
                        viewClass_Screen(username, year_head);
                        return;
                    }

                    break;
                }
            }
        }
    }
}