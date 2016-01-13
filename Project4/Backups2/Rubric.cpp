#include <string>
#include <iostream>
#include "Project4_utilities.h"
#include "Rubric.h"
using std::string;
using std::cout;
using std::endl;

Rubric::Rubric()
{
    A = 90;
    B = 80;
    C = 70;
    D = 60;
}

string Rubric::get_letter_grade(const int score)
{
    if(score >= A)
        return "A";
    else if (score >= B)
        return "B";
    else if (score >= C)
        return "C";
    else if (score >= D)
        return "D";
    else
        return "F";
}

void Rubric::update_rubric()
{
    Get_grade_cutoffs(A,B,C,D);
    this->print_rubric();
}

void Rubric::print_rubric() const
{
    cout << "A is: " << A << "\n" << endl;
    cout << "B is: " << B << "\n" << endl;
    cout << "C is: " << C << "\n" << endl;
    cout << "D is: " << D << "\n" << endl;
    cout << "F is: " << (D-1) << " and below\n" << endl;
}
