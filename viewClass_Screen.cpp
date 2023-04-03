#include "Staff.h"

void viewClass_Screen(string username, Year* &year_head)
{
    system("cls");
    string filename;
    filename = "class_" + year_head->year_name + ".txt";
    year_head->class_head = getClassListFromFile(year_head, filename);
    cout << "------------ACCESS-A-CLASS------------\n";
    cout << "Please choose the class you have created you want to access";
    
    Class* cur = year_head->class_head; int numClasses = 0;

    //Show list of years the staff has created before
    if (cur == nullptr) //Data is empty
        cout << "\n" << "Oops, there is nothing for you to choose" << "\n";
    else
    {
        cout << "\n\n" << "Here are some classes you created" << "\n";

        while (cur)
        {
            cout << numClasses + 1 << "." << setw(2) << right << cur->class_name<< "\n";
            cur = cur->next_class;
            numClasses++;
        }
    }
    cout << "\n";

    cout << "0. Return back" << "\n";
    //Move the pointer cur to the pointer class_head again
    cur = year_head->class_head;

    if (cur)
    {
        //Allow users to input their option
        int option;
        do
        {
            cout << "Please input your option: ";
            cin >> option;
        } while (option < 0 || option > numClasses);

        if (option)
        {
            //Move it to the Node including suitable class
            for (int i = 0; i < option - 1; ++i)
            {
                cur = cur->next_class;
            }

            //Show some more options
            accessClass(username, year_head, cur);
            return;
        }
        else
        {
            system("cls");
            accessSchoolYear(username, year_head);
            return;
        }
    }

    int opt;
    cout << "Please input 0 for returning back to the previous screen: ";
    cin >> opt;

    while (opt != 0)
    {
        cout << "Please input again: ";
        cin >> opt;
    }

    system("cls");
    accessSchoolYear(username, year_head);
}
