#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "../catch.hpp"

using namespace std;

int stringCMP( string s1, string s2 , int pos);

int main( int argc, char **argv)
{
    string s1, s2;
    int compareValue;
    int result = Catch::Session().run( argc, argv );

    if( result )
    {
        cout << "You failed to pass some test cases" << endl;
        return 1;
    }

    // get two strings
    cout << "Enter String 1: ";
    getline( cin, s1 );
    cout << "Enter String 2: ";
    getline( cin , s2 );

    // compare and output the returned results.
    compareValue = stringCMP( s1, s2, 0);
    if( compareValue == 0 )
        cout << "The strings are equal." << endl;
    else if( compareValue > 0 )
        cout << s1 << " is greater than " << s2 << endl;
    else
        cout << s1 << " is less than " << s2 << endl;

    return 0;
}

int stringCMP( string s1, string s2, int pos)
{
    // your code goes here.




}

TEST_CASE( "Case insensitive String Compare - recursive" )
{
    string s1 = "Hello";
    string s2 = "HELLO";
    string s3 = "elephanT";
    string s4 = "elePhant";

    string s5 = "Zebra";
    string s6 = "orange";
    string s7 = "banana";
    string s8 = "Ample";

    string p1 = "apple_bananas";
    string p2 = "apples bananas";
    string p3 = "appleS bananas";

    SECTION( "Equal" )
    {
        CHECK( stringCMP( s1, s2, 0 ) == 0 );
        CHECK( stringCMP( s2, s1, 0 ) == 0 );
        CHECK( stringCMP( s3, s4, 0 ) == 0 );
        CHECK( stringCMP( s4, s3, 0 ) == 0 );
    }
    SECTION ("Less than" )
    {
        CHECK( stringCMP( s8, s7, 0 ) < 0 );
        CHECK( stringCMP( s8, s6, 0 ) < 0 );
        CHECK( stringCMP( s8, s5, 0 ) < 0 );
        CHECK( stringCMP( s8, s1, 0 ) < 0 );
        CHECK( stringCMP( s8, s2, 0 ) < 0 );
        CHECK( stringCMP( s8, s3, 0 ) < 0 );
        CHECK( stringCMP( s8, s4, 0 ) < 0 );
        CHECK( stringCMP( s7, s6, 0 ) < 0 );
        CHECK( stringCMP( s7, s5, 0 ) < 0 );
        CHECK( stringCMP( s7, s1, 0 ) < 0 );
        CHECK( stringCMP( s7, s2, 0 ) < 0 );
        CHECK( stringCMP( s7, s3, 0 ) < 0 );
        CHECK( stringCMP( s7, s4, 0 ) < 0 );
        CHECK( stringCMP( s6, s5, 0 ) < 0 );
    }
    SECTION ("Greater than" )
    {
        CHECK( stringCMP( s7, s8, 0 ) > 0 );
        CHECK( stringCMP( s6, s8, 0 ) > 0 );
        CHECK( stringCMP( s5, s8, 0 ) > 0 );
        CHECK( stringCMP( s1, s8, 0 ) > 0);
        CHECK( stringCMP( s2, s8, 0 ) > 0 );
        CHECK( stringCMP( s3, s8, 0 ) > 0 );
        CHECK( stringCMP( s4, s8, 0 ) > 0 );
        CHECK( stringCMP( s6, s7, 0 ) > 0 );
        CHECK( stringCMP( s5, s7, 0 ) > 0 );
        CHECK( stringCMP( s1, s7, 0 ) > 0 );
        CHECK( stringCMP( s2, s7, 0 ) > 0 );
        CHECK( stringCMP( s3, s7, 0 ) > 0 );
        CHECK( stringCMP( s4, s7, 0 ) > 0 );
        CHECK( stringCMP( s5, s6, 0 ) > 0 );
    }
    SECTION( "Characters Between upper and lower case" )
    {
        // '_' comes before 's'
        CHECK( stringCMP( p1, p2, 0 ) < 0 );
        // 's' comes after '_'
        CHECK( stringCMP( p2, p1, 0 ) > 0 );
        // 'S' comes before '_'
        CHECK( stringCMP( p3, p1, 0 ) < 0 );
        // '_' comes after 'S'
        CHECK( stringCMP( p1, p3, 0 ) > 0 );
    }

    SECTION( "My Test Cases" )
    {

    }
}
