/* 
 * main.cpp - mainline
 *
 */

#include "ml_hypothesis_brute.hpp"
#include "ml_hypothesis_gradient.hpp"

#include <fstream>

using namespace std;

/* 
 * main() - mainline
 *        - arguments:  < filename > < strategy > < option 1 > < option 2 > 
 *                      < option 3 > < option 4 >
 *          < filename > - file with training set, must be same directory as
 *                         this executable
 *          < strategy > - BRUTE, GRADIENT
 *          < option_n > - choice of options depends on strategy
 *             for BRUTE: < option 1 > = lower value for theta0
 *                        < option 2 > = upper value for theta0
 *                        < option 3 > = lower value for theta1
 *                        < option 4 > = upper value for theta1
 *             for GRADIENT: < option 1 > = default value for alpha
 *                           < option 2 > = default for theta0
 *                           < option 3 > = default for theta1
 *                       
 *
 */
int main( int argc, char *argv[ ] ) {
 
    if ( argc >= 2  ) {
        ifstream data_file;
        string filename( argv[ 1 ] );
        if ( filename.empty()) {
            cout << "No filename provided for training set" << endl;
        } else {
            data_file.open( filename );
            if ( !data_file.is_open() ) {
                cout << "Could not open file:" << filename << endl;
                data_file.close();
            } else if ( argc >= 3 ) {

                /* ST 17/10/11 - close data file and reopen it again in 
                                 constructor when loading training set */
                data_file.close();
                string hyp_strategy( argv[ 2 ] );
                int options[4] = { 0, 0, 0, 0 };

                /* atoi converts any non-numeric values to 0 */
                if ( argc >= 4 ) {
                    options[ 0 ] = atoi(argv[ 3 ]);
                }
                if ( argc >= 5 ) {
                    options[ 1 ] = atoi(argv[ 4 ]);
                }
                if ( argc >= 6 ) {
                    options[ 2 ] = atoi(argv[ 5 ]);
                }
                if ( argc >= 7 ) {
                    options[ 3 ] = atoi(argv[ 6 ]);
                }

                cout << "options " << options[ 0 ] << ", " << options[ 1 ] << ", " << options[ 2 ] << ", " << options[ 3 ] << endl;
             
                if ( "BRUTE" == hyp_strategy ) {

                    /* Check that options are valid */
                    if ( ( options [ 0 ] < options[ 1 ] ) && 
                         ( options [ 2 ] < options[ 3 ] ) ) {

                        ML_Hypothesis_Brute hyp_brute( filename );
                        hyp_brute.Init( options[ 0 ], options[ 1 ], options[ 2 ], options[ 3 ] );
                        hyp_brute.DisplayTrainingSet();
                        hyp_brute.Solve();
                    } else {
                        cout << "Invalid options - re-enter " << endl;
                    }

                } else if ( "GRADIENT" == hyp_strategy ) {
                    ML_Hypothesis_Gradient hyp_gradient( filename );
                    hyp_gradient.Init( options[ 0 ], options[ 1 ], options[ 2 ], options[ 3 ] );
                    hyp_gradient.DisplayTrainingSet();
                    hyp_gradient.Solve();
                } else {
                    cout << "Invalid learning strategy: " << hyp_strategy << endl;
                }
            } else {
                cout << "No learning strategy provided" << endl;
            }
        }
    }
    cout << "Mainline end" << endl;
    return 0;
}
