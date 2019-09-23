/*!
 * @file
 */
#include <iostream>

using namespace std;
/*!
 * @brief enumerated variable to hold menu actions
 */
enum menu {ADD = 1,  /*!< entry to add some record    */
           DEL,      /*!< entry to delete some record */
           FIND,     /*!< entry to locate some record */
           PRINT,    /*!< entry to print off a record */
           BILL,     /*!< entry to bill some body     */
           QUIT};    /*!< entry to quit the program   */

/*!
 * @brief Constant character array that holds the menu that is printed.
 *
 * The lines must correspond to the enumerated action.
 * row 0 is not used
 * enumeration value 1 will match with row 1.
 * enumeration value 2 will match with row 2.
 * etc.
 */
const char MENUTEXT[8][45] =
{
    "",
    ". Add a customer",
    ". Delete a customer",
    ". Find a customer",
    ". Print a customer", 
    ". Bill a customer",
    ". Quit Program"
};
/*!
 * @brief This is the entry point to the program
 *
 * @details Simulates using enums to do menu actions on a customer
 *          database.  There is no database and only an output statement
 *          comes to the screen.
 *
 * @returns 0 for no errors occurred.
 */
int main()
{
    int a[3] = {0, 1, 2};
    menu action;
    int i;
    int choice = 1;

    // keep asking for a choice
    while ( choice != QUIT )
    {
        // print the menu out and input a choice
        for ( i = ADD; i <= QUIT; i++ )
        {
            cout << i << MENUTEXT[i] << endl;
        }

        cout << "Enter Your choice: ";
        cin >> choice;

        // do the requested action
        // if invalid output error message
        action = menu(choice);

        switch ( action )
        {
            default:
                cout << "\nInvalid option -- Try again\n" << endl;
                break;
            
            case PRINT:
                cout << "\nPrint a customer\n" << endl;
                break;

            case ADD:
                cout << "\nCode to add a customer\n" << endl;
                break;

            case DEL:
                cout << "\nCode to delete a customer\n" << endl;
                break;

            case FIND:
                cout << "\nCode to find a customer\n" << endl;
                break;

            case BILL:
                cout << "\nCode to bill a customer\n" << endl;
                break;

            case QUIT:
                return  0;
                break;
        }
    }

    return 0;
}
