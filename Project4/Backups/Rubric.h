#include <string>
using std::string;
#ifndef RUBRIC_H
#define RUBRIC_H
class Rubric
{
    public:
        Rubric();

        void update_rubric();
        void print_rubric();
        string get_letter_grade(int score);
 
    private:
        int A;
        int B;
        int C;
        int D;
};

#endif
