#include "ml_hypothesis_brute.hpp"

using namespace std;

ML_Hypothesis_Brute::ML_Hypothesis_Brute( string filename ) : ML_Hypothesis( filename ) {
    cout << "ML_Hypothesis_Brute constructor called" << endl;
}

ML_Hypothesis_Brute::~ML_Hypothesis_Brute( void ) {
    cout << "ML_Hypothesis_Brute deconstructor called" << endl;
}

void ML_Hypothesis_Brute::Init( int option1, int option2, int option3, int option4 ) {
    cout << "ML_Hypothesis_Brute init called" << endl;
}

void ML_Hypothesis_Brute::Solve( void ) {
    cout << "ML_Hypothesis_Brute solve called" << endl;
}

