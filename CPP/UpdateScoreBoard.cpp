#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

void updateStudentsScore(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{
    system("cls");
    gotoXY(67, 1); cout <<"    _    _ _____  _____       _______ ______    _____  _____ ____  _____  ______ ____   ____          _____  _____  ";
    gotoXY(67, 2); cout <<"   | |  | |  __ \\|  __ \\   /\\|__   __|  ____|  / ____|/ ____/ __ \\|  __ \\|  ____|  _ \\ / __ \\   /\\   |  __ \\|  __ \\ ";
    gotoXY(67, 3); cout <<"   | |  | | |__) | |  | | /  \\  | |  | |__    | (___ | |   | |  | | |__) | |__  | |_) | |  | | /  \\  | |__) | |  | |";
    gotoXY(67, 4); cout <<"   | |  | |  ___/| |  | |/ /\\ \\ | |  |  __|    \\___ \\| |   | |  | |  _  /|  __| |  _ <| |  | |/ /\\ \\ |  _  /| |  | |";
    gotoXY(67, 5); cout <<"   | |__| | |    | |__| / ____ \\| |  | |____   ____) | |___| |__| | | \\ \\| |____| |_) | |__| / ____ \\| | \\ \\| |__| |";
    gotoXY(67, 6); cout <<"    \\____/|_|    |_____/_/    \\_\\_|  |______| |_____/ \\_____\\____/|_|  \\_\\______|____/ \\____/_/    \\_\\_|  \\_\\_____/ ";
    gotoXY(71, 9); cout << "------------------------------"<< course_head->course_name <<"--------------------------\n";
    int option = 0;
    do
    {
        string id;
        ifstream ifs;
        ifs.open(filename);
        if (!ifs.is_open())
        {
            cerr << "ERROR: UNABLE TO OPEN FILE FOR READING\n";
            return;
        }
        ofstream ofs;
        ofs.open("../Txt_Csv/temp.csv");
        if (!ofs.is_open())
        {
            cerr << "ERROR: UNABLE TO OPEN FILE FOR WRITING\n";
            return;
        }
        gotoXY(71, 12); cout << "INPUT STUDENT ID: ";
        getline(cin, id);
        int counter = 1;
        string student_id, fullname;
        float total, final1, midterm, other;
        string temp;
        string dummy;
        getline(ifs, dummy);
        ofs << dummy << "\n";
        while (!ifs.eof())
        {
            if (ifs.eof())
                break;
        
            getline(ifs, student_id, ',');
            getline(ifs, fullname, ',');
            getline(ifs, temp, ',');
            midterm = stof(temp);
            getline(ifs, temp, ',');
            final1 = stof(temp);
            getline(ifs, temp, ',');
            other = stof(temp);
            getline(ifs, temp, '\n');
            total = stof(temp);
            
            if (id == student_id)
            {
                gotoXY(71, 14); cout << setw(3) << right << "NO." << counter << " ";
                gotoXY(71, 15); cout << setw(10) << left << student_id << " ";
                gotoXY(71, 16); cout << setw(25) << left << fullname << " ";
                gotoXY(71, 17); cout << setw(5) << right << fixed << setprecision(1) << midterm << " ";
                gotoXY(71, 18); cout << setw(5) << right << fixed << setprecision(1) << final1 << " ";
                gotoXY(71, 19); cout << setw(5) << right << fixed << setprecision(1) << other << " ";
                gotoXY(71, 20); cout << setw(5) << right << fixed << setprecision(1) << total << endl;
                ofs << student_id << "," << fullname << ",";
                gotoXY(71, 21); cout << "ENTER NEW SCORE FOR STUDENT: " << "\n";
                gotoXY(71, 22); cout << "MIDTERM: ";
                gotoXY(71 + 10, 22); cin >> midterm;
                gotoXY(71, 23); cout << "FINAL: ";
                gotoXY(71 + 8, 22); cin >> final1;
                gotoXY(71, 24); cout << "OTHER: ";
                gotoXY(71 + 8, 22); cin >> other;
                total = (midterm + final1 + other)/3.0;
                ofs << fixed << setprecision(1) << midterm << ","
                    << fixed << setprecision(1) << final1 << ","
                    << fixed << setprecision(1) << other << ","
                    << fixed << setprecision(1) << total;
            }
            else
            {
                ofs << student_id << "," << fullname << ",";
                ofs << fixed << setprecision(1) << midterm << ","
                    << fixed << setprecision(1) << final1 << ","
                    <<fixed << setprecision(1) << other << ","
                    << fixed << setprecision(1) << total;
            }
            if (!ifs.eof())
            {
                ofs << "\n";
            }
            counter++;
        }
        ifs.close();
        ofs.close();
        const char* newfilename = filename.c_str();
        remove(newfilename);
        rename("../Txt_Csv/temp.csv", newfilename);
        cout << "Update Successful!\n";
        option = choose_option(filename, username, year_head, semester_head, course_head);
        
    } while (option == 1);
    system("cls");
    accessCourse(username, year_head, semester_head, course_head);
}

int choose_option(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head){
    int a = 18;
    Create_A_Box_1(33,8 + a,2,50,14,14,0,"            UPDATE SUCCESSFUL!");
    Create_A_Box_1(33,10 + a,2,50,14,14,0,"            CONTINUE UPDATING SCOREBOARD");
    Create_A_Box_1(33,12 + a,2,50,14,14,0,"            RETURN BACK");
    gotoXY(33,15); std::cout << (char)(195);
    gotoXY(122,15); std::cout << (char)(180);

    ShowConsoleCursor(false);
    int x_temp = 33, y_temp = 28;
    bool flag = true;
    while (true)
    {
        if (flag == true)
        {
            if (y_temp == 28)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "            CONTINUE UPDATING SCOREBOARD";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 30)
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
                if (y_temp == 28)
                {
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "            CONTINUE UPDATING SCOREBOARD";
                    ShowConsoleCursor(false);
                }
                else if (y_temp == 30)
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

                if (c == UP)
                {
                    if (y_temp == 28)
                    {
                        y_temp = 30;
                    }
                    else
                    {
                        y_temp -= 2;
                    }
                }
                else if (c == 80)
                {
                    if (y_temp == 30)
                    {
                        y_temp = 28;
                    }
                    else
                    {
                        y_temp += 2;
                    }
                }
                else if (c == 13)
                {
                    if (y_temp == 28)
                    {
                        system("cls");
                        return 0;
                    }
                    else if (y_temp == 30)
                    {
                        system("cls");
                        return 1;
                    }
                }
            }
        }
    }
}