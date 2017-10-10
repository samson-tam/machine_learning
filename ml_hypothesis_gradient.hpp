#include "ml_hypothesis.hpp"

class ML_Hypothesis_Gradient : public ML_Hypothesis {
 
    public:
    ML_Hypothesis_Gradient( std::string filename );
    ~ML_Hypothesis_Gradient( void );
    void Init( int option1, int option2, int option3, int option4 );
    void Solve( void );

    private:
    int theta0;
    int theta1;
    int alpha;

}; 
