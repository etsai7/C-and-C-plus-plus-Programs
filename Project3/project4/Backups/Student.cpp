#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Course.h"
#include "Project4_utilities.h"
#include "Rubric.h"
#include "Fact.h"
#include "Student.h"
using std::cout;
using std::endl;
using std::cin;
using std::setprecision;
using std::fixed;
Student::Student()
{
    cout << fixed << setprecision(2);
    int x = 0;
    while(x <  6)                                                                       /*Just makes sure the array is filled with NULLS*/
    {
        course_list[x] = NULL;                                                          /*List of courses. An array of pointers of type Course*/
        x++;
    }
 
    grading_Rubric = Rubric();                                                          /*Initialize Rubric*/
    num_courses = 0;                                                                    /*Counter for number of courses in current Semester*/    
    cumulative_grade_points = 0.00;                                                     /*Keeps track of total grade points across all Semesters*/
    cumulative_courses_taken = 0.00;                                                    /*Keps track of total courses taken across all Semesters*/
}

void Student::action(int answer)
{
    /*Add a Course*/
    if(answer == 1)
    {
        if(num_courses < 5)
        {
            int x;
            x = 1;
            int subject;                                                                /*int because limited options available to choose from*/
            string course;                                                              /*User input for later*/
            cout << "" << endl;                                                         /*This is the menu to add a course*/
            cout << "You selected: Add a Course" << endl;
            cout << "Please choose a subject to add by selecting option number:" << endl;
            cout << "\t1-Physics" << endl;
            cout << "\t2-History" << endl;
            cout << "\t3-Math" << endl;
            cout << "\t4-Biology" << endl;
            cout << "\t5-Art" << endl;
            cout << "\t6-Computer Science" << endl;
            cout << "Subject: ";
            cin >> subject;
            cout << "Enter a Course you would like to study" << endl;
            cout << "Course Name: ";
            cin >> course;
            do                                                                          /*Makes sure that there isn't another course with same name*/
            {
                x = 1;
                for(int i = 1; i <= num_courses; i++)
                {
                    if(course_list[i]->get_course_name() == course)
                    {
                        x = 0;
                    }
                }
                if(x == 0)
                {                                                                       /*Makes you enter a different course name*/    
                    cout << "You are already taking that course. Enter another course: " << endl; 
                    cin >> course;
                }
            }while(x == 0);
            this->add_course(subject,course);                                           /*A valid course and subject has been selected and calling method*/
         }
        else
        {
            cout << "Sorry you have a full schedule." << endl;                          /*Can't add anymore Courses. You have 5 Courses*/
        }
    }
    /*Drop a Course*/
    else if(answer == 2)
    {
        int z = 1;
        string course;
        if(num_courses > 0)
        {
            cout << "You selected: Drop a Course\n" << endl;
            cout << "Select one of the following courses to drop:" << endl;
            while(z <= num_courses)
            {
                cout << course_list[z]->get_course_name() << endl;
                z++;
            }
            cout << "Please enter course name to drop: " << endl;
            cin >> course;
            this->drop_course(course);
        }
        else
        {
            cout << "You don't have any classes to drop!" << endl;
        }
    }
    /*Ask Prof for Rubric*/
    else if(answer == 3)
    {
        cout << "You selected: Ask the Prof for updated Rubric" << endl;
        this->ask_for_prof_rubric();
    }
    /*Print the Rubric*/
    else if(answer == 4)
    {
        cout << "You selected: Print current Rubric" << endl;
        this->print_current_rubric();
    }
    /*Calculate_grades*/
    else if(answer == 5)
    {
        cout << "You selected: Calculate grades" << endl;
        this->calculate_grades();
    }
    /*Take Finals*/
    else if(answer == 6)
    {
        cout << "You selected: Take Finals" << endl;
        this->take_final();    
    }
    /*Study for a course*/
    else if(answer == 7)
    {
        cout << "You selected: Study" << endl;
        this->study();
    }
    /*Take and exam*/
    else if(answer == 8)
    {
        cout << "You selected: Take an Exam" << endl;
        this->exam();    
    }
}
/*--------------------------------------------------------------------*/
void Student::add_course(int subject, string course)
{
    Course *add;                                                    /*The new course to be added*/
    int x = 1;
    if(subject == 1)
    {
        add = new Course("physics", course);                        /*Creating the new Course*/  
    }
    else if(subject == 2)
    {
        add = new Course("history", course);
    }
    else if(subject == 3)
    {
        add = new Course("math", course);
    }
    else if(subject == 4)
    {
        add = new Course("biology",course);
    }
    else if(subject == 5)
    {
        add = new Course("art", course);
    }
    else if(subject == 6)
    {
        add = new Course("computer science", course);
    }
    else
    {
        cout << "Invalid subject entered. Failed to add" << endl;
    }
    while(x <= 5)                                                   /*Finds an open space to insert new course*/
    {
        if(course_list[x] == NULL)
        {
            course_list[x] = add;
            num_courses++;
            break;
        }
        x++;
    }
    x = 1;
}

void Student::drop_course(string course)
{
    int t;
    int found = 0;
    int x = 1;
    cout << "Select course to drop " << endl;
    while(x <= num_courses)                                         /*Traverses array to find course*/
    {           
        if(course_list[x]->get_course_name() == course)             /*found coursename*/
        {
            t = x;
            num_courses--;
            delete course_list[x];
            course_list[x] = NULL;
            found = 1;
            while(t <= num_courses )                                /*Reshifts the course list*/
            {
                course_list[t] = course_list[t+1];
                course_list[t+1] = NULL;
                t++;
            }
            course_list[t+1] = NULL;
            cout << "Course successfully deleted." << endl;
        }
        x++;
    }
    if(found == 0)
    {
        cout << "Course was not found. Cannot be dropped." << endl;
    }
}

void Student::ask_for_prof_rubric()
{
    grading_Rubric.update_rubric();   
}

void Student::print_current_rubric()
{
    grading_Rubric.print_rubric();
}

void Student::calculate_grades()
{
    int temp_num_score;
    double temp_total_GPA;
    double temp_sem_GPA;
    double class_GPA;
    string letter_grade;
    temp_total_GPA = 0.00;
    temp_sem_GPA = 0.00;
    cout << "Number of Courses: " << num_courses << endl;
    for(int i = 1; i <= num_courses; i++)
    {
        temp_num_score = course_list[i]->calculate_course_grade();
        letter_grade = grading_Rubric.get_letter_grade(temp_num_score);
        if(letter_grade == "A")
           class_GPA = 4.00;
        else if(letter_grade == "B")
           class_GPA = 3.00;
        else if(letter_grade == "C")
           class_GPA = 2.00;
        else if(letter_grade == "D")
           class_GPA = 1.00;
        else
           class_GPA = 0.00;
        temp_sem_GPA = temp_sem_GPA + class_GPA;       
    }
    if(num_courses != 0)
    {
        temp_sem_GPA = temp_sem_GPA/num_courses;
        cout << "Current Semester GPA: " << std::setprecision(2) << temp_sem_GPA << endl; 
    }
    else
    {
        temp_sem_GPA = 0.00;
        cout << "Current Semester GPA: " << std::setprecision(2) << temp_sem_GPA << endl;
    }
    if(cumulative_courses_taken != 0)
    {
        temp_total_GPA = cumulative_grade_points/cumulative_courses_taken;
        cout << "Cumulative GPA: " << std::setprecision(2) <<temp_total_GPA << endl;
    }
    else
    {
        temp_total_GPA = 0.00;    
        cout << "Cumulative GPA: " << std::setprecision(2) << temp_total_GPA << endl;
    }
}   

void Student::take_final() 
{
    int final_exam_score;
    double class_GPA;
    int current_course_grade;
    string letter_grade;
    double temp_total_GPA;
    double temp_sem_GPA;
    temp_total_GPA = 0.00;
    temp_sem_GPA = 0.00;
    if(num_courses != 0)
    {
        for(int i = 1; i <= num_courses; i++)
        {
            final_exam_score = course_list[i]->take_exam();
            cout << "Final Exam Letter Grade: " << grading_Rubric.get_letter_grade(final_exam_score) << endl;
            current_course_grade = course_list[i]->calculate_course_grade();
            letter_grade = grading_Rubric.get_letter_grade(current_course_grade);
            cout << "Course Letter Grade: " << letter_grade << endl;
            if(letter_grade == "A")
                class_GPA = 4.00;
            else if(letter_grade == "B")
                class_GPA = 3.00;
            else if(letter_grade == "C")
                class_GPA = 2.00;
            else if(letter_grade == "D")
                class_GPA = 1.00;
            else
                class_GPA = 0.00;
            cout << "Course GPA: " << std::setprecision(2) << class_GPA << endl;
            cout << "------------------------------------" << endl; 
            temp_sem_GPA = temp_sem_GPA + class_GPA;   
            delete course_list[i];
        }
    
    
        cumulative_grade_points = cumulative_grade_points + temp_sem_GPA;
        cumulative_courses_taken = cumulative_courses_taken + num_courses;
        temp_sem_GPA = temp_sem_GPA/num_courses;
    }
    else{
        cout << "No classes were taken. What an easy Semester." << endl;
        cout <<"-----------------------------" << endl;
        temp_sem_GPA = 0.00;
    }
    if(cumulative_courses_taken != 0)
    {
        temp_total_GPA = cumulative_grade_points/cumulative_courses_taken;     
    }
    else
    {
        temp_total_GPA = 0.00;
    }
    cout << "Semester GPA: " << std::setprecision(2) << temp_sem_GPA << endl;
    cout << "Cumulative GPA: " << std::setprecision(2) << temp_total_GPA << " over " << cumulative_courses_taken << " courses." << endl;
    
    num_courses = 0;
    grading_Rubric = Rubric();
    for(int t = 1; t <= 5; t++)
    {
        course_list[t] = NULL;
    }
}

void Student::study()
{
    int z = 1;
    string course_name;
    cout << "Select a class to study for" << endl;
    while(z <= num_courses)
    {
        cout << course_list[z]->get_course_name() << endl;
        z++;
    }
    cout << "Please enter course name to study for:" << endl;
    cin >> course_name;
    for(int i = 1; i <= num_courses; i++)
    {
        if(course_list[i]->get_course_name() == course_name)
        {
            course_list[i]->study(course_list[i]->get_subject_name());
            cout << "Course Successfully Studied" << endl;
        }
    }
}

void Student::exam()
{
    int score;
    string letter_grade;
    string course_name;
    cout << "Please enter course name to take an exam for:" << endl;
    cin >> course_name;
    for(int i = 1; i <= num_courses; i++)
    {
        if(course_list[i]->get_course_name() == course_name)
        {
           score =  course_list[i]->take_exam();
           letter_grade = grading_Rubric.get_letter_grade(score);
           cout << "Letter Grade: " << letter_grade << endl;
        }
    }   
}
