/*!
 * @file
 *
 * @mainpage
 *
 * @brief A short code snippet that demonstrates using enums with arrays.
 *
 * @authors Fred Flintstone, Barney Rubble
 *
 * @par Instructor:
 *      Roger Schrader
 * @par Course:
 *      CSC 215 - Section 1 @ 1:00pm
 *
 * @par Description:
 * This code is used in the CSC 250 class to demonstrate how to
 * use enums with arrays.  The code does nothing spectacular.
 *
 * @par Compiling Instructions:
 * none
 *
 * @par Usage:
 *  arrayenum.exe
 */
#include <iostream>
using namespace std;
/*!
 * @brief An enumerated type for the Days of the week.
 *
 * @details Sun = 0 to Sat = 6.  Valid Constants are
 * Sun, Mon, Tue, Wed, Thu, Fri, and Sat
 */
enum days { Sun, /*!< Will represent the day Sunday
                      and have a numeric value of 0 */
            Mon, /*!< Will represent the day Monday
                      and have a numeric value of 1 */
            Tue, /*!< Will represent the day Tuesday
                      and have a numeric value of 2 */
            Wed, /*!< Will represent the day Wednesday
                      and have a numeric value of 3 */
            Thu, /*!< Will represent the day Thursday
                      and have a numeric value of 4 */
            Fri, /*!< Will represent the day Friday
                      and have a numeric value of 5 */
            Sat  /*!< Will represent the day Saturday
                  *   and have a numeric value of 6 */
          };

/* need to add doxygen function header */
int main()
{
    // declare a counter for loops to walk through all the days
    days i;
    // the current day of the week
    days curDay = Sun;
    int dayValue = 0;
    
    // number of workers on a given day
    int workers[7] = {0, 2, 4, 6, 8, 10, 0};
    
    // For loop is easy to see it is walking through the seven days of the week
    for ( i = Sun; i <= Sat; i = days ( i + 1 ) )
    {
        cout << "Number of workers on day " << i ;
        cout << " is:  " << workers[i] << endl;
    }
    
    cout << endl << endl;
    
    // change the current day to Wednesday, not the typecast
    cout << "Sun=0, Mon=1 .... Fri=5, Sat=6" << endl;
    cout << "Enter the number representing the weekday: ";
    cin >> dayValue;
    
    if ( dayValue >= 0 && dayValue <= 6 )
    {
        curDay = days ( dayValue );
    }
    
    
    cout << "Number of workers on Wednesday "  ;
    cout << " is:  " << workers[curDay] << endl << endl;
    
    return 0;
}










