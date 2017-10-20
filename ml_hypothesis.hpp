/* 
 * ml_hypothesis.hpp - header file for ml_hypothesis.cpp
 *
 */
#ifndef __ML_HYPOTHESIS__
#define __ML_HYPOTHESIS__
#include <iostream>
#include <string>
#include <vector>

class ML_Hypothesis {

    public:
    ML_Hypothesis( std::string filename );
    ~ML_Hypothesis( void );
    void ReadTrainingSet( std::string filename );
    void DisplayTrainingSet( void );
    virtual void Init( double option1, double option2, double  option3, double option4 ) = 0;
    virtual void Solve( void ) = 0;

    protected:
    std::vector <double> input;
    std::vector <double> output;
    int num_items;
    std::vector <double> cost_fn_values;
   
};

#endif /* __ML_HYPOTHESIS */
