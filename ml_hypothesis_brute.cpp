/* 
 * ml_hypothesis_brute.cpp - derived class for Brute force approach to learning algorithm
 *
 */
#include "ml_hypothesis_brute.hpp"

#include <tgmath.h>
#include <cfloat>

using namespace std;

/*
 * derived constructor
 */
ML_Hypothesis_Brute::ML_Hypothesis_Brute( string filename ) : ML_Hypothesis( filename ) {
    theta0 = 0;
    theta0_min = 0;
    theta0_max = 0;

    theta1 = 0;
    theta1_min = 0;
    theta1_max = 0;
    cout << "ML_Hypothesis_Brute constructor called" << endl;
}

/*
 * derived destructor
 */
ML_Hypothesis_Brute::~ML_Hypothesis_Brute( void ) {
    cout << "ML_Hypothesis_Brute deconstructor called" << endl;
}

/*
 * initialize parameters for learning algorithm
 */
void ML_Hypothesis_Brute::Init( int option1, int option2, int option3, int option4 ) {
    if ( 0 != option1 ) {
        theta0_min = option1;
    }

    if ( 0 != option2 ) {
        theta0_max = option2;
    }

    if ( 0 != option3 ) {
        theta1_min = option3;
    }

    if ( 0 != option4 ) {
        theta1_max = option4;
    }

    cout << "ML_Hypothesis_Brute init called" << endl;
}

/*
 * solve hypothesis with learning algorithm
 *
 * brute force method
 * ------------------
 *
 * set theta0 to theta0_min, and iterate from theat1_min to theat1_max
 *  calculating cost function J.  Store minimum J and corresponding theta0
 *  and theta1
 * J ( theta0, theta1 ) = ( 1 / ( 2 * num_items ) ) * 
 *    SUMMATION ( i = 1 to num_items ) ( h(x(i) - y(i) )^2
 * h(x(i)) = theta0 + ( theta1 * x(i) )
 *
 */
void ML_Hypothesis_Brute::Solve( void ) {

    float minJ = FLT_MAX;
    float J;
    int h_x;
    int theta0_cnt, theta1_cnt, sum_cnt;
    int num_calcs = 0;

    for ( theta0_cnt = theta0_min; theta0_cnt <= theta0_max; theta0_cnt++ ) {
        for ( theta1_cnt = theta1_min; theta1_cnt <= theta1_max; theta1_cnt++ ) {
            J = 0;
            for ( sum_cnt = 0; sum_cnt < num_items; sum_cnt++ ) {
                /* calculate h(x(i)) */
                h_x = theta0_cnt + ( theta1_cnt * input.at( sum_cnt ) );
                J += ( float )( pow ( ( double )( h_x - output.at( sum_cnt ) ), 2.0 ) );
                num_calcs++;
            }
            J = J / ( float )num_items;
            if ( J < minJ ) {
                minJ = J;
                theta0 = theta0_cnt;
                theta1 = theta1_cnt;
            }
        }
    }               

    cout << "Brute force solution: # calc " << num_calcs << " theta0 " << theta0 << " theta1 " << theta1 << " minJ " << minJ << endl;
 
    cout << "ML_Hypothesis_Brute solve called" << endl;
}

