#include "Staff.h"

bool checkInvalidSemester (string input)
{
    if (input != "0" && input != "1" && input != "2" && input != "3")
        return false;

    return true;
}

bool checkExistingSemester (Semester* &semester_head, string input)
{
    if (input[0] == '0')
        return true;
    
    int semester_ord = (int)input[0] - 48;
    
    if (!semester_head)
        return true;
    
    Semester* temp_semester = semester_head;

    while (temp_semester)
    {
        if (temp_semester->Semester_Ord == semester_ord)
            return false;

        temp_semester = temp_semester->semester_next;
    }

    return true;
}

//Check if the input data had any characters or special letters
bool checkYearOfDate (string StartDate_Year_Input)
{
    int len = StartDate_Year_Input.size();

    for (int i = 0; i < len; ++i)
    {
        if (StartDate_Year_Input[i] < '0' || StartDate_Year_Input[i] > '9')
            return false;
    } 

    return true; 
}

bool checkMonthOfDate (string StartDate_Month_Input)
{
    int len = StartDate_Month_Input.size();

    for (int i = 0; i < len; ++i)
    {
        if (StartDate_Month_Input[i] < '0' || StartDate_Month_Input[i] > '9')
            return false;
    } 

    return true;
}

bool checkDayOfDate (string StartDate_Day_Input)
{
    int len = StartDate_Day_Input.size();

    for (int i = 0; i < len; ++i)
    {
        if (StartDate_Day_Input[i] < '0' || StartDate_Day_Input[i] > '9')
            return false;
    } 

    return true;
}

bool checkInvalidDayOfDate (int year, int month, string StartDate_Day_Input)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        switch (month)
        {
            case 1:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 31)
                    return false;
            }
            case 2:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 29)
                    return false;
            }
            case 3:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 31)
                    return false;
            }
            case 4:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 30)
                    return false;
            }
            case 5:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 31)
                    return false;
            }
            case 6:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 30)
                    return false;
            }
            case 7:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 31)
                    return false;
            }
            case 8:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 31)
                    return false;
            }
            case 9:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 30)
                    return false;
            }
            case 10:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 31)
                    return false;
            }
            case 11:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 30)
                    return false;
            }
            case 12:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 31)
                    return false;
            }
        }
    }
    else
    {
        switch (month)
        {
            case 1:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 31)
                    return false;
            }
            case 2:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 28)
                    return false;
            }
            case 3:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 31)
                    return false;
            }
            case 4:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 30)
                    return false;
            }
            case 5:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 31)
                    return false;
            }
            case 6:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 30)
                    return false;
            }
            case 7:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 31)
                    return false;
            }
            case 8:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 31)
                    return false;
            }
            case 9:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 30)
                    return false;
            }
            case 10:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 31)
                    return false;
            }
            case 11:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 30)
                    return false;
            }
            case 12:
            {
                if (stoi(StartDate_Day_Input) <= 0 || stoi(StartDate_Day_Input) > 31)
                    return false;
            }
        }
    }

    return true;
}

bool checkStartDateAndEndDate (int startyear, int startmonth, int startday, int endyear, int endmonth, int endday)
{
    if (startyear > endyear)
        return false;
    
    if (startyear == endyear)
    {
        if (startmonth > endmonth)
            return false;

        if (startmonth == endmonth)
        {
            if (startday >= endday)
                return false;
        }
    }

    return true;
}

void addNewSemester (string username, Year* &year_head) //Now, year_head is the school year you are accessing
{
    ofstream ofs;

    //Create new node for linked list semester_head
    cout << "Principles when inputing a new semester\n";
    cout << "1. You must input a number from 1 to 3 because there are at most 3 semesters in a school year\n";
    cout << "2. Don't input an available semester in your chosen school year!\n";
    cout << "3. You can input 0 if you want to return back\n\n";

    string input;
    cin.ignore();
    cout << "Please type the semester you want to add (Ensure that your input follows our given principles: ";
    getline(cin, input);

    //If user's input is wrong, input again
    while (!checkInvalidSemester(input) || !checkExistingSemester(year_head->semester_head, input))
    {
        if (!checkInvalidSemester(input))
        {
            cout << "Your input must include a number from 0 to 3, please input again: ";
            getline(cin, input);
        }
        else
        {
            cout << "Your inputed semester was existed in your chosen school year, please input another semester: ";
            getline(cin, input);
        }
    }

    if (input == "0")
    {
        system ("cls");
        accessSchoolYear(username, year_head);
        return;
    }
    else
    {
        //Start Date
        cout << "\n";
        cout << "Start date of your inputted semester\n";

        string StartDate_year_input;
        cout << "Year: ";
        getline(cin, StartDate_year_input);

        while (!checkYearOfDate(StartDate_year_input))
        {
            cout << "Your input year included at least 1 letter which is different from numbers, please input again: \n";
            cout << "Year: ";
            getline(cin, StartDate_year_input);
        }

        if (StartDate_year_input == "0")
        {
            system ("cls");
            accessSchoolYear(username, year_head);
            return;
        }
        
        string StartDate_month_input;
        cout << "Month: ";
        getline(cin, StartDate_month_input);

        if (StartDate_month_input == "0")
        {
            system ("cls");
            accessSchoolYear(username, year_head);
            return;
        }

        while (!checkMonthOfDate(StartDate_month_input) || stoi(StartDate_month_input) < 1 || stoi(StartDate_month_input) > 12)
        {
            if (!checkMonthOfDate(StartDate_month_input))
            {
                cout << "Your input month included at least 1 letter which is different from numbers, please input again: \n";
                cout << "Month: ";
                getline(cin, StartDate_month_input);
                
                if (StartDate_month_input == "0")
                {
                    system ("cls");
                    accessSchoolYear(username, year_head);
                    return;
                }
            }
            else
            {
                cout << "The value of month must be in range of 1 to 12, please input again: \n";
                cout << "Month: ";
                getline(cin, StartDate_month_input);

                if (StartDate_month_input == "0")
                {
                    system ("cls");
                    accessSchoolYear(username, year_head);
                    return;
                }
            }
        }

        string StartDate_day_input;
        cout << "Day: ";
        getline(cin, StartDate_day_input);

        if (StartDate_day_input == "0")
        {
            system ("cls");
            accessSchoolYear(username, year_head);
            return;
        }  

        while (!checkDayOfDate(StartDate_day_input) || !checkInvalidDayOfDate(stoi(StartDate_year_input), stoi(StartDate_month_input), StartDate_day_input))
        {
            if (!checkDayOfDate(StartDate_day_input))
            {
                cout << "Your input day included at least 1 letter which is different from numbers, please input again: \n";
                cout << "Day: ";
                getline(cin, StartDate_day_input);

                if (StartDate_day_input == "0")
                {
                    system ("cls");
                    accessSchoolYear(username, year_head);
                    return;
                }
            }
            else
            {
                cout << "Your inputed month does not include this day, please input again: \n";
                cout << "Day: ";
                getline(cin, StartDate_day_input);

                if (StartDate_day_input == "0")
                {
                    system ("cls");
                    accessSchoolYear(username, year_head);
                    return;
                }
            }
        }

        //End Date
        cout << "\n";
        cout << "End date of your inputted semester\n";

        string EndDate_year_input;
        cout << "Year: ";
        getline(cin, EndDate_year_input);

        while (!checkYearOfDate(EndDate_year_input))
        {
            cout << "Your input year included at least 1 letter which is different from numbers, please input again: \n";
            cout << "Year: ";
            getline(cin, EndDate_year_input);
        }

        if (EndDate_year_input == "0")
        {
            system ("cls");
            accessSchoolYear(username, year_head);
            return;
        }
        
        string EndDate_month_input;
        cout << "Month: ";
        getline(cin, EndDate_month_input);

        if (EndDate_month_input == "0")
        {
            system ("cls");
            accessSchoolYear(username, year_head);
            return;
        }

        while (!checkMonthOfDate(EndDate_month_input) || stoi(EndDate_month_input) < 1 || stoi(EndDate_month_input) > 12)
        {
            if (!checkMonthOfDate(EndDate_month_input))
            {
                cout << "Your input month included at least 1 letter which is different from numbers, please input again: \n";
                cout << "Month: ";
                getline(cin, EndDate_month_input);

                if (EndDate_month_input == "0")
                {
                    system ("cls");
                    accessSchoolYear(username, year_head);
                    return;
                }
            }
            else
            {
                cout << "The value of month must be in range of 1 to 12, please input again: \n";
                cout << "Month: ";
                getline(cin, EndDate_month_input);

                if (EndDate_month_input == "0")
                {
                    system ("cls");
                    accessSchoolYear(username, year_head);
                    return;
                }
            }
        }

        string EndDate_day_input;
        cout << "Day: ";
        getline(cin, EndDate_day_input);

        if (EndDate_day_input == "0")
        {
            system ("cls");
            accessSchoolYear(username, year_head);
            return;
        }  

        while (!checkDayOfDate(EndDate_day_input) || !checkInvalidDayOfDate(stoi(EndDate_year_input), stoi(EndDate_month_input), EndDate_day_input))
        {
            if (!checkDayOfDate(EndDate_day_input))
            {
                cout << "Your input day included at least 1 letter which is different from numbers, please input again: \n";
                cout << "Day: ";
                getline(cin, EndDate_day_input);

                if (EndDate_day_input == "0")
                {
                    system ("cls");
                    accessSchoolYear(username, year_head);
                    return;
                } 
            }
            else
            {
                cout << "Your inputed month does not include this day, please input again: \n";
                cout << "Day: ";
                getline(cin, EndDate_day_input);

                if (EndDate_day_input == "0")
                {
                    system ("cls");
                    accessSchoolYear(username, year_head);
                    return;
                } 
            }
        }

        while (!checkStartDateAndEndDate(stoi(StartDate_year_input), stoi(StartDate_month_input), stoi(StartDate_day_input), stoi(EndDate_year_input), stoi(EndDate_month_input), stoi(EndDate_day_input)))
        {
            cout << "\n";
            cout << "End Date must be after Start Date, please input again!\n\n";

            //Start Date
            cout << "\n";
            cout << "Start date of your inputted semester\n";

            cout << "Year: ";
            getline(cin, StartDate_year_input);

            while (!checkYearOfDate(StartDate_year_input))
            {
                cout << "Your input year included at least 1 letter which is different from numbers, please input again: \n";
                cout << "Year: ";
                getline(cin, StartDate_year_input);
            }

            if (StartDate_year_input == "0")
            {
                system ("cls");
                accessSchoolYear(username, year_head);
                return;
            }
            
            cout << "Month: ";
            getline(cin, StartDate_month_input);

            if (StartDate_month_input == "0")
            {
                system ("cls");
                accessSchoolYear(username, year_head);
                return;
            }

            while (!checkMonthOfDate(StartDate_month_input) || stoi(StartDate_month_input) < 1 || stoi(StartDate_month_input) > 12)
            {
                if (!checkMonthOfDate(StartDate_month_input))
                {
                    cout << "Your input month included at least 1 letter which is different from numbers, please input again: \n";
                    cout << "Month: ";
                    getline(cin, StartDate_month_input);
                    
                    if (StartDate_month_input == "0")
                    {
                        system ("cls");
                        accessSchoolYear(username, year_head);
                        return;
                    }
                }
                else
                {
                    cout << "The value of month must be in range of 1 to 12, please input again: \n";
                    cout << "Month: ";
                    getline(cin, StartDate_month_input);

                    if (StartDate_month_input == "0")
                    {
                        system ("cls");
                        accessSchoolYear(username, year_head);
                        return;
                    }
                }
            }

            cout << "Day: ";
            getline(cin, StartDate_day_input);

            if (StartDate_day_input == "0")
            {
                system ("cls");
                accessSchoolYear(username, year_head);
                return;
            }  

            while (!checkDayOfDate(StartDate_day_input) || !checkInvalidDayOfDate(stoi(StartDate_year_input), stoi(StartDate_month_input), StartDate_day_input))
            {
                if (!checkDayOfDate(StartDate_day_input))
                {
                    cout << "Your input day included at least 1 letter which is different from numbers, please input again: \n";
                    cout << "Day: ";
                    getline(cin, StartDate_day_input);

                    if (StartDate_day_input == "0")
                    {
                        system ("cls");
                        accessSchoolYear(username, year_head);
                        return;
                    }
                }
                else
                {
                    cout << "Your inputed month does not include this day, please input again: \n";
                    cout << "Day: ";
                    getline(cin, StartDate_day_input);

                    if (StartDate_day_input == "0")
                    {
                        system ("cls");
                        accessSchoolYear(username, year_head);
                        return;
                    }
                }
            }

            //End Date
            cout << "\n";
            cout << "End date of your inputted semester\n";

            cout << "Year: ";
            getline(cin, EndDate_year_input);

            while (!checkYearOfDate(EndDate_year_input))
            {
                cout << "Your input year included at least 1 letter which is different from numbers, please input again: \n";
                cout << "Year: ";
                getline(cin, EndDate_year_input);
            }

            if (EndDate_year_input == "0")
            {
                system ("cls");
                accessSchoolYear(username, year_head);
                return;
            }
            
            cout << "Month: ";
            getline(cin, EndDate_month_input);

            if (EndDate_month_input == "0")
            {
                system ("cls");
                accessSchoolYear(username, year_head);
                return;
            }

            while (!checkMonthOfDate(EndDate_month_input) || stoi(EndDate_month_input) < 1 || stoi(EndDate_month_input) > 12)
            {
                if (!checkMonthOfDate(EndDate_month_input))
                {
                    cout << "Your input month included at least 1 letter which is different from numbers, please input again: \n";
                    cout << "Month: ";
                    getline(cin, EndDate_month_input);

                    if (EndDate_month_input == "0")
                    {
                        system ("cls");
                        accessSchoolYear(username, year_head);
                        return;
                    }
                }
                else
                {
                    cout << "The value of month must be in range of 1 to 12, please input again: \n";
                    cout << "Month: ";
                    getline(cin, EndDate_month_input);

                    if (EndDate_month_input == "0")
                    {
                        system ("cls");
                        accessSchoolYear(username, year_head);
                        return;
                    }
                }
            }

            cout << "Day: ";
            getline(cin, EndDate_day_input);

            if (EndDate_day_input == "0")
            {
                system ("cls");
                accessSchoolYear(username, year_head);
                return;
            }  

            while (!checkDayOfDate(EndDate_day_input) || !checkInvalidDayOfDate(stoi(EndDate_year_input), stoi(EndDate_month_input), EndDate_day_input))
            {
                if (!checkDayOfDate(EndDate_day_input))
                {
                    cout << "Your input day included at least 1 letter which is different from numbers, please input again: \n";
                    cout << "Day: ";
                    getline(cin, EndDate_day_input);

                    if (EndDate_day_input == "0")
                    {
                        system ("cls");
                        accessSchoolYear(username, year_head);
                        return;
                    } 
                }
                else
                {
                    cout << "Your inputed month does not include this day, please input again: \n";
                    cout << "Day: ";
                    getline(cin, EndDate_day_input);

                    if (EndDate_day_input == "0")
                    {
                        system ("cls");
                        accessSchoolYear(username, year_head);
                        return;
                    } 
                }
            }
        }

        //Create new semester
        Semester* new_semester = new Semester;
        new_semester->Semester_Ord = stoi(input);

        new_semester->start_date.day = stoi(StartDate_day_input);
        new_semester->start_date.month = stoi(StartDate_month_input);
        new_semester->start_date.year = stoi(StartDate_year_input);

        new_semester->end_date.day = stoi(EndDate_day_input);
        new_semester->end_date.month = stoi(EndDate_month_input);
        new_semester->end_date.year = stoi(EndDate_year_input);


        new_semester->course_head = nullptr;
        new_semester->semester_next = nullptr;

        //Add new semester at the end of semester list of corresponding year
        if (!year_head->semester_head)
            year_head->semester_head = new_semester;
        else
        {
            Semester* temp_semester = year_head->semester_head;

            while (temp_semester->semester_next)
                temp_semester = temp_semester->semester_next;

            temp_semester->semester_next = new_semester;
        }
    }

    //Print semester list after changed out file txt corresponding with the semester
    string file_name = year_head->year_name + "_semester.txt";
    ofs.open(file_name);
    if (!ofs.is_open())
    {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }

    Semester* temp_semester = year_head->semester_head;
    while (temp_semester)
    {
        ofs << temp_semester->Semester_Ord << "," << setw(2) << setfill('0') << temp_semester->start_date.day
            << "/" << setw(2) << setfill('0') << temp_semester->start_date.month << "/" << setw(4) << setfill('0') 
            << temp_semester->start_date.year << "," << setw(2) << setfill('0') << temp_semester->end_date.day
            << "/" << setw(2) << setfill('0') << temp_semester->end_date.month << "/" << setw(4) << setfill('0') << temp_semester->end_date.year << "\n";

        temp_semester = temp_semester->semester_next;
    }
    ofs.close();

    //Announce for user
    cout << "You created a new semester successfully!\n\n";

    //Require user input 0 for returning back
    string option;
    cout << "Please type the number 0 for returning back: ";
    getline(cin, option);

    while (option != "0")
    {
        cout << "The number is different from 0, please input again: ";
        getline(cin, option);
    }

    accessSchoolYear(username, year_head);
}