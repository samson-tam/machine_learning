/* 
 * ml_hypothesis_gradient.hpp - header file for ml_hypothesis_brute.cpp
 *
 */
#include "ml_hypothesis.hpp"

class ML_Hypothesis_Gradient : public ML_Hypothesis {
 
    public:
    ML_Hypothesis_Gradient( std::string filename );
    ~ML_Hypothesis_Gradient( void );
    void Init( double option1, double option2, double option3, double option4 );
    void Solve( void );

    private:
    double theta0;
    double theta1;
    double alpha;

}; 
