#include "../Header/Staff.h"
#include "../Header/Student.h"

void viewScoreBoard_Class(string username, Year *&year_head, Class *class_head)
{
    string filename;
    int semester;
    cout << "Choose a semester (1->3): ";
    cin >> semester;
    while (semester<1 && semester>3)
    {
        cout << "Invalid input!";
        cout << "Please input again: ";
        cin >> semester;
    }
    char char_semester=static_cast<char>(semester+48);
    filename=class_head->class_name+ "_" + "Semester" + char_semester + "_" + year_head->year_name + "_courses.csv";
    Course *class_course=nullptr;
    Course *temp=nullptr;
    ifstream ifs;
    ifs.open(filename);
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
    Course *check=class_course;
    while (check!=nullptr)
    {
        string filename1;
        filename1=check->course_ID+ "_Semester" + char_semester + "_" + year_head->year_name +"_Scoreboard.csv";
        ifstream ifs;
        ifs.open(filename1);
        cout << "------------"<< check->course_name <<"--------------\n";
        int counter=1;
        string student_id, fullname;
        float total, final1, midterm, other;
        string dummy;
        getline(ifs,dummy);
        string temp;
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
            cout << setw(3) << right << "No." << counter << " ";
            cout << setw(10) << left << student_id << " ";
            cout << setw(25) << left << fullname << " ";
            cout << setw(5) << right << fixed << setprecision(1) << midterm << " ";
            cout << setw(5) << right << fixed << setprecision(1) << final1 << " ";
            cout << setw(5) << right << fixed << setprecision(1) << other << " ";
            cout << setw(5) << right << fixed << setprecision(1) << total << endl;
            counter++;
        }
        cout << "\n";
        ifs.close();
        check=check->course_next;
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
    accessClass(username, year_head, class_head);
}