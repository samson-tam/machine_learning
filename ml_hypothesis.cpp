/* 
 * ml_hypothesis.cpp - base class for learning algorithm hypothesis
 *
 */
#include "ml_hypothesis.hpp"

#include <fstream>
#include <exception>

using namespace std;

/*
 * base constructor
 */
ML_Hypothesis::ML_Hypothesis( string filename ) {
    cout << "ML_Hypothesis constructor called" << endl;
    ReadTrainingSet( filename );
}

/*
 * base destructor
 */
ML_Hypothesis::~ML_Hypothesis( void ) {
    cout << "ML_Hypothesis deconstructor called" << endl;
}

/*
 * read training set data from filename
 * data in form of < input >, < output > CR/LF
 * max line length 256
 */
void ML_Hypothesis::ReadTrainingSet( string filename ) {
    ifstream data_file;
    char line_data[ 256 ];
    string input_value_string, output_value_string;
	size_t match_pos, input_pos, output_pos, del_pos;
	int line_no = 0;
    num_items = 0;
    data_file.open( filename );
    while ( 1 ) {

        data_file.getline( line_data, 256 );
        if ( data_file.eof()) {
           break;
        }

        string line_string ( line_data );
        line_no++;

        del_pos = line_string.find( ',' );
        match_pos = line_string.find_first_not_of( "-1234567890," );
        input_pos = line_string.find_first_of( "-1234567890" );
        output_pos = line_string.find_first_of( "-1234567890", del_pos );

        /* Ignore any lines that do not have integer value or ,
         * Check for ','.  If can find it, then can not differentiate
         *  input from output
         * Check that integer exists before and after ','
         */
        if ( line_string.npos == match_pos ) {

            if ( line_string.npos == del_pos ) {
                cout << "Invalid line of data - skip line  " << line_no << endl;
            } else if ( ( input_pos > del_pos ) || ( line_string.npos == input_pos ) ) {
                cout << "Invalid input entry - skip line  " << line_no << endl;
            } else if ( line_string.npos == output_pos ) {
                cout << "Invalid output entry - skip line  " << line_no << endl;
            } else {
                try {
                    input_value_string = line_string.substr( 0, del_pos );
                    output_value_string = line_string.substr( del_pos + 1, line_string.npos - del_pos );
                    input.push_back( stoi( input_value_string ) );
                    output.push_back( stoi( output_value_string ) );
                    num_items++;
                } catch ( exception &e ) {
                    cout << e.what() << " - skip line " << line_no << endl;
                }
            }
        } else {
            cout << "Found illegal characters - skip line  " << line_no << endl;
        } 
    }
}

/*
 * display training set data - verify read file properly
 */
void ML_Hypothesis::DisplayTrainingSet( void ) {
   int counter;
   cout << "Number of items " << num_items << endl;
   if ( num_items > 0 ) {
       for ( counter = 0; counter < num_items; counter++ ) {
           cout << "Data "<< counter + 1 << ": Input = " << input.at( counter ) << ", Output = " << output.at( counter ) << endl;
       } 
   } else {
       cout << "Empty data set - nothing to display " << endl;
   }
}

