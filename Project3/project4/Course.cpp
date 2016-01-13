#include <iostream>
#include <string>
#include "Course.h"
#include "Fact.h"

using std::cout;
using std::endl;

Course::Course(string subject, string course)
{
    subject_name = subject;
    course_name = course;
    course_Fact_List = new Fact_List();
    points_earned_so_far = 0;
    number_grade = 0;
    letter_grade = "";
    exams_taken = 0;
}

Course::~Course()
{
    delete course_Fact_List;   
}

string Course::get_course_name()
{
    return course_name;
}

string Course::get_subject_name()
{
    return subject_name;
}

void Course::study(string subject)
{
    course_Fact_List->set_next_Fact(subject);    
}

int Course::take_exam()
{
    int tempScore;
    tempScore = 0;
    exams_taken++;
    while(course_Fact_List->Remove())
    {
        tempScore = tempScore + Get_points();
    }
    if(tempScore > 100)
    {
        tempScore = 100;
    }
    points_earned_so_far = points_earned_so_far + tempScore;
    cout << "Exam score: " << tempScore << endl;
    return tempScore;
}

double Course::calculate_course_grade()
{
    if(exams_taken != 0)
    {
        number_grade =((double) points_earned_so_far) / exams_taken;    
        cout << "Subject: " << this->get_subject_name() << endl;
        cout << "Course: " << this->get_course_name() << endl;    
        cout << "Exams taken: " << exams_taken << endl;
        cout << "Number grade: " << number_grade << endl;
        cout << "" << endl;
        return number_grade;;
    }
    else
    {
        cout << "Subject: " << this->get_subject_name() << endl;
        cout << "Course: " << this->get_course_name() << endl;
        cout << "No exams taken yet. There are no grades." << endl;
        return 0;
    }

}
