#ifndef INC_P4UTIL
#define INC_P4UTIL
#include <string>

/*These constants are the subject strings that the Get_fact function expects.*/

#define PHYSICS "physics"
#define HISTORY "history"
#define MATH "math"
#define BIO "biology"
#define ART "art"
#define COMPSCI "computer science"
#define NUM_SUBJECTS 6

/* This function gets a fact to study for the given subject. It stores the
 * unique id of the fact in the "fact_id" parameter. It stores the fact in the
 * "fact" parameter. (Note that ids are only unique within a given subject --
 * i.e.  biology and math can both have a fact with id 1)
 *
 * Returns 1 for success, 0 for failure (if the subject was invalid).*/
int Get_fact(std::string subject, int &fact_id, std::string &fact);

/* This function generates the values for a grading rubric. It stores the
 * lowest numerical grade (0-100) that earns an A in a_cutoff, the lowest grade
 * that earns a B in b_cutoff, the lowest grade that earns a C in c_cutoff, and
 * the lowest grade that earns a D in d_cutoff*/
void Get_grade_cutoffs(int &a_cutoff, int &b_cutoff, int &c_cutoff, int &d_cutoff);

/* This function then number of points that a fact is worth when the student
 * takes an exam. It returns the number of points the fact should be given. */
int Get_points(void);

/* Seed the random generator used in the above 3 functions */
void Set_rand_seed(int seed);

#endif /* INC_P4UTIL */
