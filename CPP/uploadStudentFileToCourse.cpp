#include "../Header/Staff.h"
#include "../Header/Design.h"
void uploadStudentFileToCourse (string username, Year* year_head, Semester* semester_head, Course* course_head)
{
    gotoXY(67,2); std::cout << "    _    _ _____  _      ____          _____    ______ _____ _      ______ ";
    gotoXY(67,3); std::cout << "   | |  | |  __ \\| |    / __ \\   /\\   |  __ \\  |  ____|_   _| |    |  ____|";
    gotoXY(67,4); std::cout << "   | |  | | |__) | |   | |  | | /  \\  | |  | | | |__    | | | |    | |__   ";
    gotoXY(67,5); std::cout << "   | |  | |  ___/| |   | |  | |/ /\\ \\ | |  | | |  __|   | | | |    |  __|  ";
    gotoXY(67,6); std::cout << "   | |__| | |    | |___| |__| / ____ \\| |__| | | |     _| |_| |____| |____ ";
    gotoXY(67,7); std::cout << "    \\____/|_|    |______\\____/_/    \\_\\_____/  |_|    |_____|______|______|";

    string file_name;

    Create_A_Box_2(70,10,2,60,14,14,0,"ENTER FILE NAME:  ");
    Create_A_Box_1(40,20,2,20,14,14,0,"    RETURN BACK");
    ShowConsoleCursor(false);

    int x_temp = 70; int y_temp = 10; int y_old; int xp = x_temp; int yp = y_temp; int pos_user = 0; int pos_pass = 0;
    int count = 0;
    while (count < 1)
    {
        system("color E0");

        if (y_temp == 10)
        {
            gotoXY(xp + 2, yp + 1);
            ShowConsoleCursor(true);

            char c;
            while (true)
            {
                c = _getch();

                if (c == ENTER)
                {
                    if (file_name != "")
                        count++;
                    xp = 68;
                    yp = y_temp;
                    break;
                }
                else if (c == DOWN)
                {
                    ShowConsoleCursor(false);
                    y_old = y_temp;
                    y_temp = 20;
                    xp = x_temp + file_name.size();
                    yp = y_old;
                    break;
                }
                else if (c == BACKSPACE)
                {
                    if (file_name != "" && pos_user > 0)
                    {
                        std::cout << "\b \b";
                        file_name.pop_back();
                    }
                }
                else if (c == LEFT)
                {
                    int len = file_name.size();

                    if (pos_user > 0)
                    {
                        pos_user--;
                        gotoXY(x_temp + pos_user + 2, y_temp + 1);
                    }

                    continue;
                }
                else if (c == RIGHT)
                {
                    int len = file_name.size();

                    if (pos_user < len)
                    {
                        pos_user++;
                        gotoXY(x_temp + pos_user + 2, y_temp + 1);
                    }

                    continue;
                }
                else
                {
                    int len = file_name.size();

                    if (c >= 32 && c <= 126 && len < 26)
                    {
                        pos_user++;
                        file_name += c;
                        std::cout << c;
                    }
                }
            }
        }
        else
        {
            SetColor1(15,0);
            for (int i = 41; i <= 59; ++i)
            {
                gotoXY(i, y_temp + 1);
                std::cout << " ";
            }

            gotoXY(41, y_temp + 1);
            std::cout << "    RETURN BACK";


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
                    updateACourse(username, year_head, semester_head, course_head);
                    return;
                }
            }
        }
    }


    ifstream ifs;

    //Open file
    file_name = "../Txt_Csv/" + file_name;
    ifs.open (file_name);
    while (!ifs.is_open())
    {
        system("cls");
        gotoXY(67, 0); cerr << "ERROR: UNABLE TO OPEN FILE FOR READING\n\n";

        uploadStudentFileToCourse(username, year_head, semester_head, course_head);
        return;
    }

    Student* temp = nullptr;
    string line;
    getline(ifs, line);

    while (getline(ifs, line))
    {
        string tmp, tmp1; //Tmp1 is student ID, tmp is Class Name
        stringstream ss(line);

        getline(ss, tmp1, ',');
        getline(ss, tmp, ',');
        getline(ss, tmp, ','); 
        getline(ss, tmp, ',');
        getline(ss, tmp, ',');

        Year* year = nullptr;
        getdata(year);

        Year* temp_year = year;
        //Don't need to check if temp_year is nullptr because if you want to access course, you must go through year
        while (temp_year)
        {
            Class* temp_class = temp_year->class_head;

            //Find Class in Year
            if (!temp_class)
            {
                temp_year = temp_year->year_next;
                continue;
            }
            while (temp_class)
            {
                if (tmp == temp_class->class_name)
                    break;
                else
                    temp_class = temp_class->next_class;
            }
            if (!temp_class)
            {
                temp_year = temp_year->year_next;
                continue;
            }

            //Check Student in that class
            Student* temp_student = temp_class->student_head;
            if (!temp_student)
            {
                temp_year = temp_year->year_next;
                continue;
            }
            while (temp_student)
            {
                if (tmp1 == temp_student->student_ID)
                    break;
                else
                    temp_student = temp_student->student_next;
            }
            if (!temp_student)
            {
                temp_year = temp_year->year_next;
                continue;
            }

            if (!course_head->student_head)
            {
                course_head->student_head = temp_student;
                temp = course_head->student_head;
            }
            else
            {
                temp->student_next = temp_student;
                temp = temp->student_next;
            }

            if (!temp_student->course_head)
                temp_student->course_head = course_head;
            else
            {
                Course* temp_course = temp_student->course_head;

                while (temp_course->course_next)
                    temp_course = temp_course->course_next;

                temp_course->course_next = course_head;
            }
        }

        if (!temp_year)
        {
            deletedata(year);
            system("cls");
            gotoXY(67, 0); cout << "YOUR INPUT FILE INCLUDES A STUDENT WHICH DOES NOT EXIST, PLEASE CHECK AGAIN\n";
            uploadStudentFileToCourse(username, year_head, semester_head, course_head);
            return;
        }
    }

    //Close file
    ifs.close();

    string name_file = course_head->course_ID + "_Semester" + (char)(semester_head->Semester_Ord + 48) + "_" + year_head->year_name + ".csv";
    const char* newfilename = file_name.c_str();
    const char* newname = name_file.c_str();
    remove(newfilename);
    rename(newfilename, newname);

    //Require user input 0 for returning back
    gotoXY(67,15); cout << "YOU UPLOADED STUDENT LIST SUCCESSFULLY";
    bool flag = true;
    while (true)
    {
        if (_kbhit())
        {
            char c = _getch();
            system("color E0");
            SetColor1(15,0);
            gotoXY(41,20 + 1); 
            std::cout << "    RETURN BACK";
            if (c == 13)
            {
                system("cls");
                updateACourse(username, year_head, semester_head, course_head);
                return;
            }
        }
    }
}