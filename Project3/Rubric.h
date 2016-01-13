#include <string>
using std::string;
#ifndef RUBRIC_H
#define RUBRIC_H
class Rubric
{
    public:
        Rubric();

        void update_rubric();
        void print_rubric() const;
        string get_letter_grade(const int score);
 
    private:
        int A;
        int B;
        int C;
        int D;
};

#endif
