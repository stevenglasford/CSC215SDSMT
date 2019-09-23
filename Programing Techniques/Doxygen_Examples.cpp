/*************************************************************************//**
 * @file
 *
 * @mainpage Doxygen Howto
 *
 * @section course_section Course Information
 *
 * @author Roger Schrader
 *
 * @date 9/19/2014
 *
 * @par Professor:
 *         Roger Schrader
 *
 * @par Course:
 *         CSC 250
 *
 * @par Location:
 *         McLaury - Room 214
 *
 * @section program_section Program Information
 *
 * @details This program demonstrates how to document your source code.
 *
 * THe program header (this section) goes into one file only.  Usually
 * where the main function is located.
 *
 * Note the \@file at the top of the file.  This tells doxygen to document
 * this file.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      Not a real program
 *
 * @par Usage:
   @verbatim
   c:\> d.exe
   d:\> c:\bin\d.exe
   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @bug none
 *
 * @todo none
 *
 * @par Modifications and Development Timeline:
   @verbatim
   Date           Modification
   -------------  -------------------------------------------------------------
   Sep  15, 2014  Added Program documenation for the Doxygen writeups
   Sep  15, 2014  Added the main functions documentation example
   Sep  16, 2014  Added read functions documentation example
   Sep  16, 2014  Added the removeInteger documentation example
   Sep  17, 2014  Added global constant documentation example
   Sep  17, 2014  Added define documentation example
   Sep  17, 2014  Added enumerated type documentation example
   Sep  18, 2014  Added typedef documentation example
   Sep  19, 2014  Added structure documentation example

   @endverbatim
 *
 *****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*!
 * @brief the value of PI carried out to ten decimal places
 */
const double PI = 3.14159265359;

/*!
 * @brief the maximum number of integers to be read into an array
 */
const int MAX_SIZE = 10000;

/*!
 * @brief the key used to encrypt and decrypt a private message
 */
#define KEY 938429281

/*!
 * @brief create enumerated type to hold the value for the current season
 */
enum Season
{
    WINTER,     /*!< Contains the value 0 representing the winter Season  */
    SPRING,     /*!< Contains the value 1 representing the Spring Season */
    SUMMER,     /*!< Contains the value 2 representing the Summer Season */
    FALL        /*!< Contains the vlaue 3 representing the Fall Season   */
};

/*!
 * @brief byte contains a value for a single pixel within an image.
 */
typedef unsigned char byte;

/*!
 * @brief Holds information about a single student
 */
struct StudentRecord
{
    int id;          /*!< the student colleague number */
    string name;     /*!< proper name of the student associated with the id */
    double gpa;      /*!< current or final gpa for the student */
    string major;    /*!< the indented department with student belongs to*/
};

void readFile ( ifstream &fin, int *a, int &size );
void removeIntegers ( int *a, int &size, int tgt );


/**************************************************************************//**
 * @author Roger Schrader
 *
 * @par Description:
 * Note that ever variable being passed into the function is listed with a
 * \@param directive.  After the param directive you must specify [in],[out] or
 * [in,out].  Then the exact name of the variable follows with a description of
 * the parameter.  argc, this is an input parameter that contains the number of
 * command line arguments specified.  I do not modify this variable so the
 * OS gets it back, therefore it is an [in] type.  argv, this is an input
 * parameter that contains the arguments.  I do not modify the arguements for
 * the OS therefore it is an [in] type.  If the function is a valued function,
 * the return directive is used to indicate what is being returned from the
 * function.
 *
 * @param[in]      argc - a count of the command line arguments used to start
 *                        the program.
 * @param[in]     argv - a 2d character array of each argument.  Each token
 *                        occupies one line in the array.
 *
 * @returns 0 program ran successful.
 * @returns 1 the program fail or there was an error.
 *
 *****************************************************************************/
int main ( int argc, char **argv )
{
    return 0;
}

/**************************************************************************//**
 * @author Roger Schrader
 *
 * @par Description:
 * This function is will fill an array using a file that has already been
 * opened.  Size will contain the number of integers read.  fin is an input
 * and output parameter since it is opened outside the function.  We will then
 * change the where the file is at and return that.  a is the array that will
 * be filled.  It is an output parameter since it has no data coming in and the
 * function will populate it with data.  The size parameter is also an output
 * parameter since it is being changed to the number of integers read into the
 * array. No return directive is necessary since it is a void function.
 *
 * @param[in,out]  fin  - an ifstream that is already opened to read data from.
 * @param[out]     a    - an integer array to populate
 * @param[out]     size - the number of integers read from the file.
 *
 *****************************************************************************/
void readFile ( ifstream &fin, int *a, int &size )
{

}

/**************************************************************************//**
 * @author Roger Schrader
 *
 * @par Description:
 * This function will remove all instances of a specific integer from the
 * integer arry passed in.  Size will be decrement to so how many integers
 * were removed and represents the new size of the array.
 * a is both an input and output variable since it has data being passed in
 * and the data is being changed.  size is both an input and output variable
 * since it contains valid data coming in and will possibly change before
 * the function exits. tgt is just in input variable since it does not
 * change and go back to the calling function. No return directive is
 * necessary since it is a void function.
 *
 * @param[in,out]  a    - the array that contains the data to search and
 *                        remove from.
 * @param[in,out]  size - the number of integers stored in the array coming in
 *                        and the new size of the array when the function
 *                        exits.
 * @param[in]      tgt  - the item to remove all instances from the array.
 *
 *****************************************************************************/
void removeIntegers ( int *a, int &size, int tgt )
{

}



