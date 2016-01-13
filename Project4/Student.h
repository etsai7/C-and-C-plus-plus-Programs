#include "Course.h"
#include <string>
#include "Rubric.h"
#ifndef STUDENT_H
#define STUDENT_H
class Student
{
    public:
        Student();
        void action(int);
        void add_course(int, const string);
        void drop_course(string);
        void ask_for_prof_rubric();
        void print_current_rubric();
        void calculate_grades();
        void take_final();
        void study();
        void exam();
        void print_courses() const;
    private:
        Course *course_list[6];
        Rubric grading_Rubric;
        int num_courses;
        double cumulative_grade_points;
        int cumulative_courses_taken;

};

#endif
