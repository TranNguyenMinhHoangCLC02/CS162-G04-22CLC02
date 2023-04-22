#include "../Header/Staff.h"
#include "../Header/Design.h"

void accessSemester(string username, Year* &year_head, Semester* &semester_head)
{
    system("cls");
    // cout << "\n";
    // cout << "------------SEMESTER_"<< semester_head->Semester_Ord <<"--------------\n";
    // cout << "0." << setw(2) << right << "Return back\n";
    // cout << "1." << setw(2) << right << "Add a course\n";
    // cout << "2." << setw(2) << right << "Access a course\n";
    // cout << "3." << setw(2) << right << "Update a course\n";
    
    // int option;
    // do
    // {
    //     cout << "Input option: ";
    //     cin >> option;
    // } while (option < 0 || option > 3);

    // if (option == 0)
    // {   
    //     system("cls");
    //     viewSemester_Screen(username, year_head);
    //     return;
    // }
    // else if (option == 1)
    // {
    //     system ("cls");
    //     semester_head->course_head = getCourseListFromFile(year_head, semester_head);
    //     addNewCourse(username, year_head, semester_head);
    //     deallocateCourses(semester_head->course_head);
    //     return;
    // }
    // else if (option == 2)
    // {
    //     system("cls");
    //     semester_head->course_head = getCourseListFromFile(year_head, semester_head);
    //     viewCourse_Screen(username, year_head, semester_head);
    //     deallocateCourses(semester_head->course_head);
    //     return;
    // }
    // else if (option == 3)
    // {
    //     system("cls");
    //     semester_head->course_head = getCourseListFromFile(year_head, semester_head);
    //     viewUpdateCourseInformation(username, year_head, semester_head);
    //     deallocateCourses(semester_head->course_head);
    //     return;
    // }

    SetScreenBufferSize(1000,1000);
    system("color E0");

    gotoXY(60,2);
    std::cout << "   _____ _____ _   _______  _____ _____";
    gotoXY(60,3);
    std::cout << "  /  __ \\  _  | | | | ___ \\/  ___|  ___|";
    gotoXY(60,4);
    std::cout << "  | /  \\/ | | | | | | |_/ /\\ `--.| |__";
    gotoXY(60,5);
    std::cout << "  | |   | | | | | | |    /  `--. \\  __|";
    gotoXY(60,6);
    std::cout << "  | \\__/\\ \\_/ / |_| | |\\ \\ /\\__/ / |___";
    gotoXY(60,7);
    std::cout << "   \\____/\\___/ \\___/\\_| \\_|\\____/\\____/";

    Create_A_Box_1(30,13,2,20,14,14,0,"    ADD A COURSE");
    Create_A_Box_1(70,13,2,20,14,14,0,"  ACCESS A COURSE");
    Create_A_Box_1(110,13,2,20,14,14,0,"  UPDATE A COURSE");
    Create_A_Box_1(70,20,2,20,14,14,0,"    RETURN BACK");
    ShowConsoleCursor(false);

    int x_temp = 30; int y_temp = 13;
    bool flag = true;
    while (true)
    {
        if (flag == true)
        {
            if (x_temp == 30)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "    ADD A COURSE";
                ShowConsoleCursor(false);
            }
            else if (x_temp == 70)
            {
                if (y_temp == 13)
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "  ACCESS A COURSE";
                    ShowConsoleCursor(false);
                }
                else
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "    RETURN BACK";
                    ShowConsoleCursor(false);
                }
            }
            else
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "  UPDATE A COURSE";
                ShowConsoleCursor(false);
            }

            flag = false;
        }
        else
        {
            if (_kbhit())//keyboardhit
            {
                char c = _getch();

                system("color E0");
                if (x_temp == 30)
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "    ADD A COURSE";
                    ShowConsoleCursor(false);
                }
                else if (x_temp == 70)
                {
                    if (y_temp == 13)
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        gotoXY(x_temp + 1, y_temp + 1);
                        std::cout << "  ACCESS A COURSE";
                        ShowConsoleCursor(false);
                    }
                    else
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        gotoXY(x_temp + 1, y_temp + 1);
                        std::cout << "    RETURN BACK";
                        ShowConsoleCursor(false);
                    }
                }
                else
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "  UPDATE A COURSE";
                    ShowConsoleCursor(false);
                }

                flag = true;

                if (c == LEFT)
                {
                    if (x_temp == 30)
                        x_temp = 110;
                    else
                        x_temp -= 40;
                }
                else if (c == RIGHT)
                {
                    if (x_temp == 110)
                        x_temp = 30;
                    else
                        x_temp += 40;
                }
                else if (c == UP)
                {
                    if (y_temp == 20)
                    {
                        x_temp = 30;
                        y_temp = 13;
                    }
                }
                else if (c == DOWN)
                {
                    if (y_temp == 13)
                    {
                        x_temp = 70;
                        y_temp = 20;
                    }
                }
                else if (c == ENTER)
                {
                    if (y_temp == 20)
                    {
                        system("cls");
                        viewSemester_Screen(username, year_head);
                        return;
                    }
                    else
                    {
                        if (x_temp == 30)
                        {
                            system ("cls");
                            semester_head->course_head = getCourseListFromFile(year_head, semester_head);
                            addNewCourse(username, year_head, semester_head);
                            deallocateCourses(semester_head->course_head);
                            return;
                        }
                        else if (x_temp == 70)
                        {
                            system("cls");
                            semester_head->course_head = getCourseListFromFile(year_head, semester_head);
                            viewCourse_Screen(username, year_head, semester_head);
                            deallocateCourses(semester_head->course_head);
                            return;
                        }
                        else
                        {
                            system("cls");
                            semester_head->course_head = getCourseListFromFile(year_head, semester_head);
                            viewUpdateCourseInformation(username, year_head, semester_head);
                            deallocateCourses(semester_head->course_head);
                            return;
                        }
                    }
                }
            }
        }
    }
}