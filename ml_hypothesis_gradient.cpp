#include "ml_hypothesis_gradient.hpp"

using namespace std;

ML_Hypothesis_Gradient::ML_Hypothesis_Gradient( string filename ) : ML_Hypothesis( filename ) {
    cout << "ML_Hypothesis_Gradient constructor called" << endl;
}

ML_Hypothesis_Gradient::~ML_Hypothesis_Gradient( void ) {
    cout << "ML_Hypothesis_Gradient deconstructor called" << endl;
}

void ML_Hypothesis_Gradient::Init( int option1, int option2, int option3, int option4 ) {
    cout << "ML_Hypothesis_Gradient init called" << endl;
}

void ML_Hypothesis_Gradient::Solve( void ) {
    cout << "ML_Hypothesis_Gradient solve called" << endl;
}

