#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

string getYearStr(string username)
{
    resizeConsole(1920,920);
    system("color E0");
    SetColor1(14, 0);
    gotoXY(24, 1); cout <<"   _____  _____  _____ ______  _____ ______  _____   ___  ______ ______";
    gotoXY(24, 2); cout <<"  /  ___|/  __ \\|  _  || ___ \\|  ___|| ___ \\|  _  | / _ \\ | ___ \\|  _  \\";
    gotoXY(24, 3); cout <<"  \\ `--. | /  \\/| | | || |_/ /| |__  | |_/ /| | | |/ /_\\ \\| |_/ /| | | |";
    gotoXY(24, 4); cout <<"   `--. \\| |    | | | ||    / |  __| | ___ \\| | | ||  _  ||    / | | | |";
    gotoXY(24, 5); cout <<"  /\\__/ /| \\__/\\\\ \\_/ /| |\\ \\ | |___ | |_/ /\\ \\_/ /| | | || |\\ \\ | |/ /";
    gotoXY(24, 6); cout <<"  \\____/  \\____/ \\___/ \\_| \\_|\\____/ \\____/  \\___/ \\_| |_/\\_| \\_||___/";
    Create_A_Box_2(1, 11, 2, 30, 14, 14, 0, "INPUT A YEAR(0000-0000)");
    Create_A_Box_1(1, 14, 2, 14, 14, 14, 0, " RETURN BACK");
    ShowConsoleCursor(false);
    int counter=0;
    string year="";
    int x_temp = 1; int y_temp = 11; int y_old; int xp = x_temp; int yp = y_temp; int pos_year = 0;
    while (counter < 1)
    {
        system("color E0");

        if (y_temp == 11)
        {
            gotoXY(xp + 2, yp + 1);
            ShowConsoleCursor(true);

            char c;
            while (true)
            {
                c = _getch();

                if (c == ENTER)
                {
                    if (year != "")
                        counter++;
                    xp = 1;
                    yp = y_temp;
                    break;
                }
                else if (c == DOWN)
                {
                    ShowConsoleCursor(false);
                    y_old = y_temp;
                    y_temp = 14;
                    xp = x_temp + year.size();
                    yp = y_old;
                    break;
                }
                else if (c == BACKSPACE)
                {
                    if (year != "" && pos_year > 0)
                    {
                        std::cout << "\b \b";
                        year.pop_back();
                    }
                }
                else if (c == LEFT)
                {
                    int len = year.size();

                    if (pos_year > 0)
                    {
                        pos_year--;
                        gotoXY(x_temp + pos_year + 2, y_temp + 1);
                    }

                    continue;
                }
                else if (c == RIGHT)
                {
                    int len = year.size();

                    if (pos_year < len)
                    {
                        pos_year++;
                        gotoXY(x_temp + pos_year + 2, y_temp + 1);
                    }

                    continue;
                }
                else
                {
                    int len = year.size();

                    if (c >= 32 && c <= 126 && len < 26)
                    {
                        pos_year++;
                        year += c;
                        std::cout << c;
                    }
                }
            }
        }
        else
        {
            SetColor1(15,0);
            for (int i = 1 + 1; i <= 14; ++i)
            {
                gotoXY(i, 15);
                std::cout << " ";
            }
            gotoXY(1 + 1, 15);
            std::cout << " RETURN BACK";
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
                    system("cls");
                    Main_Student_Screen(username);
                    return "";
                }
            }
        }
    }
    system("cls");
    return year;
}

void viewScoreBoard_Student(string username)
{
    system("cls");
    system("color E0");
    SetColor1(14, 0);
    string year;
    Student *user = new Student();
    ifstream ifs;
    ifs.open("../Txt_Csv/student_info.csv");
    string dummy;
    getline(ifs, dummy);
    string first_name, last_name, student_class, student_ID, social_ID, DOB, gender;
    while (!ifs.eof())
    {
        getline(ifs, student_ID, ',');
        if (student_ID == username)
        {
            user->student_ID = student_ID;
            getline(ifs, social_ID, ',');
            user->student_socialID = social_ID;
            getline(ifs, first_name, ',');
            user->student_fisrtname = first_name;
            getline(ifs, last_name, ',');
            user->student_lastname = last_name;
            getline(ifs, gender, ',');
            user->gender=stoi(gender);
            getline(ifs, student_class, ',');
            user->student_class.class_name = student_class;
            getline(ifs, DOB, '\n');
            getDate(user, DOB);
            break;
        }
        else
            getline(ifs, dummy);
    }
    ifs.close();
    // cout << "Choose a year(0000-0000): ";
    // getline(cin, year);
    year=getYearStr(username);
    // cin.ignore();
    int semester=getSemesterNum();
    // cout << "Choose a semester(1->3): ";
    // cin >> semester;

    char ch_semester = static_cast<char>(semester + 48);
    string filename = user->student_class.class_name + "_Semester" + ch_semester + "_" + year +  "_courses.csv";
    filename = "../Txt_Csv/" + filename;
    Course *class_course = nullptr;
    Course *temp = nullptr;
    ifs.open(filename);
    if (!ifs.is_open())
    {
        // cout << "Input invalid\n";
        // cout << "Please input again:\n";
        // cout << "Choose a year(0000-0000): ";
        // getline(cin, year);
        // cin.ignore();
        // cout << "Choose a semester(1->3): ";
        // cin >> semester;
        system("cls");
        system("color E0");
        Create_A_Box_1(1, 7, 2, 35, 14, 14, 0, "INPUT INVALID! PLEASE INPUT AGAIN!");
        year=getYearStr(username);
        int semester=getSemesterNum();
        ch_semester = static_cast<char>(semester + 48);
        filename = user->student_class.class_name + "_Semester" + ch_semester + "_" + year +  "_courses.csv";
        filename = "../Txt_Csv/" + filename;
        ifs.open(filename);
    }
    string line;
    while (getline(ifs, line))
    {
        Course* new_course = new Course;
        string tmp;
        stringstream ss(line);
        getline(ss, tmp, ',');
        new_course->course_ID = tmp;
        getline(ss, tmp, ',');
        new_course->course_name = tmp; 
        getline(ss, tmp, ','); 
        new_course->class_name = tmp;
        getline(ss, tmp, ',');
        new_course->teacher_name = tmp;
        getline(ss, tmp, ',');
        new_course->numCredits = stoi(tmp);
        getline(ss, tmp, ',');
        new_course->maxNumStudents = stoi(tmp);
        getline(ss, tmp, ',');
        new_course->dayInWeek = tmp;
        getline(ss, tmp, '\n');

        new_course->Session = tmp;
        new_course->student_head = nullptr;
        new_course->scoreboard_head = nullptr;
        new_course->course_next = nullptr;

        if (!class_course)
        {
            class_course = new_course;
            temp = class_course;
        }
        else
        {
            temp->course_next = new_course;
            temp = temp->course_next;
        }
    }
    ifs.close();
    // cout << setw(12) << left << "Courses" << setw(16) << right << "Midterm Mark" 
    //     << setw(16) << right << "Final Mark" << setw(16) << right << "Other Mark" 
    //     << setw(16) << right << "Total Mark" << "\n";
    gotoXY(24, 1); cout <<"   _____  _____  _____ ______  _____ ______  _____   ___  ______ ______";
    gotoXY(24, 2); cout <<"  /  ___|/  __ \\|  _  || ___ \\|  ___|| ___ \\|  _  | / _ \\ | ___ \\|  _  \\";
    gotoXY(24, 3); cout <<"  \\ `--. | /  \\/| | | || |_/ /| |__  | |_/ /| | | |/ /_\\ \\| |_/ /| | | |";
    gotoXY(24, 4); cout <<"   `--. \\| |    | | | ||    / |  __| | ___ \\| | | ||  _  ||    / | | | |";
    gotoXY(24, 5); cout <<"  /\\__/ /| \\__/\\\\ \\_/ /| |\\ \\ | |___ | |_/ /\\ \\_/ /| | | || |\\ \\ | |/ /";
    gotoXY(24, 6); cout <<"  \\____/  \\____/ \\___/ \\_| \\_|\\____/ \\____/  \\___/ \\_| |_/\\_| \\_||___/";
    // string student_id, fullname;
    // float total, final1, midterm, other;
    Course *check = class_course;
    int y=8;
    int y_coord=1;
    while (check!=nullptr)
    {
        // cout << setw(12) << left << class_course->course_name;
        string filename1;
        filename1 = check->course_ID + "_Semester" + ch_semester + "_" + year + "_Scoreboard.csv";
        filename1 = "../Txt_Csv/" + filename1;
        ifstream ifs;
        ifs.open(filename1);
        Create_A_Box_1(1, y, 2, check->course_name.size()+1, 14, 14, 0, check->course_name);
        // ifs.open("../Txt_Csv/" + class_course->course_ID + "_Semester" + ch_semester + "_" + year + "_Scoreboard.csv");
        int counter = 0;
        string student_id, fullname;
        float total, final1, midterm, other;
        getline(ifs, dummy);
        string check2ndLine;
        getline(ifs, check2ndLine);
        if (check2ndLine == "")
        {
            
            Create_A_Box_1(1, y_coord+10, 2, 30, 14, 14, 0, "THERE IS NO AVAILABLE VALUE!");
            y_coord=y_coord+3;
        }
        ifs.close();
        ifs.open(filename1);
        getline(ifs, dummy);
        string temp;
        bool checkAvailable = false;
        while (!ifs.eof())
        {
            getline(ifs, student_id, ',');
            if (student_id == username)
            {
                checkAvailable = true;
                getline(ifs, fullname, ',');
                getline(ifs, temp, ',');
                midterm = stof(temp);
                getline(ifs, temp, ',');
                final1 = stof(temp);
                getline(ifs, temp, ',');
                other = stof(temp);
                getline(ifs, temp, '\n');
                total = stof(temp);
                printStudentInfo(y_coord ,counter, student_id, fullname, midterm, final1, other, total);
                counter++;
                y_coord=y_coord+3;
                break;
            }
            else
                getline(ifs, dummy);
        }
        if (checkAvailable == false)
        {
            
            Create_A_Box_1(1, y_coord+10, 2, 30, 14, 14, 0, "THERE IS NO AVAILABLE VALUE!");
            y_coord=y_coord+3;
        }
        y=y_coord + 13;
        y_coord = y_coord + 6;
        ifs.close();
        check = check->course_next;
    }
    // cout << "0. Return back" << "\nYour input is: ";
    // int opt = 1;
    // cin >> opt;

    // while (opt != 0)
    // {
    //     cout << "Please input again: ";
    //     cin >> opt;
    // }
    Create_A_Box_1(1, y, 2, 14, 14, 14, 0, " RETURN BACK");
    SetColor1(15,0);
    for (int i = 1 + 1; i <= 14; ++i)
    {
        gotoXY(i, y + 1);
        std::cout << " ";
    }
    gotoXY(1 + 1, y + 1);
    std::cout << " RETURN BACK";
    ShowConsoleCursor(false);
    while (true)
    {
        if (_kbhit())
        {
            char c = _getch();
            if (c == ENTER)
            {
                break;
            }
        }
    }
    system("cls");
    deallocateCourses(class_course);
    Main_Student_Screen(username);
}