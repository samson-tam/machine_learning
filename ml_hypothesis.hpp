#ifndef __ML_HYPOTHESIS__
#define __ML_HYPOTHESIS__
#include <iostream>
#include <string>
#include <vector>

class ML_Hypothesis {

    public:
    ML_Hypothesis( std::string filename );
    ~ML_Hypothesis( void );
    virtual void Init( int option1, int option2, int option3, int option4 ) = 0;
    virtual void Solve( void ) = 0;

    protected:
    std::vector <float> input;
    std::vector <float> output;
    int num_items;
    std::vector <float> cost_fn_values;
   
};

#endif /* __ML_HYPOTHESIS */
