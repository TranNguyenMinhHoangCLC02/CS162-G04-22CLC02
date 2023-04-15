#include "../Header/Staff.h"

void deleteCourse(Semester *semester, Course *&course_head, Course* course) 
{
    int option;
    cout<< "Are you sure you want to delete? (1 for Yes, 0 for No)";
    cin>> option;
    while (option != 0 && option != 1){
            cout << "Invalid input. Please enter again: ";
            cin >> option;
        }        
    if (option == 0)
        return;

    // Delete Course in Semester
    Course *cur = semester->course_head;
    Course *pre = nullptr;
    while (cur != course)
    {
        pre = cur;
        cur = cur->course_next;
    }
    if (pre == nullptr)
        semester->course_head = semester->course_head->course_next;
    else 
        pre->course_next = cur->course_next;
    
    // Delete Course in Course list
    Course *curr = course_head;
    Course *prev = nullptr;

    // Search for the course in the list
    while (curr != course) 
    {
        prev = curr;
        curr = curr->course_next;
    }

    // Remove the course from the list
    if (prev == nullptr)  // Case where the head node is the one to remove
        course_head = curr->course_next;
    else
        prev->course_next = curr->course_next;

    // Remove the course from the enrolled courses list of all students
    Student *student_ptr = curr->student_head;
    while (student_ptr != nullptr) 
    {
        Course *enrolled_course_ptr = student_ptr->course_head;
        Course *enrolled_course_prev = nullptr;

        while (enrolled_course_ptr != nullptr && enrolled_course_ptr != curr) 
        {
            enrolled_course_prev = enrolled_course_ptr;
            enrolled_course_ptr = enrolled_course_ptr->course_next;
        }

        if (enrolled_course_ptr == curr) 
        {
            if (enrolled_course_prev == nullptr)
                student_ptr->course_head = enrolled_course_ptr->course_next;
            else
                enrolled_course_prev->course_next = enrolled_course_ptr->course_next;
        }

        student_ptr = student_ptr->student_next;
    }

    // Delete the course node
    delete cur;
    delete curr;
}

