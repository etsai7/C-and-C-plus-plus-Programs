#include <string>
#include "Fact.h"
#include "Project4_utilities.h"
#ifndef COURSE_H
#define COURSE_H
class Course
{
   public:
       Course(std::string subject, std::string course);
       ~Course();
       std::string get_course_name();
       std::string get_subject_name();
       void study(std::string);
       int take_exam();
       double calculate_course_grade();

   private:
       Fact_List *course_Fact_List;
       std::string subject_name;
       std::string course_name;
       double number_grade;
       std::string letter_grade;
       int exams_taken;
       int points_earned_so_far;
        
};

#endif
