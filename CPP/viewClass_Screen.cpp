#include "../Header/Staff.h"
#include "../Header/Design.h"
void viewClass_Screen(string username, Year* &year_head)
{                                                      
    system("cls");
    resizeConsole(1920,920);
    system("color E0");

    int y = 5;
    gotoXY(100, y + 5);
    std::cout << "                                                                                                    ";
    gotoXY(100, y + 6);
    std::cout << "       .!?YY55555555555555555555555555555555555555555555555555555555555555PPPPP55555YJ7:            ";
    gotoXY(100, y + 7);
    std::cout << "      :PGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGB#&&&&&&&&##BGGGGG~           ";
    gotoXY(100, y + 8);
    std::cout << "      :PGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGB#&&&&&&&&##BGGGGG~           ";
    gotoXY(100, y + 9);
    std::cout << "      ~GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGB#BGP5P55B###GGGGG?           ";
    gotoXY(100, y + 10);
    std::cout << "      ~GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5PPJJ5P5YB#BGGGGG?           ";
    gotoXY(100, y + 11);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPYP555P5YGBPGGGGG?           ";
    gotoXY(100, y + 12);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPYY55555JPGYGGGGG?           ";
    gotoXY(100, y + 13);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBP5J?JJ5B#BGGGGGG?           ";
    gotoXY(100, y + 14);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBGPGGPGB#BGGGGGGG?     :^:   ";
    gotoXY(100, y + 15);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBBPYYGGGGGGGGG?    .7J?^  ";
    gotoXY(100, y + 16);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPYJJY?!?~7JJJJ5GGG?    ^JY?.  ";
    gotoXY(100, y + 17);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGJ~^^^^^~!^^^^^^^?GG?    .?7.   ";
    gotoXY(100, y + 18);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5^^^^^^^!7^^^^^^^^5B?    ^^     ";
    gotoXY(100, y + 19);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGP7^^~^^^^77~^^^^~^^~PJ  .^~:     ";
    gotoXY(100, y + 20);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5~^^!?^^^~77~^^^~Y~^^!? :^~^      ";  
    gotoXY(100, y + 21);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGY~^^^5?^^^!77~^^^^5Y^^^~:~~^       ";
    gotoXY(100, y + 22);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5~^^!5G7^^^!77~^^^^YGJ^^^~^:        ";
    gotoXY(100, y + 23);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGY^^~PGG!^^^~!!^^^^^?GGY7~:.         ";
    gotoXY(100, y + 24);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5!^!PG!^^^^^^^^^^^7GGGB?           ";
    gotoXY(100, y + 25);
    std::cout << "      ^GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGJ~~5~^^^^^^^^^^^!GGGG!           ";
    gotoXY(100, y + 26);
    std::cout << "       ^?Y5PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5?JJ?JYYYYYYYYYYP5J~            ";
    gotoXY(100, y + 27);
    std::cout << "          ...........................................................:?BGGGGGGGGGGBG^               ";
    gotoXY(100, y + 28);
    std::cout << "                                                                       5GGGGGGGGGGGB~               ";
    gotoXY(100, y + 29);
    std::cout << "                                                                       YBGGGGGGGGGGB?               ";
    gotoXY(100, y + 30);
    std::cout << "                                                                       YBGGGG55GGGGGY               ";
    gotoXY(100, y + 31);
    std::cout << "           .^!~~~!~:^~~^                         ...                   JBGGGB?~GBB###P5?^           ";
    gotoXY(100, y + 32);
    std::cout << "         7YY5PPPPPP55PP5J~.                 :~7??JJJ?7~.               JBGGGGPP&@@@@@@@@@7          ";
    gotoXY(100, y + 33);
    std::cout << "        ~5555555555555555Y:                !JYYYYJJJYYYJ~              JBGGGG@@@@@@@@@@@@@P.        ";
    gotoXY(100, y + 34);
    std::cout << "       :555555555555555!.                 ^YJJJJJJJJJJJJY:             ?BGGG&@@@@@@@@@@@@@@:        ";
    gotoXY(100, y + 35);
    std::cout << "       ?P55555555555555:                  ~YJJJJJJJJJJJJY^             ?BGGG#@@@@@@@@@@@@@@!        ";
    gotoXY(100, y + 36);
    std::cout << "       ^J55555555555P5^       .^!PBBJ^.   ^YJJJJJJJJJJJY?              7BGGGG&@@@@@@@@@@@@#~        ";
    gotoXY(100, y + 37);
    std::cout << "         !555PP555PPY:     ~5G#@@@@@@@#P~ :JJJJJJJJJJJJYJ:      .:^~~!~7JYPGP^B@@#GGGB@@&?.         ";
    gotoXY(100, y + 38);
    std::cout << "          .^^~?JJJ!^     .P@@@@@@@@@@@@@@BP5JJJJJJJJJJJJYJ:   .~77777777!!7J5 ^#@@@@@@@@!           ";
    gotoXY(100, y + 39);
    std::cout << "    .:^^^^^^^^^~~~^^^^^^^7@@@@@@@@@@@@@@@@@GJJJJJJJJJJJJJYJ?7~!777777777777!7^!&@@@@@@@&7^~~^^:.    ";
    gotoXY(100, y + 40);
    std::cout << " .^!!!!!!!!!!!!!!!!!!!!!!7#@@@@@@@@@@@@@@@@&YJJJJJJJJJJJJGB##Y!777777777777777?#@@@@@@@&57777777!:  ";
    gotoXY(100, y + 41);
    std::cout << ".~!!!!!!!!!!!!!!!!!!!!!!!G@@@@@@@@@@@@@@@@@&YYYJJYYYJJY55BBBBP7!77777777777777775@@@@@@@@5!7777777^ ";
    gotoXY(100, y + 42);
    std::cout << "^!!!!!77?????????????????&@@@@@@@@@@@@@@@@@GPGGPPGGPPPGGGGGGGB57!77777777777?????G@@@@@@@5????77777.";
    gotoXY(100, y + 43);
    std::cout << "~!!!!!Y5555555555555555PJ:YGB&@@@@@@@@@@##G555555555555555555GBB5?7!!!!777^JP55555#@@@&GP5555577777:";
    gotoXY(100, y + 44);
    std::cout << "~!!!!!YP5555555555555555J.~!!?PB&@@@###B7?5555555555555555555GGG577777777!.?555555PGBGP55555P5?7???:";
    gotoXY(100, y + 45);
    std::cout << ":^^^::~??????????????JYYYJJJJJJJYY5YJYYYJYYYYYYYY???????J?77!777!77777777!!!!!7?J??????????????????^";
    gotoXY(100, y + 46);
    std::cout << "                    !JYYYYYYYYYYYYYYYYYYYYYYYYYYJ7.    ^!!!!!!!!!!!!!!!!!!!!!!!!!~.                 ";
    gotoXY(100, y + 47);
    std::cout << "                   7YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYJ.  ^!!!!!7777777777777777777!!!!.                ";
    gotoXY(100, y + 48);
    std::cout << "                  .JYYYYY55555555555555555555YYYYYY^ .!!!!!75555555555555555555Y!!!^                ";
    gotoXY(100, y + 49);
    std::cout << "                  .JYYYYY55555555555555555555YYYYYY^ .!!!!!75555555555555555555Y!!!^                ";
    gotoXY(100, y + 50);
    std::cout << "                  .JYYYJJ55555555555555555555YJJJJY^ .~!~~~75555555555555555555Y~~!:                ";
    gotoXY(100, y + 51);
    std::cout << "                  .JJJJJJ55555555555555555555YJJJJJ^  ^^^^^!5555555555555555555Y^^~:                ";

    gotoXY(10,2);
    std::cout << "     _____ _    _  ____   ____   _____ ______    _____ _                _____ _____ ";
    gotoXY(10,3);
    std::cout << "    / ____| |  | |/ __ \\ / __ \\ / ____|  ____|  / ____| |        /\\    / ____/ ____|";
    gotoXY(10,4);
    std::cout << "   | |    | |__| | |  | | |  | | (___ | |__    | |    | |       /  \\  | (___| (___  ";
    gotoXY(10,5);
    std::cout << "   | |    |  __  | |  | | |  | |\\___ \\|  __|   | |    | |      / /\\ \\  \\___ \\___ \\ ";
    gotoXY(10,6);
    std::cout << "   | |____| |  | | |__| | |__| |____) | |____  | |____| |____ / ____\\ ____) |___) |";
    gotoXY(10,7);
    std::cout << "    \\_____|_|  |_|\\____/ \\____/|_____/|______|  \\_____|______/_/    \\_\\_____/_____/ ";
    gotoXY(10,8);
    std::cout << "                                                                                     ";
    Class* cur = year_head->class_head; int numClasses = 0;

    //Show list of class the staff has created before
    if (cur == nullptr) //Data is empty
    {
        Create_A_Box_1(32,15,2,20,14,14,0,"    RETURN BACK");
        ShowConsoleCursor(false);
    }
    else
    {
        while (cur)
        {
            std::string name_year = "          " + cur->class_name;
            Create_A_Box_1(27,11 + numClasses * 4 ,2,30,14,14,0, name_year);
            cur = cur->next_class;
            numClasses++;
        }

        Create_A_Box_1(12,11 + 4 * numClasses,2,20,14,14,0,"    RETURN BACK");
        ShowConsoleCursor(false);
    }

    //Move the pointer cur to the pointer class_head again
    cur = year_head->class_head;

    if (cur)
    {
        int x_temp = 27; int y_temp = 11;
        bool flag = true;
        while (true)
        {
            if (flag == true)
            {
                for (int i = 11; i < 11 + 4*numClasses; ++i)
                {
                    if (y_temp == i)
                    {
                        system("color E0");
                        SetColor1(15,0);
                        for (int j = x_temp + 1; j <= x_temp + 29; ++j)
                        {
                            gotoXY(j, y_temp + 1);
                            std::cout << " ";
                        }

                        gotoXY(x_temp + 1, y_temp + 1);

                        Class* temp = year_head->class_head;
                        for (int j = 0; j < (y_temp - 11)/4; ++j)
                        {
                            temp = temp->next_class;
                        }  

                        std::string name_year = "          " + temp->class_name;
                        std::cout << name_year;
                        ShowConsoleCursor(false);
                    }
                }

                if (y_temp == 11 + 4*numClasses)
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int j = 13; j <= 31; ++j)
                    {
                        gotoXY(j, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(13, y_temp + 1);
                    std::cout << "    RETURN BACK";
                    ShowConsoleCursor(false);
                }
    
                flag = false;
            }
            else
            {
                if (_kbhit())
                {
                    char c = _getch();
    
                    for (int i = 11; i < 11 + 4*numClasses; ++i)
                    {
                        if (y_temp == i)
                        {
                            system("color E0");
                            SetColor1(14,0);
                            for (int j = x_temp + 1; j <= x_temp + 29; ++j)
                            {
                                gotoXY(j, y_temp + 1);
                                std::cout << " ";
                            }

                            gotoXY(x_temp + 1, y_temp + 1);

                            Class* temp = year_head->class_head;
                            for (int j = 0; j < (y_temp - 11)/4; ++j)
                            {
                                temp = temp->next_class;
                            }  

                            std::string name_year = "          " + temp->class_name;
                            std::cout << name_year;
                            ShowConsoleCursor(false);
                        }
                    }

                    if (y_temp == 11 + 4*numClasses)
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int j = 13; j <= 31; ++j)
                        {
                            gotoXY(j, y_temp + 1);
                            std::cout << " ";
                        }

                        gotoXY(13, y_temp + 1);
                        std::cout << "    RETURN BACK";
                        ShowConsoleCursor(false);
                    }
    
                    flag = true;
    
                    if (c == UP)
                    {
                        if (y_temp == 11)
                            y_temp = 11 + 4*numClasses;
                        else
                            y_temp -= 4;
                    }
                    else if (c == DOWN)
                    {
                        if (y_temp == 11 + 4*numClasses)
                            y_temp = 11;
                        else
                            y_temp += 4;
                    }
                    else if (c == ENTER)
                    {
                        if (y_temp == 11 + 4*numClasses)
                        {
                            system("cls");
                            accessSchoolYear(username, year_head);
                            return;
                        }
                        else
                        {
                            Class* temp = year_head->class_head;
                            for (int j = 0; j < (y_temp - 11)/4; ++j)
                            {
                                temp = temp->next_class;
                            }

                            accessClass(username, year_head, temp);
                            return;
                        }
                    }
                }
            }
        }
    }

    bool flag = true;
    while (true)
    {
        if (flag == true)
        {
            system("color E0");
            SetColor1(15,0);
            for (int j = 33; j <= 51; ++j)
            {
                gotoXY(j, 16);
                std::cout << " ";
            }

            gotoXY(33, 16);
            std::cout << "    RETURN BACK";
            ShowConsoleCursor(false);

            flag = false;
        }
        else
        {
            if (_kbhit())
            {
                char c = _getch();
                flag = true;

                if (c == ENTER)
                {
                    system("cls");
                    Main_Staff_Screen(username, year_head);
                    return;
                }
            }
        }
    }
    system("cls");
    accessSchoolYear(username, year_head);
}
