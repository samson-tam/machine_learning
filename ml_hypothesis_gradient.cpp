/* 
 * ml_hypothesis_gradient.cpp - derived class for Gradient Descent approach to learning algorithm
 *
 */
#include "ml_hypothesis_gradient.hpp"

using namespace std;

/*
 * derived constructor
 */
ML_Hypothesis_Gradient::ML_Hypothesis_Gradient( string filename ) : ML_Hypothesis( filename ) {
    cout << "ML_Hypothesis_Gradient constructor called" << endl;
}

/*
 * derived destructor
 */
ML_Hypothesis_Gradient::~ML_Hypothesis_Gradient( void ) {
    cout << "ML_Hypothesis_Gradient deconstructor called" << endl;
}

/*
 * initialize parameters for learning algorithm
 */
void ML_Hypothesis_Gradient::Init( int option1, int option2, int option3, int option4 ) {
    cout << "ML_Hypothesis_Gradient init called" << endl;
}

/*
 * solve hypothesis with learning algorithm
 */
void ML_Hypothesis_Gradient::Solve( void ) {
    cout << "ML_Hypothesis_Gradient solve called" << endl;
}

