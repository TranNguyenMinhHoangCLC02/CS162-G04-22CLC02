#include "../Header/Staff.h"
#include "../Header/Design.h"

void addTailCourse(Course* &course_head, Course* tmp)
{
    if (course_head == nullptr)
        course_head = tmp;
    else
    {
        Course* cur = course_head;
        while (cur->course_next != nullptr)
            cur = cur->course_next;
        cur->course_next = tmp; 
    }
}

Course* findCoursebyID(Course* course_head, string courseid, string nameclass)
{
    Course* tmp = course_head;
    while (tmp != nullptr)
    {
        if (tmp->course_ID == courseid && tmp->class_name == nameclass)
            return tmp;
        tmp = tmp->course_next;
    }
    return nullptr;
}
void removeCourseFromList(Course* &course_head, string courseid, string nameclass)
{
    Course* cur = course_head;
    Course* pre = nullptr;
    while (cur != nullptr && (cur->course_ID != courseid || cur->class_name !=nameclass ))
    {
        pre = cur;
        cur = cur->course_next;
    }
    if (cur ==  nullptr)
        return;
    else
    {
        if (pre == nullptr)
            course_head = cur->course_next;
        else
            pre->course_next = cur->course_next;
        delete cur;
    }
}

Course* getCourseFromFile(string filename)
{
    ifstream ifs;
    ifs.open(filename);
    if (!ifs.is_open())
    {
        // cerr << "Error: Unable to open file for reading\n";
        Create_A_Box_1(1, 1, 2, 41, 14, 14, 0, "Error: Unable to open file for reading");
        return nullptr;
    }

    Course* course_head = nullptr;
    string line;

    // Get data from file
    while (getline(ifs,line))
    {
        Course* new_course = new Course;
        stringstream ss(line);
        getline(ss, new_course->course_ID, ',');
        getline(ss, new_course->course_name, ',');
        getline(ss, new_course->class_name, ',');
        getline(ss, new_course->teacher_name, ',');
        string numCre, maxStu;
        getline(ss, numCre, ',');
        getline(ss, maxStu, ',');
        new_course->numCredits = stoi(numCre);
        new_course->maxNumStudents = stoi(maxStu);
        getline(ss, new_course->dayInWeek, ',');
        getline(ss, new_course->Session, '\n');
        new_course->scoreboard_head = nullptr;
        new_course->student_head = nullptr;
        new_course->course_next = nullptr;

        addTailCourse(course_head, new_course);
    }
    
    ifs.close();
    return course_head;
}

void deleteCoursefromFile(string filename, string courseid, string nameclass) 
{
    ifstream fin(filename); // Open the file for reading
    ofstream fout("temp.txt"); // Open a temporary file for writing

    Course* tmp = getCourseFromFile(filename);
    removeCourseFromList(tmp, courseid, nameclass);


    
    while (tmp != nullptr) 
    {
        fout << tmp->course_ID << "," << tmp->course_name << ","
             << tmp->class_name << "," << tmp->teacher_name << ","
             << tmp->numCredits << "," << tmp->maxNumStudents << "," 
             << tmp->dayInWeek << "," << tmp->Session << "\n";
        tmp = tmp->course_next;
    }

    fin.close(); // Close the input file
    fout.close(); // Close the temporary file
    
    remove(filename.c_str()); // Delete the original file
    rename("temp.txt", filename.c_str()); // Rename the temporary file to the original filename
}

void deleteCourse(string username, Semester *semester_head, Year* year_head) 
{
    int option;
    // cout<< "Are you sure you want to delete?";
    Create_A_Box_1(1, 1, 2, 34, 14, 14, 0, "ARE YOU SURE YOU WANT TO DELETE?");
    // cin>> option;
    // while (option != 0 && option != 1){
    //         cout << "Invalid input. Please enter again: ";
    //         cin >> option;
    //     }        
    // if (option == 0)
    //     return;
    Create_A_Box_1(1, 4, 2, 4, 14, 14, 0, "YES");
    Create_A_Box_1(1, 8, 2, 3, 14, 14, 0, "NO");
    int x_temp = 1; int y_temp = 4;
    bool flag=true;
    while (true)
    {
        if (flag == true)
        {
            if (y_temp == 4)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 4; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "YES";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 8)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 4; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                cout << " NO";
                ShowConsoleCursor(false);
            }
        }
        if (_kbhit())
        {
            char c=_getch();
            system("color E0");
            if (y_temp == 4)
            {
                system("color E0");
                SetColor1(14,0);
                for (int i = x_temp + 1; i <= x_temp + 4; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "YES";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 8)
            {
                system("color E0");
                SetColor1(14,0);
                for (int i = x_temp + 1; i <= x_temp + 4; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                cout << " NO";
                ShowConsoleCursor(false);
            }
            flag=true;
            if (c == UP)
            {
                if (y_temp == 4)
                    y_temp = 8;
                else
                    y_temp -= 4;
            }
            else if (c == DOWN)
            {
                if (y_temp == 8)
                    y_temp == 4;
                else
                    y_temp += 4;
            }
            else if (c == ENTER)
            {
                ShowConsoleCursor(true);
                if (y_temp == 4)
                    option = 1;
                else if (y_temp == 8)
                    option = 0;
                break;
            }
        }
    }
    if (option == 0)
    {
        system("cls");
        viewUpdateCourseInformation (username, year_head, semester_head);
        return;
    }
    system("cls");
    system("color E0");
    // Delete Course in Semester
    // string courseid, nameclass;
    // cout<< "Input CourseID of Course that will remove:";
    // cin >> courseid;
    // cout << "Input Nameclass of Course that will remove:";
    // cin >> nameclass;
    int counter=0;
    Create_A_Box_2(1,2,2,50,14,14,0,"Input CourseID of Course that will be removed");
    Create_A_Box_2(1,6,2,50,14,14,0,"Input Nameclass of Course that will be removed");
    ShowConsoleCursor(false);
    string courseid="";
    string classname="";
    int opt;
    x_temp = 1; y_temp = 2; int y_old; int xp = x_temp; int yp = y_temp; int pos_id = 0; int pos_class = 0;
    while (counter < 2)
    {
        system("color E0");

        if (y_temp == 2)
        {
            gotoXY(xp + 2, yp + 1);
            ShowConsoleCursor(true);

            char c;
            while (true)
            {
                c = _getch();

                if (c == ENTER)
                {
                    if (courseid != "")
                        counter++;

                    if (classname == "")
                        y_temp = 6;
                    xp = 1;
                    yp = y_temp;
                    break;
                }
                else if (c == BACKSPACE)
                {
                    if (courseid != "" && pos_id > 0)
                    {
                        std::cout << "\b \b";
                        courseid.pop_back();
                    }
                }
                else if (c == LEFT)
                {
                    if (pos_id > 0)
                    {
                        pos_id--;
                        gotoXY(x_temp + pos_id + 2, y_temp + 1);
                    }

                    continue;
                }
                else if (c == RIGHT)
                {
                    int len = courseid.size();

                    if (pos_id < len)
                    {
                        pos_id++;
                        gotoXY(x_temp + pos_id + 2, y_temp + 1);
                    }

                    continue;
                }
                else
                {
                    int len = courseid.size();

                    if (c >= 32 && c <= 126 && len < 26)
                    {
                        pos_id++;
                        courseid += c;
                        std::cout << c;
                    }
                }
            }
        }
        else if (y_temp == 6)
        {
            gotoXY(xp + 2, yp + 1);
            ShowConsoleCursor(true);

            char c;
            while (true)
            {
                c = _getch();

                if (c == ENTER)
                {
                    if (classname != "")
                        counter++;

                    if (courseid == "")
                        y_temp = 2;

                    xp = 1;
                    yp = y_temp;
                    break;
                }
                else if (c == BACKSPACE)
                {
                    if (classname != "" && pos_class > 0)
                    {
                        std::cout << "\b \b";
                        classname.pop_back();
                    }
                }
                else if (c == LEFT)
                {
                    if (pos_class > 0)
                    {
                        pos_class--;
                        gotoXY(x_temp + pos_class + 2, y_temp + 1);
                    }

                    continue;
                }
                else if (c == RIGHT)
                {
                    int len = classname.size();

                    if (pos_class < len)
                    {
                        pos_class++;
                        gotoXY(x_temp + pos_class + 2, y_temp + 1);
                    }

                    continue;
                }
                else
                {
                    int len = classname.size();

                    if (c >= 32 && c <= 126 && len < 26)
                    {
                        pos_class++;
                        classname += c;
                        std::cout << c;
                    }
                }
            }
        }
    }

    Course* course = findCoursebyID(semester_head->course_head,courseid, classname);
    Course *cur = semester_head->course_head;
    Course *pre = nullptr;
    while (cur != course)
    {
        pre = cur;
        cur = cur->course_next;
    }
    if (pre == nullptr)
        semester_head->course_head = semester_head->course_head->course_next;
    else 
        pre->course_next = cur->course_next;
    
    // // Delete Course in Course list
    // Course *curr = course_head;
    // Course *prev = nullptr;

    // // Search for the course in the list
    // while (curr != course) 
    // {
    //     prev = curr;
    //     curr = curr->course_next;
    // }

    // // Remove the course from the list
    // if (prev == nullptr)  // Case where the head node is the one to remove
    //     course_head = curr->course_next;
    // else
    //     prev->course_next = curr->course_next;

    // Remove the course from the enrolled courses list of all students
    // Student *student_ptr = curr->student_head;
    // while (student_ptr != nullptr) 
    // {
    //     Course *enrolled_course_ptr = student_ptr->course_head;
    //     Course *enrolled_course_prev = nullptr;

    //     while (enrolled_course_ptr != nullptr && enrolled_course_ptr != curr) 
    //     {
    //         enrolled_course_prev = enrolled_course_ptr;
    //         enrolled_course_ptr = enrolled_course_ptr->course_next;
    //     }

    //     if (enrolled_course_ptr == curr) 
    //     {
    //         if (enrolled_course_prev == nullptr)
    //             student_ptr->course_head = enrolled_course_ptr->course_next;
    //         else
    //             enrolled_course_prev->course_next = enrolled_course_ptr->course_next;
    //     }

    //     student_ptr = student_ptr->student_next;
    // }

    // Delete the course node
    delete cur;
    // delete curr;

    // Delete course from file
    //Open file
    string file_name = year_head->year_name + "_semester" + (char)(semester_head->Semester_Ord + 48) + "_course.csv";
    file_name = "../Txt_Csv/" + file_name;
    deleteCoursefromFile(file_name, courseid, classname);

    string file_name2 = course->course_ID + "_Semester" + (char)(semester_head->Semester_Ord + 48) + "_" + year_head->year_name + ".csv";
    file_name2 = "../Txt_Csv/" + file_name;
    remove(file_name2.c_str());
    system("cls");
    viewUpdateCourseInformation (username, year_head, semester_head);
    return;
}