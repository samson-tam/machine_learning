/* 
 * ml_hypothesis_gradient.cpp - derived class for Gradient Descent 
 *                              approach to learning algorithm
 *                            - equations for hypothesis h and cost 
 *                              function J are taken from the Coursera 
 *                              class, Machine Learning, by Prof. 
 *                              Andrew Ng at Stanford University
 *
 */
#include "ml_hypothesis_gradient.hpp"

using namespace std;

/*
 * derived constructor
 */
ML_Hypothesis_Gradient::ML_Hypothesis_Gradient( string filename ) : ML_Hypothesis( filename ) {
    theta0 = 0;
    theta1 = 0;
    alpha = 0;
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
void ML_Hypothesis_Gradient::Init( double option1, double option2, double option3, double option4 ) {
    alpha = option1;
    theta0 = option2;
    theta1 = option3;
    cout << "ML_Hypothesis_Gradient init called" << endl;
}

/*
 * solve hypothesis with learning algorithm
 *
 * gradient descent method
 * -----------------------
 * 
 * set theta0 = theta0 - alpha * ( 1 / num_items ) *  SUMMATION 
 *  ( i = 1 to num_items ) ( ( h(x(i)) - y(i) ) )
 * set theta1 = theta1 - alpha * ( 1 / num_items ) *  SUMMATION 
 *  ( i = 1 to num_items ) ( ( ( h(x(i)) - y(i) ) ) * x(i) )
 * h(x(i)) = theta0 + ( theta1 * x(i) )
 *
 * iterate through until theta0 and theta1 are minimum
 *
 */
void ML_Hypothesis_Gradient::Solve( void ) {
    double h_x;
    int num_calcs = 0;
    double working_theta0 = -1;
    double working_theta1 = -1;
    int sum_cnt;
    double sum0, sum1;
    int pass_no = 0;

    while ( ( working_theta0 != theta0 ) || ( working_theta1 != theta1 ) ) {
        working_theta0 = theta0;
        working_theta1 = theta1;
        sum0 = 0;
        sum1 = 0;

        for ( sum_cnt = 0; sum_cnt < num_items; sum_cnt++ ) {
            /* calculate h(x(i)) */
            h_x = ( working_theta0 + ( working_theta1 * input.at( sum_cnt ) ) );
            sum0 += ( h_x - output.at( sum_cnt ) );
            sum1 += ( ( h_x - output.at( sum_cnt ) ) * input.at( sum_cnt ) );
            num_calcs+=2;
        }
        sum0 /= ( double )num_items;
        sum1 /= ( double )num_items;
        sum0 *= alpha;
        sum1 *= alpha;

        theta0 = working_theta0 - sum0;
        theta1 = working_theta1 - sum1;
        pass_no++;

        cout << "Gradient descent pass " << pass_no << " theta ( " << theta0 << ", "  << theta1 << " ) " << ", working theta ( " << working_theta0 << ", " << working_theta1 << " ) " << endl;

    }

    cout << "Gradient descent solution: # calc " << num_calcs << " theta0 " << theta0 << " theta1 " << theta1 << " alpha " << alpha << endl;

    cout << "ML_Hypothesis_Gradient solve called" << endl;
}

