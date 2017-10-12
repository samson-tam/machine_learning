/* 
 * ml_hypothesis_brute.hpp - header file for ml_hypothesis_brute.cpp
 *
 */
#include "ml_hypothesis.hpp"

class ML_Hypothesis_Brute : public ML_Hypothesis {
 
    public:
    ML_Hypothesis_Brute( std::string filename );
    ~ML_Hypothesis_Brute( void );
    void Init( int option1, int option2, int option3, int option4 );
    void Solve( void );

    private:
    int theta0, theta0_min, theta0_max;
    int theta1, theta1_min, theta1_max;

};
