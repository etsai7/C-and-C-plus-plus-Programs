#include <iostream>
#include <sstream>
#include <string>
#include "Student.h"
#include "Project4_utilities.h"
using namespace std;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int new_semester = 1;
    int end_semester = 0;
    int choice = -1;
    int seed;
    Student current_student;
    cout << "Please enter a Seed: ";
    cin >> seed;
    Set_rand_seed(seed);
    while(new_semester == 1)
    {
        cout << "Welcome to a new semester. What would you like to do?" << endl;
        while(end_semester == 0)
        {
            cout << "Please select one of the following actions:" << endl;
            cout << "Please enter the corresponding number for the action: " << endl;
            cout << "1 Add a Course" << endl;
            cout << "2 Drop a Course" << endl;
            cout << "3 Ask the Professor for the Rubric" << endl;           
            cout << "4 Print the Rubric" << endl;
            cout << "5 Calculate current Grades" << endl;
            cout << "6 Take Finals" << endl;
            cout << "7 Study" << endl;
            cout << "8 Take an Exam" << endl;
            cout << "Choice: ";
            cin >> choice;
            cout << "" << endl;
            if(choice == 6)
            {
                end_semester = 1;
            }
            current_student.action(choice);
            cout << "--------------------------------------" << endl;
        }
        cout << "You finished the semester. Continue? 1 for yes 0 for no" << endl;
        cin >> new_semester;
        end_semester = 0;
    }

}
