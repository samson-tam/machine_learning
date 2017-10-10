#include "ml_hypothesis_brute.hpp"
#include "ml_hypothesis_gradient.hpp"

#include <fstream>

using namespace std;

int main( int argc, char *argv[] ) {
 
    if ( argc >= 2  ) {
        ifstream data_file;
        string filename( argv[1] );
        if ( filename.empty()) {
            cout << "No filename provided for training set" << endl;
        } else {
            data_file.open( filename );
            if ( !data_file.is_open() ) {
                cout << "Could not open file:" << filename << endl;
                data_file.close();
            } else if ( argc >= 3 ) {
                string hyp_strategy( argv[2] );
                int options[4] = { 0, 0, 0, 0 };
                if ( argc >= 4 ) {
                    options[0] = atoi(argv[3]);
                }
                if ( argc >= 5 ) {
                    options[1] = atoi(argv[4]);
                }
                if ( argc >= 6 ) {
                    options[2] = atoi(argv[5]);
                }
                if ( argc >= 7 ) {
                    options[3] = atoi(argv[6]);
                }
             
                if ( "BRUTE" == hyp_strategy ) {
                    ML_Hypothesis_Brute hyp_brute( filename );
                    hyp_brute.Init( options[0], options[1], options[2], options[3] );
                    hyp_brute.Solve();
                } else if ( "GRADIENT" == hyp_strategy ) {
                    ML_Hypothesis_Gradient hyp_gradient( filename );
                    hyp_gradient.Init( options[0], options[1], options[2], options[3] );
                    hyp_gradient.Solve();
                } else {
                    cout << "Invalid learning strategy: " << hyp_strategy << endl;
                }
                data_file.close();
            } else {
                cout << "No learning strategy provided" << endl;
            }
        }
    }
    cout << "Mainline end" << endl;
    return 0;
}
