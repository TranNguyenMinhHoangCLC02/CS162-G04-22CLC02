#include "../Header/Staff.h"

void uploadStudentFileToCourse (string username, Year* year_head, Semester* semester_head, Course* course_head)
{
    cout << "(You can input 0 for returning back)" << "\n\n";

    string file_name;
    cin.ignore();
    cout << "Name of file for uploading: ";
    getline(cin, file_name);

    if (file_name == "0")
    {
        system("cls");
        accessCourse(username, year_head, semester_head, course_head);
        return;
    }

    ifstream ifs;

    //Open file
    file_name = "../Txt_Csv/" + file_name;
    ifs.open (file_name);
    while (!ifs.is_open())
    {
        system("cls");
        cerr << "Error: Unable to open file for reading. Try to input again!\n\n";

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

        Year* temp_year = getYearListFromFile();
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
            system("cls");
            cout << "Your input file includes a student which does not exist, please check again (you can input 0 for returning back)";

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
    string option;
    cout << "\n" << "You uploaded successfully, please input 0 for returning back: ";
    getline(cin, option);

    while (option != "0")
    {
        cout << "The number is different from 0, please input again: ";
        getline(cin, option);
    }

    accessCourse(username, year_head, semester_head, course_head);
}