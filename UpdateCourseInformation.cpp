#include "Staff.h"

void updateInformationOfCourse (string username, Year* year_head, Semester* semester_head, Course* accessed_course)
{
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
            system("cls");
            accessSemester(username, year_head, semester_head);
            return;
        }

        case 1:
        {
            cout << "Please input new information for course ID: ";
            getline (cin, accessed_course->course_ID);
            break;
        }

        case 2:
        {
            cout << "Please input new information for course name: ";
            getline (cin, accessed_course->course_name);
            break;
        }

        case 3:
        {
            cout << "Please input new information for class name: ";
            getline (cin, accessed_course->class_name);
            break;
        }

        case 4:
        {
            cout << "Please input new information for teacher name: ";
            getline (cin, accessed_course->teacher_name);
            break;
        }

        case 5:
        {
            cout << "Please input new information for the number of credits: ";
            cin >> accessed_course->numCredits;
            break;
        }

        case 6:
        {
            cout << "Please input new information for the maximum in the number of students: ";
            cin >> accessed_course->maxNumStudents;
            break;
        }

        case 7:
        {
            cout << "Please input new information for the day of course in week: ";
            getline (cin, accessed_course->dayInWeek);
            break;
        }

        case 8:
        {
            cout << "Please input new information for the course's session: ";
            getline (cin, accessed_course->Session);
            break;
        }
    }

    cout << "\n";
    cout << "You updated successfully! Please input 0 for returning back: ";

    string opt;
    cout << "Please type the number 0 for returning back: ";
    getline(cin, opt);

    while (opt != "0")
    {
        cout << "The number is different from 0, please input again: ";
        getline(cin, opt);
    }

    //Open file for updating information
    ofstream ofs;
    string file_name = year_head->year_name + "_semester" + (char)(year_head->semester_head->Semester_Ord + 48) + "_course.csv";
    ofs.open(file_name);
    if (!ofs.is_open())
    {
        cerr << "Error: Unable to open file for reading\n";
        return;
    }

    Course* temp = year_head->semester_head->course_head;
    while (temp)
    {
        convertTime_slot(temp);

        ofs << temp->course_ID << "," << temp->course_name << "," << temp->class_name << "," 
            << temp->teacher_name << "," << temp->numCredits << "," << temp->maxNumStudents 
            << "," << temp->dayInWeek << "," << temp->Session << "\n";
    }
    ofs.close();

    viewUpdateCourseInformation(username, year_head, semester_head);
}

void viewUpdateCourseInformation (string username, Year* year_head, Semester* semester_head)
{
    system("cls");
    cout << setw(2) << "------------UPDATE-COURSE-INFORMATION--------------\n";
    cout << "Please choose the course you have created you want to access for seeing information";
    
    Course* cur = year_head->semester_head->course_head; int numCourses = 0;

    //Show list of years the staff has created before
    if (cur == nullptr) //Data is empty
        cout << "\n" << "Oops, there is nothing for you to choose" << "\n";
    else
    {
        cout << "\n\n" << "Here are some semesters you created" << "\n";

        while (cur)
        {
            cout << numCourses + 1 << "\t" << setw(2) << right << cur->course_name << "-" << cur->course_ID << "_" << cur->class_name << "\n";
            cur = cur->course_next;
            numCourses++;
        }
    }
    cout << "\n";

    //If users don't want to manipulate with this page, they can return back
    cout << "0. Return back" << "\n";

    //Move the pointer cur to the pointer semester_head again
    cur = year_head->semester_head->course_head;

    if (cur)
    {
        //Allow users to input their option
        int option;
        do
        {
            cout << "Please input your option: ";
            cin >> option;
        } while (option < 0 || option > numCourses);

        if (option)
        {
            //Move it to the Node including suitable year
            for (int i = 0; i < option - 1; ++i)
            {
                cur = cur->course_next;
            }

            //Show some more options
            system("cls");
            updateInformationOfCourse(username, year_head, semester_head, cur);
            return;
        }
        else
        {
            system("cls");
            accessSemester(username, year_head, semester_head);
            return;
        }
    }

    string opt;
    cout << "Please type the number 0 for returning back: ";
    getline(cin, opt);

    while (opt != "0")
    {
        cout << "The number is different from 0, please input again: ";
        getline(cin, opt);
    }
    
    system("cls");
    accessSemester(username, year_head, semester_head);
}