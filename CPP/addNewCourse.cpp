#include "../Header/Staff.h"

//Check Validation of course ID
bool checkCourseID (string Course_ID)
{
    if (Course_ID == "0")
        return true;

    int check = 1; int len = Course_ID.size();

    for (int i = 0; i < len; ++i)
    {
        if ((Course_ID[i] < '0' || Course_ID[i] > '9') && (Course_ID[i] < 'A' || Course_ID[i] > 'Z'))
        {
            check = 0;
            break;
        }
    }

    return check;
}

//Normalization
string Normalization (string input)
{
    int len = input.size();

    int index = 0;
    while (index < len && input[index] == ' ')
    {
        index++;
    }

    if (index == len)
        return "";

    string output = "";
    while (index < len)
    {
        if (output == "")
        {
            output += toupper(input[index]);
            index++;
        }
        else if (input[index - 1] == ' ')
        {
            output += toupper(input[index]);
            index++;
        }
        else
        {
            if (input[index] >= 'A' && input[index] <= 'Z')
            {
                output += (input[index] + 32);
                index++;
            }
            else if (input[index] == ' ')
            {
                output += input[index];

                while (index < len && input[index] == ' ')
                {
                    index++;
                }
            }
            else
            {
                output += input[index];
                index++;
            }
        }
    }

    return output;
}

//Check Class Name
bool checkClassName (string Class_Name)
{
    if (Class_Name == "0")
        return true;

    int len = Class_Name.size();

    for (int i = 0; i < len; ++i)
    {
        if ((Class_Name[i] < 'A' || Class_Name[i] > 'Z') && (Class_Name[i] < '0' || Class_Name[i] > '9'))
            return false;
    }

    return true;
}

//Check Teacher's Name
bool checkTeacherName (string Teacher_Name)
{
    if (Teacher_Name == "0")
        return true;

    int len = Teacher_Name.size();

    for (int i = 0; i < len; ++i)
    {
        if ((Teacher_Name[i] < 'a' || Teacher_Name[i] > 'z') && (Teacher_Name[i] < 'A' || Teacher_Name[i] > 'Z') && Teacher_Name[i] != ' ')
            return false;
    }

    return true;
}

void showDayOptions()
{
    cout << "\n";

    cout << "1. Monday\n";
    cout << "2. Tuesday\n";
    cout << "3. Wednesday\n";
    cout << "4. Thursday\n";
    cout << "5. Friday\n";
    cout << "6. Saturday\n";
    cout << "7. Sunday\n";

    cout << "\n";
}

void showSessionOptions()
{
    cout << "\n";
    
    cout << "1. S1(7:30)\n";
    cout << "2. S2(9:30)\n";
    cout << "3. S3(13:30)\n";
    cout << "4. S4(15:30)\n";

    cout << '\n';
}

void addNewCourse (string username, Year* year_head, Semester* semester_head)
{
    ofstream ofs;

    //Create new node for linked list course_head
    cout << "Principles when inputing a new course\n";
    cout << "1. With course ID information, your input must include only capital letters and numbers, other letters are not allowed\n";
    cout << "2. You can input a number of option for choosing information in the day and the session of course\n";
    cout << "3. Whenever you want to return back to the previous screen, you can input 0\n\n";

    //Input the ID of course
    string CourseID;
    cin.ignore();
    cout << "Course ID (inputting 0 for returning back): ";
    getline(cin, CourseID);

    //If user's input is wrong, input again
    while (!checkCourseID(CourseID))
    {
        cout << "Your input includes at least 1 character that is not a capital letter or number, please input again: ";
        getline(cin, CourseID);
    }

    if (CourseID == "0")
    {
        system("cls");
        accessSemester(username, year_head, semester_head);
        return;
    }
    else
    {
        //Input the name of course
        string CourseName;
        cout << "Course Name (inputting 0 for returning back): ";
        getline(cin, CourseName);

        if (CourseName == "0")
        {
            system("cls");
            accessSemester(username, year_head, semester_head);
            return;
        }
        else
        {
            CourseName = Normalization(CourseName);

            //Input the class having course
            string CourseClass;
            cout << "Class Name (inputting 0 for returning back): ";
            getline(cin, CourseClass);

            while (!checkClassName(CourseClass))
            {
                cout << "Your input includes at least 1 character that is not a capital letter or number, please input again: ";
                getline(cin, CourseClass);
            }

            if (CourseClass == "0")
            {
                system("cls");
                accessSemester(username, year_head, semester_head);
                return;
            }
            else
            {
                //Input the teacher teaching course
                string TeacherName;
                cout << "Teacher Name (inputting 0 for returning back): ";
                getline(cin, TeacherName);

                //If user's input is wrong, input again
                while (!checkTeacherName(TeacherName))
                {
                    cout << "Your input includes at least 1 character that is not a letter or a space, please input again: ";
                    getline(cin, TeacherName);
                }

                if (TeacherName == "0")
                {
                    system("cls");
                    accessSemester(username, year_head, semester_head);
                    return;
                }
                else
                {
                    TeacherName = Normalization(TeacherName);

                    //Input the class having course
                    int NumOfCredits;
                    cout << "Number of Credits (inputting 0 for returning back): ";
                    cin >> NumOfCredits;

                    if (NumOfCredits == 0)
                    {
                        system("cls");
                        accessSemester(username, year_head, semester_head);
                        return;
                    }
                    else
                    {
                        //Input the class having course
                        int MaximumStudents;
                        cout << "Maximum number of students (inputting 0 for returning back): ";
                        cin >> MaximumStudents;

                        if (MaximumStudents == 0)
                        {
                            system("cls");
                            accessSemester(username, year_head, semester_head);
                            return;
                        }
                        else
                        {
                            showDayOptions();

                            int DayOption;
                            do
                            {
                                cout << "Please input your option for the day of course in week (inputting 0 for returning back): ";
                                cin >> DayOption;
                            } while (DayOption < 0 || DayOption > 7);

                            if (DayOption == 0)
                            {
                                system("cls");
                                accessSemester(username, year_head, semester_head);
                                return;
                            }
                            else
                            {
                                showSessionOptions();

                                int SessionOption;
                                do
                                {
                                    cout << "Please input your option for the day of course in week (inputting 0 for returning back): ";
                                    cin >> SessionOption;
                                } while (SessionOption < 0 || SessionOption > 4);

                                if (SessionOption == 0)
                                {
                                    system("cls");
                                    accessSemester(username, year_head, semester_head);
                                    return;
                                }
                                else
                                {
                                    //Create new course
                                    Course* new_course = new Course;
                                    new_course->course_ID = CourseID;
                                    new_course->course_name = CourseName;
                                    new_course->class_name = CourseClass;
                                    new_course->teacher_name = TeacherName;
                                    new_course->numCredits = NumOfCredits;
                                    new_course->maxNumStudents = MaximumStudents;
                                    
                                    switch (DayOption)
                                    {
                                        case 1:
                                        {
                                            new_course->dayInWeek = "Monday";
                                            break;
                                        }
                                        case 2:
                                        {
                                            new_course->dayInWeek = "Tuesday";
                                            break;
                                        }
                                        case 3:
                                        {
                                            new_course->dayInWeek = "Wednesday";
                                            break;
                                        }
                                        case 4:
                                        {
                                            new_course->dayInWeek = "Thursday";
                                            break;
                                        }
                                        case 5:
                                        {
                                            new_course->dayInWeek = "Friday";
                                            break;
                                        }
                                        case 6:
                                        {
                                            new_course->dayInWeek = "Saturday";
                                            break;
                                        }
                                        case 7:
                                        {
                                            new_course->dayInWeek = "Sunday";
                                            break;
                                        }
                                    }

                                    switch (SessionOption)
                                    {
                                        case 1:
                                        {
                                            new_course->Session = "7:30";
                                            break;
                                        }
                                        case 2:
                                        {
                                            new_course->Session = "9:30";
                                            break;
                                        }
                                        case 3:
                                        {
                                            new_course->Session = "13:30";
                                            break;
                                        }
                                        case 4:
                                        {
                                            new_course->Session = "15:30";
                                            break;
                                        }
                                    }

                                    new_course->scoreboard_head = nullptr;
                                    new_course->student_head = nullptr;
                                    new_course->course_next = nullptr;

                                    //Add new course at the end of course list of corresponding year
                                    if (!semester_head->course_head)
                                        semester_head->course_head = new_course;
                                    else
                                    {
                                        Course* temp_course = semester_head->course_head;

                                        while (temp_course->course_next)
                                            temp_course = temp_course->course_next;

                                        temp_course->course_next = new_course;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    //Print course list after changed out file txt corresponding with the year and the semester including courses
    string file_name = year_head->year_name + "_semester" + (char)(semester_head->Semester_Ord + 48) + "_course.csv";
    file_name = "../Txt_Csv/" + file_name;
    ofs.open(file_name);
    if (!ofs.is_open())
    {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }

    Course* temp_course = semester_head->course_head;
    while (temp_course->course_next)
    {
        ofs << temp_course->course_ID << "," << temp_course->course_name << "," << temp_course->class_name << "," 
            << temp_course->teacher_name << "," << temp_course->numCredits << "," << temp_course->maxNumStudents 
            << "," << temp_course->dayInWeek << "," << temp_course->Session << "\n";
        
        temp_course = temp_course->course_next;
    }
    ofs << temp_course->course_ID << "," << temp_course->course_name << "," << temp_course->class_name << "," 
        << temp_course->teacher_name << "," << temp_course->numCredits << "," << temp_course->maxNumStudents 
        << "," << temp_course->dayInWeek << "," << temp_course->Session;
    ofs.close();
    
    // Create files for each classes
    Course *current_course = semester_head->course_head;
    while (current_course != nullptr)
    {
        string Class_name = current_course->class_name;
        char char_semester = static_cast<char>(semester_head->Semester_Ord + 48);
        string filename = Class_name + "_" + "Semester" + char_semester + "_" + year_head->year_name + "_courses.csv";
        filename = "../Txt_Csv/" + filename;
        ofstream ofs(filename, ios::app);
        if (!ofs.is_open())
        {
            cerr << "Error: Unable to open file " << filename << " for writing\n";
            return;
        }
        if (current_course->class_name == Class_name)
        {
            ofs << current_course->course_ID << "," << current_course->course_name << "," 
            << current_course->class_name << "," << current_course->teacher_name << "," 
            << current_course->numCredits << "," << current_course->maxNumStudents << "," 
            << current_course->dayInWeek << "," << current_course->Session << "\n";
        }
        ofs.close();
        current_course = current_course->course_next;
    }

    //Create file including students of created course
    Course* temp_course1 = semester_head->course_head;

    while (temp_course1->course_next)
        temp_course1 = temp_course1->course_next;

    string name_file = temp_course1->course_ID + "_Semester" + (char)(semester_head->Semester_Ord + 48) + "_" + year_head->year_name + "_Scoreboard.csv";
    name_file = "../Txt_Csv/" + name_file;
    ofs.open(name_file);
    if (!ofs.is_open())
    {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }
    ofs << "ID,FullName,Midterm,Final,Other,Total";
    ofs.close();

    //Announce for user
    cout << "You created a new course successfully!\n\n";

    //Require user input 0 for returning back
    string option;
    cin.ignore();
    cout << "Please type the number 0 for returning back: ";
    getline(cin, option);

    while (option != "0")
    {
        cout << "The number is different from 0, please input again: ";
        getline(cin, option);
    }

    system("cls");
    accessSemester(username, year_head, semester_head);
}