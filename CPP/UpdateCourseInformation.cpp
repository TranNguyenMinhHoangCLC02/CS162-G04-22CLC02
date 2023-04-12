#include "../Header/Staff.h"

void updateCourseID (string username, Year* year_head, Semester* semester_head, Course* accessed_course)
{
    //Rules for changing Course ID information
    cout << "1. With course ID information, your input must include only capital letters and numbers, other letters are not allowed\n";
    cout << "2. You can input 0 for returning back\n\n";

    string input;
    cin.ignore();
    cout << "Please input new information for course ID (inputting 0 for returning back): ";
    getline (cin, input);

    while (!checkCourseID(input))
    {
        cout << "Your input includes at least 1 character that is not a capital letter or number, please input again: ";
        getline(cin, input);
    }

    if (input == "0")
    {
        system("cls");
        updateInformationOfCourse(username, year_head, semester_head, accessed_course);
        return;
    }

    cout << "\n";
    cout << "You updated successfully!\n\n";

    accessed_course->course_ID = input;

    string opt;
    cout << "Please input 0 for returning back: ";
    getline(cin, opt);

    while (opt != "0")
    {
        cout << "The number is different from 0, please input again: ";
        getline(cin, opt);
    }

    system("cls");
    updateInformationOfCourse(username, year_head, semester_head, accessed_course);
}

void updateCourseName (string username, Year* year_head, Semester* semester_head, Course* accessed_course)
{
    cout << "(You can input 0 for returning back)\n\n";

    //Input new info
    string input;
    cin.ignore();
    cout << "Please input new information for course name (inputting 0 for returning back): ";
    getline (cin, input);

    if (input == "0")
    {
        system("cls");
        updateInformationOfCourse(username, year_head, semester_head, accessed_course);
        return;
    }

    //Normalize the style of user's input
    accessed_course->course_name = Normalization(input);

    cout << "\n";
    cout << "You updated successfully!\n\n";

    string opt;
    cout << "Please input 0 for returning back: ";
    getline(cin, opt);

    while (opt != "0")
    {
        cout << "The number is different from 0, please input again: ";
        getline(cin, opt);
    }

    system("cls");
    updateInformationOfCourse(username, year_head, semester_head, accessed_course);
}

void updateClassName(string username, Year* year_head, Semester* semester_head, Course* accessed_course)
{
    cout << "(You can input 0 for returning back)\n\n";

    //Input new info
    string input;
    cin.ignore();
    cout << "Please input new information for class name (inputting 0 for returning back): ";
    getline (cin, input);

    while (!checkClassName(input))
    {
        cout << "Your input includes at least 1 character that is not a capital letter or number, please input again: ";
        getline(cin, input);
    }

    if (input == "0")
    {
        system("cls");
        updateInformationOfCourse(username, year_head, semester_head, accessed_course);
        return;
    }

    accessed_course->class_name = input;

    cout << "\n";
    cout << "You updated successfully!\n\n";

    string opt;
    cout << "Please input 0 for returning back: ";
    getline(cin, opt);

    while (opt != "0")
    {
        cout << "The number is different from 0, please input again: ";
        getline(cin, opt);
    }

    system("cls");
    updateInformationOfCourse(username, year_head, semester_head, accessed_course);
}

void updateTeacherName (string username, Year* year_head, Semester* semester_head, Course* accessed_course)
{
    cout << "(You can input 0 for returning back)\n\n";

    string input;
    cin.ignore();
    cout << "Please input new information for teacher name (inputting 0 for returning back): ";
    getline(cin, input);

    while (!checkTeacherName(input))
    {
        cout << "Your input includes at least 1 character that is not a letter or a space, please input again: ";
        getline(cin, input);
    }

    if (input == "0")
    {
        system("cls");
        updateInformationOfCourse(username, year_head, semester_head, accessed_course);
        return;
    }

    accessed_course->teacher_name = Normalization(input);

    cout << "\n";
    cout << "You updated successfully!\n\n";

    string opt;
    cout << "Please input 0 for returning back: ";
    getline(cin, opt);

    while (opt != "0")
    {
        cout << "The number is different from 0, please input again: ";
        getline(cin, opt);
    }

    system("cls");
    updateInformationOfCourse(username, year_head, semester_head, accessed_course);
}

void updateNumCredits (string username, Year* year_head, Semester* semester_head, Course* accessed_course)
{
    cout << "(You can input 0 for returning back)\n\n";

    int input;
    cout << "Please input new information for the number of credits (inputting 0 for returning back): ";
    cin >> input;

    if (input == 0)
    {
        system("cls");
        updateInformationOfCourse(username, year_head, semester_head, accessed_course);
        return;
    }

    accessed_course->numCredits = input;

    cout << "\n";
    cout << "You updated successfully!\n\n";

    string opt;
    cout << "Please input 0 for returning back: ";
    getline(cin, opt);

    while (opt != "0")
    {
        cout << "The number is different from 0, please input again: ";
        getline(cin, opt);
    }

    system("cls");
    updateInformationOfCourse(username, year_head, semester_head, accessed_course);
}

void updateMaxStudents (string username, Year* year_head, Semester* semester_head, Course* accessed_course)
{
    cout << "(You can input 0 for returning back)\n\n";

    int input;
    cout << "Please input new information for the maximum in the number of students (inputting 0 for returning back): ";
    cin >> input;

    if (input == 0)
    {
        system("cls");
        updateInformationOfCourse(username, year_head, semester_head, accessed_course);
        return;
    }

    accessed_course->maxNumStudents = input;

    cout << "\n";
    cout << "You updated successfully!\n\n";

    string opt;
    cout << "Please input 0 for returning back: ";
    getline(cin, opt);

    while (opt != "0")
    {
        cout << "The number is different from 0, please input again: ";
        getline(cin, opt);
    }

    system("cls");
    updateInformationOfCourse(username, year_head, semester_head, accessed_course);
}

void updateDayOfCourse (string username, Year* year_head, Semester* semester_head, Course* accessed_course)
{
    cout << "(You can input 0 for returning back)\n";

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
        updateInformationOfCourse(username, year_head, semester_head, accessed_course);
        return;
    }
    else
    {
        switch (DayOption)
        {
            case 1:
            {
                accessed_course->dayInWeek = "Monday";
                break;
            }
            case 2:
            {
                accessed_course->dayInWeek = "Tuesday";
                break;
            }
            case 3:
            {
                accessed_course->dayInWeek = "Wednesday";
                break;
            }
            case 4:
            {
                accessed_course->dayInWeek = "Thursday";
                break;
            }
            case 5:
            {
                accessed_course->dayInWeek = "Friday";
                break;
            }
            case 6:
            {
                accessed_course->dayInWeek = "Saturday";
                break;
            }
            case 7:
            {
                accessed_course->dayInWeek = "Sunday";
                break;
            }
        }
    }

    cout << "\n";
    cout << "You updated successfully!\n\n";

    string opt;
    cout << "Please input 0 for returning back: ";
    getline(cin, opt);

    while (opt != "0")
    {
        cout << "The number is different from 0, please input again: ";
        getline(cin, opt);
    }

    system("cls");
    updateInformationOfCourse(username, year_head, semester_head, accessed_course);
}

void updateSession (string username, Year* year_head, Semester* semester_head, Course* accessed_course)
{
    cout << "(You can input 0 for returning back)\n";

    showSessionOptions();

    int SessionOption;
    do
    {
        cout << "Please input new information for the course's session (inputting 0 for returning back): ";
        cin >> SessionOption;
    } while (SessionOption < 0 || SessionOption > 4);

    if (SessionOption == 0)
    {
        system("cls");
        updateInformationOfCourse(username, year_head, semester_head, accessed_course);
        return;
    }
    else
    {
        switch (SessionOption)
        {
            case 1:
            {
                accessed_course->Session = "7:30";
                break;
            }
            case 2:
            {
                accessed_course->Session = "9:30";
                break;
            }
            case 3:
            {
                accessed_course->Session = "13:30";
                break;
            }
            case 4:
            {
                accessed_course->Session = "15:30";
                break;
            }
        }
    }

    cout << "\n";
    cout << "You updated successfully!\n\n";

    string opt;
    cout << "Please input 0 for returning back: ";
    getline(cin, opt);

    while (opt != "0")
    {
        cout << "The number is different from 0, please input again: ";
        getline(cin, opt);
    }

    system("cls");
    updateInformationOfCourse(username, year_head, semester_head, accessed_course);
}

void updateInformationOfCourse (string username, Year* year_head, Semester* semester_head, Course* accessed_course)
{
    //Some rules for changing information
    //cout << "Principles when changing course's information\n";
    //cout << "1. With course ID information, your input must include only capital letters and numbers, other letters are not allowed\n";
    //cout << "2. You can input a number of option for choosing information in the day and the session of course\n";
    //cout << "3. Whenever you want to return back to the previous screen, you can input 0\n\n";

    //Show information of chosen course
    cout << "1. " << "Course ID: " << accessed_course->course_ID << "\n";
    cout << "2. " << "Course Name: " << accessed_course->course_name << "\n";
    cout << "3. " << "Class Name: " << accessed_course->class_name << "\n";
    cout << "4. " << "Teacher Name: " << accessed_course->teacher_name << "\n";
    cout << "5. " << "Number of Credits: " << accessed_course->numCredits << "\n";
    cout << "6. " << "Maximum Number of Students: " << accessed_course->maxNumStudents << "\n";
    cout << "7. " << "Day In Week: " << accessed_course->dayInWeek << "\n";
    cout << "8. " << "Session: " << accessed_course->Session << "\n";

    cout << "\n";

    //If users don't want to manipulate with this page, they can return back
    cout << "0. Return back" << "\n\n";

    //Allow users to input their option
    int option;
    do
    {
        cout << "Please input your option: ";
        cin >> option;
    } while (option < 0 || option > 8);

    switch (option)
    {
        case 0:
        {
            //Open file for updating information
            ofstream ofs;
            string file_name = year_head->year_name + "_semester" + (char)(semester_head->Semester_Ord + 48) + "_course.csv";
            file_name = "../Txt_Csv/" + file_name;
            ofs.open(file_name);
            if (!ofs.is_open())
            {
                cerr << "Error: Unable to open file for reading\n";
                return;
            }

            Course* temp = semester_head->course_head;
            while (temp)
            {
                ofs << temp->course_ID << "," << temp->course_name << "," << temp->class_name << "," 
                    << temp->teacher_name << "," << temp->numCredits << "," << temp->maxNumStudents 
                    << "," << temp->dayInWeek << "," << temp->Session << "\n";

                temp = temp->course_next;
            }
            ofs.close();

            system("cls");
            viewUpdateCourseInformation(username, year_head, semester_head);
            return;
        }

        case 1:
        {
            system("cls");
            updateCourseID(username, year_head, semester_head, accessed_course);
            break;
        }

        case 2:
        {
            system("cls");
            updateCourseName(username, year_head, semester_head, accessed_course);
            break;
        }

        case 3:
        {
            system("cls");
            updateClassName(username, year_head, semester_head, accessed_course);
            break;
        }

        case 4:
        {
            system("cls");
            updateTeacherName(username, year_head, semester_head, accessed_course);
            break;
        }

        case 5:
        {
            system("cls");
            updateNumCredits(username, year_head, semester_head, accessed_course);
            break;
        }

        case 6:
        {
            system("cls");
            updateMaxStudents(username, year_head, semester_head, accessed_course);
            break;
        }

        case 7:
        {
            system("cls");
            updateDayOfCourse(username, year_head, semester_head, accessed_course);
            break;
        }

        case 8:
        {
            system("cls");
            updateSession(username, year_head, semester_head, accessed_course);
            break;
        }
    }
}