#include <iostream>
using namespace std;

void print_bin ( char abyte );


void print_bin(char abyte)
{
    int i;
    // take bit pattern 0000 0001 and shift it seven
    // places to the left to become 1000 0000
    int mask = 1 << 7;

    for (i = 0; i < 8; i++)
    {
        cout << (abyte & mask ? "1" : "0");
        mask >>= 1;
    }
}


int main()
{
    char lower, upper;
    char ch;

    cout << "What is different between the upper and lower case characters"
         << endl;
    for ( lower = 'a', upper = 'A'; lower <= 'z'; lower++, upper++ )
    {
        cout << lower << " = ";
        print_bin ( lower );
        cout << "   " << upper << " = ";
        print_bin ( upper );
        cout << endl;
    }

    cout << "convert lower to upper case" << endl;
    // never put this in your assignments unless requested
    // to do so.
    system ( "pause" );





    // clear the 6th bit, use a mask of 223 -> 1101 1111
    cout << "do a bitwise & on the character to clear the bit"
         << endl;
    for ( ch = 'a'; ch <= 'z'; ch++ )
    {
        upper = ch & 223;	
        cout << ch << " --> " << upper << endl;
    }

    cout << "Convert Upper to lower case" << endl;
    system ( "pause" );


    // set the 6th bit, use a mask of 32 -> 0010 0000
    // could have done a ~223
    cout << "do a bitwise | on the character to set the bit"
         << endl;
    for ( ch = 'A'; ch <= 'Z'; ch++ )
    {
        lower = ch | 32; 
        cout << ch << " --> " << lower << endl;

    }

    return 0;
}

