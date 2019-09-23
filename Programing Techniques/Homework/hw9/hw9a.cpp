#include <iostream>
#include <iomanip>

#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"

using namespace std;

int volume( int height, int baseSU );

int main(int argc, char **argv)
{
    int base1, base2;
    int height1, height2;
    int volume1, volume2;
    int remaining;
    int result = Catch::Session().run( argc, argv );

    if( result )
    {
        cout << "Failed to pass test cases" << endl;
        return 0;
    }

    // get the data for both boxes
    cout <<"Enter the larger box data" << endl;
    cout <<"Enter the area of the base: ";
    cin >> base1;
    cout << "Enter the height: ";
    cin >> height1;
    cout << endl << endl <<"Enter the smaller box data" << endl;
    cout <<"Enter the area of the base: ";
    cin >> base2;
    cout << "Enter the height: ";
    cin >> height2;

    // your code goes here





    // End of your code
    cout << "The small box would displace all but " << remaining
         << " cubic units of the larger box." << endl;
    
    return 0;
}


int volume( int height, int baseSU )
{
    // your recursive code goes here.




}


TEST_CASE( "VOLUME" )
{
    CHECK( volume( 0, 34 ) == 0 );
    CHECK( volume( 24, 0 ) == 0 );
    CHECK( volume( 8, 30 ) == 240 );
    CHECK( volume( 1, 10 ) == 10 );
    CHECK( volume( 3, 19 ) == 57 );

    // provide 5 more test cases.  
    // do not use negatives.  
    // Be creative and stick with values under 1000

}

