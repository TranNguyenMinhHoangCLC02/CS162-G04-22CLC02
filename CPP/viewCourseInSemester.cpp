#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

void viewCoursesInSemester(string username)
{
    system("cls");
    resizeConsole(1920,920);
    system("color E0");

    string year;
    Student *user = new Student();
    ifstream ifs;
    ifs.open("../Txt_Csv/student_info.csv");
    string dummy;
    getline(ifs, dummy);
    
    string first_line;
    while (getline(ifs, first_line))
    {
        string temp;
        stringstream ss(first_line);

        getline(ss, temp, ',');
        if (temp == username)
        {
            user->student_ID = temp;
            getline(ss, temp, ',');
            user->student_socialID = temp;
            getline(ss, temp, ',');
            user->student_fisrtname = temp;
            getline(ss, temp, ',');
            user->student_lastname = temp;
            getline(ss, temp, ',');
            user->gender = stoi(temp);
            getline(ss, temp, ',');
            user->student_class.class_name = temp;
            getline(ss, temp, '\n');
            getDate(user, temp);
            break;
        }
    }
    ifs.close();

    year = getYearStr(username);
    int semester = getSemesterNum();

    char ch_semester = static_cast<char>(semester + 48);
    string filename = user->student_class.class_name + "_Semester" + ch_semester + "_" + year +  "_courses.csv";
    filename = "../Txt_Csv/" + filename;

    Course *class_course = nullptr;
    Course *temp = nullptr;

    ifs.open(filename);
    if (!ifs.is_open())
    {
        system("cls");
        system("color E0");
        Create_A_Box_1(1, 7, 2, 35, 14, 14, 0, "INPUT INVALID! PLEASE INPUT AGAIN!");
        year = getYearStr(username);
        int semester = getSemesterNum();
        ch_semester = static_cast<char>(semester + 48);
        filename = user->student_class.class_name + "_Semester" + ch_semester + "_" + year +  "_courses.csv";
        filename = "../Txt_Csv/" + filename;
        ifs.open(filename);
    }

    string second_line;
    while (getline(ifs, second_line))
    {
        Course* new_course = new Course;
        string tmp;
        stringstream ss(second_line);

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

    gotoXY(55,2); std::cout <<"     _____ ____  _    _ _____   _____ ______ ";
    gotoXY(55,3); std::cout <<"    / ____/ __ \\| |  | |  __ \\ / ____|  ____|";
    gotoXY(55,4); std::cout <<"   | |   | |  | | |  | | |__) | (___ | |__   ";
    gotoXY(55,4); std::cout <<"   | |   | |  | | |  | |  _  / \\___ \\|  __|  ";
    gotoXY(55,5); std::cout <<"   | |___| |__| | |__| | | \\ \\ ____) | |____ ";
    gotoXY(55,6); std::cout <<"    \\_____\\____/ \\____/|_|  \\_\\_____/|______|";
    
    Course *check = class_course;
    //int y = 8;
    int counter = 1;
    int i = 0;
    int numCourses = 0;
    Course* acceptCourse = nullptr;
    Course* tmp = nullptr;

    while (check != nullptr)
    {
        string filename1;
        filename1 = check->course_ID + "_Semester" + ch_semester + "_" + check->class_name + "_" + year + "_student.csv";
        filename1 = "../Txt_Csv/" + filename1;
        ifstream ifs;
        string student_id;
        ifs.open(filename1);
        getline(ifs, dummy);
        
        string third_line;
        while (getline(ifs, third_line))
        {
            stringstream ss(third_line);
            getline(ss, student_id, ',');
            if (student_id == username)
            {
                Course* tmpCourse = new Course;
                tmpCourse->course_ID = check->course_ID;
                tmpCourse->course_name = check->course_name;
                
                tmpCourse->student_head = nullptr;
                tmpCourse->scoreboard_head = nullptr;
                tmpCourse->course_next = nullptr;

                if (acceptCourse == nullptr)
                {
                    acceptCourse = tmpCourse;
                    tmp = acceptCourse;
                }
                else 
                {
                    tmp->course_next = tmpCourse;
                    tmp = tmp->course_next;
                }
                numCourses += 2;
                break;
            }
            else
                getline(ss, dummy);
        }
        ifs.close();
        check = check->course_next;
    }

    if (acceptCourse == nullptr)
    {
        Create_A_Box_1(55,12,2,30,14,14,0,"    There are no course!");
    }
    Course *curr = acceptCourse;
    Create_A_Box_1(55, 12, numCourses, 40, 14, 14, 0, "");
    while(curr)
    {
        gotoXY(57, 13 + i);
        std:: cout<< counter <<". " << check->course_ID<< " - " << check->course_name;
        i += 2;
        counter ++; 
    }

    Create_A_Box_1(130, 35, 2, 14, 14, 14, 0, " RETURN BACK");
    SetColor1(15,0);
    for (int i = 131; i <= 143; ++i)
    {
        gotoXY(i, 36);
        std::cout << " ";
    }
    gotoXY(131, 36);
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
