/*!
 * @file
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
    
int rolldice();
/*!
 * @brief An enumerated type to control the status of a game
 *
 * @details Continue means the game is active. Won means the plaeyr wond the 
 * game.  Lost means the player lost the game.
 */
enum Status {CONTINUE, /*!< Value of 0 for the game is not over */
             WON,      /*!< Value of 1 for the game has been won */
             LOST      /*!< Value of 2 for the game has been lost */
            };

int main()
{
    int sum, mypoint;
    // enumerated type for the status of the game
    Status gamestatus;
    
    srand ( ( unsigned int ) time ( NULL ) );
    sum = rolldice();
    
    // roll the dice for the first time
    switch ( sum )
    {
        // game is over and player won
        case 7:
        case 11:
            gamestatus = WON;
            break;
            
        // game is over and player lost
        case 2:
        case 3:
        case 12:
            gamestatus = LOST;
            break;
            
        // at least one more roll is needed.  Game must continue
        default:
            gamestatus = CONTINUE;
            mypoint = sum;
            cout << "Point is " << mypoint << endl;
            break;
    }
    
    // while the game is not over
    while ( gamestatus == CONTINUE )
    {
        sum = rolldice();
        
        // see if player won
        if ( sum == mypoint )
        {
            gamestatus = WON;
        }
        // see if player lost
        else if ( sum == 7 )
        {
            gamestatus = LOST;
        }
    }
    
    // check how the game ended.
    if ( gamestatus == WON )
    {
        cout << "Player wins" << endl;
    }
    else
    {
        cout << "Player loses" << endl;
    }
    
    
}

int rolldice()
{
    int die1, die2, worksum;
    
    die1 = 1 + rand() % 6;
    die2 = 1 + rand() % 6;
    
    worksum = die1 + die2;
    cout << "Player rolled " << die1 << " + " << die2
         << " = " << worksum << endl;
    return worksum;
}