#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

string format_float(float value)
{
    stringstream ss;
    ss << fixed << setprecision(1) << value;
    return ss.str();
}

void printStudentInfo(int y, int counter, string student_id, string fullname, float midterm, float final1, float other, float total)
{
    gotoXY(1, y + 10);
    Create_A_Box_1(1, y + 10, 2, 5, 14 , 14, 0, to_string(counter+1));
    gotoXY(1, y + 10); cout << (char)218;
    Create_A_Box_1(6, y + 10, 2, 14, 14 , 14, 0, student_id);
    gotoXY(6, y + 10); cout << (char)194;
    gotoXY(6, y + 12); cout << (char)193;
    Create_A_Box_1(20, y + 10, 2, 60, 14, 14, 0, fullname);
    gotoXY(20, y + 10); cout << (char)194;
    gotoXY(20, y + 12); cout << (char)193;
    Create_A_Box_1(80, y + 10, 2, 10, 14, 14, 0, format_float(midterm));
    gotoXY(80, y + 10); cout << (char)194;
    gotoXY(80, y + 12); cout << (char)193;
    Create_A_Box_1(90, y + 10, 2, 10, 14, 14, 0, format_float(final1));
    gotoXY(90, y + 10); cout << (char)194;
    gotoXY(90, y + 12); cout << (char)193;
    Create_A_Box_1(99, y + 10, 2, 10, 14, 14, 0, format_float(other));
    gotoXY(99, y + 10); cout << (char)194;
    gotoXY(99, y + 12); cout << (char)193;
    Create_A_Box_1(109, y + 10, 2, 9, 14, 14, 0, format_float(total));
    gotoXY(109, y + 10); cout << (char)194;
    gotoXY(109, y + 12); cout << (char)193;
    return;
}

void viewScoreBoard_Course(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{
    system("cls");
    SetColor1(14, 0);
    gotoXY(24, 1); cout <<"   _____  _____  _____ ______  _____ ______  _____   ___  ______ ______";
    gotoXY(24, 2); cout <<"  /  ___|/  __ \\|  _  || ___ \\|  ___|| ___ \\|  _  | / _ \\ | ___ \\|  _  \\";
    gotoXY(24, 3); cout <<"  \\ `--. | /  \\/| | | || |_/ /| |__  | |_/ /| | | |/ /_\\ \\| |_/ /| | | |";
    gotoXY(24, 4); cout <<"   `--. \\| |    | | | ||    / |  __| | ___ \\| | | ||  _  ||    / | | | |";
    gotoXY(24, 5); cout <<"  /\\__/ /| \\__/\\\\ \\_/ /| |\\ \\ | |___ | |_/ /\\ \\_/ /| | | || |\\ \\ | |/ /";
    gotoXY(24, 6); cout <<"  \\____/  \\____/ \\___/ \\_| \\_|\\____/ \\____/  \\___/ \\_| |_/\\_| \\_||___/";
    gotoXY(24, 7); cout << "------------"<< course_head->course_name << "_" << year_head->year_name <<"--------------\n";
    Create_A_Box_1(1, 8, 2, 5, 14 , 14, 0, " No");
    gotoXY(1, 8); cout << (char)218;
    Create_A_Box_1(6, 8, 2, 14, 14 , 14, 0, " Student ID");
    gotoXY(6, 8); cout << (char)194;
    gotoXY(6, 10); cout << (char)193;
    Create_A_Box_1(20, 8, 2, 60, 14, 14, 0, "                       Fullname");
    gotoXY(20, 8); cout << (char)194;
    gotoXY(20, 10); cout << (char)193;
    Create_A_Box_1(80, 8, 2, 10, 14, 14, 0, " Midterm ");
    gotoXY(80, 8); cout << (char)194;
    gotoXY(80, 10); cout << (char)193;
    Create_A_Box_1(90, 8, 2, 10, 14, 14, 0, " Final ");
    gotoXY(90, 8); cout << (char)194;
    gotoXY(90, 10); cout << (char)193;
    Create_A_Box_1(99, 8, 2, 10, 14, 14, 0, " Other ");
    gotoXY(99, 8); cout << (char)194;
    gotoXY(99, 10); cout << (char)193;
    Create_A_Box_1(109, 8, 2, 9, 14, 14, 0, "  Total ");
    gotoXY(109, 8); cout << (char)194;
    gotoXY(109, 10); cout << (char)193;
    system("pause");
    ifstream ifs;   
    ifs.open(filename);
    if (!ifs.is_open())
    {
        gotoXY(1, 11);
        Create_A_Box_1(1, 11+10, 2, 14, 14, 14, 0, " RETURN BACK");
        SetColor1(15,0);
        for (int i = 1 + 1; i <= 14; ++i)
        {
            gotoXY(i, 11 + 11);
            std::cout << " ";
        }
        gotoXY(1 + 1, 11 + 11);
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
        system("E0");
        system("cls");
        accessCourse(username, year_head, semester_head, course_head);
        return;
    }
    string dummy;
    getline(ifs, dummy);
    int counter = 0;
    string student_id, fullname;
    float total, final1, midterm, other;
    string temp;
    int y=1;
    while (!ifs.eof())
    {
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
        printStudentInfo(y ,counter, student_id, fullname, midterm, final1, other, total);
        counter++;
        y=y+3;
    }
    ifs.close();
    Create_A_Box_1(1, y+10, 2, 14, 14, 14, 0, " RETURN BACK");
    SetColor1(15,0);
    for (int i = 1 + 1; i <= 14; ++i)
    {
        gotoXY(i, y + 11);
        std::cout << " ";
    }
    gotoXY(1 + 1, y + 11);
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
    system("E0");
    system("cls");
    accessCourse(username, year_head, semester_head, course_head);
    return;
}