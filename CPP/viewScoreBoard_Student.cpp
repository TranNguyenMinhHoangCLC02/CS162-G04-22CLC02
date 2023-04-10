#include "../Header/Staff.h"
#include "../Header/Student.h"

void viewScoreBoard_Student(string username)
{
    string year;
    Student *user = new Student();
    ifstream ifs;
    ifs.open("student_info.csv");
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
    cout << "Choose a year(0000-0000): ";
    getline(cin, year);
    cin.ignore();
    int semester;
    cout << "Choose a semester(1->3): ";
    cin >> semester;
    char ch_semester = static_cast<char>(semester + 48);
    string filename = user->student_class.class_name + "_Semester" + ch_semester + "_" + year +  "_courses.csv";
    Course *class_course = nullptr;
    Course *temp = nullptr;
    ifs.open(filename);
    if (!ifs.is_open())
    {
        cout << "Input invalid\n";
        cout << "Please input again:\n";
        cout << "Choose a year(0000-0000): ";
        getline(cin, year);
        cin.ignore();
        cout << "Choose a semester(1->3): ";
        cin >> semester;
        ch_semester = static_cast<char>(semester + 48);
        filename = user->student_class.class_name + "_Semester" + ch_semester + "_" + year +  "_courses.csv";
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
    cout << setw(12) << left << "Courses" << setw(16) << right << "Midterm Mark" 
        << setw(16) << right << "Final Mark" << setw(16) << right << "Other Mark" 
        << setw(16) << right << "Total Mark" << "\n";
    string student_id, fullname;
    float total, final1, midterm, other;
    while (class_course!=nullptr)
    {
        cout << setw(12) << left << class_course->course_name;
        ifs.open(class_course->course_ID + "_Semester" + ch_semester + "_" + year + "_Scoreboard.csv");
        getline(ifs, dummy);
        while (!ifs.eof())
        {
            getline(ifs, student_id, ',');
            if (student_id==username)
            {
                getline(ifs, fullname, ',');
                getline(ifs, dummy, ',');
                midterm = stof(dummy);
                getline(ifs, dummy, ',');
                final1 = stof(dummy);
                getline(ifs, dummy, ',');
                other = stof(dummy);
                getline(ifs, dummy, '\n');
                total = stof(dummy);
                cout << setw(16) << right << fixed << setprecision(1) << midterm;
                cout << setw(16) << right << fixed << setprecision(1) << final1;
                cout << setw(16) << right << fixed << setprecision(1) << other;
                cout << setw(16) << right << fixed << setprecision(1) << total << "\n";
            }
            else
                getline(ifs, dummy);
        }
        class_course=class_course->course_next;
    }
    cout << "0. Return back" << "\n";
    int opt = 1;
    cin >> opt;

    while (opt != 0)
    {
        cout << "Please input again: ";
        cin >> opt;
    }
    system("cls");
    Main_Student_Screen(username);
}