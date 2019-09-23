#include <iostream>

using namespace std;

void outputbin ( unsigned int val, int format = 1 );
int parity ( unsigned int val );


int main()
{
    int a = 216;
    int aparity = 0;

    cout << "Input Negative value to stop" << endl;
    cout << "Input Value: ";
    cin >> a;
    cout << endl;
    while ( a != 0 )
    {

        aparity = parity ( a );

        cout << "Decimal value: " << a << endl;

        cout << "\t";
        cout << "Binary Number: ";
        outputbin ( a );

        cout << "\t";
        cout << "Parity: " << ( aparity ? "1" : "0" ) << "   "
             << ( aparity ? "ODD" : "EVEN" ) << endl;


        cout << "\n\nInput Negative value to stop" << endl;
        cout << "Input Value: ";
        cin >> a;
        cout << endl;
    }

    return 0;
}

void outputbin ( unsigned int val, int format )
{
    unsigned int mask;
    unsigned int result = 0;
    int i;

    // shift 1 (bit pattern of 0000....00001 up (4)*8-1 = 31
    mask = 1 << ( sizeof ( val ) * 8 - 1 );

    // output the 32 bits of the unsigned integer (4*8)
    for ( i = 0; i < sizeof ( val ) * 8; i++ )
    {
        result = val & mask;
        cout << ( ( result ) ? 1 : 0 );

        if ( format && ( ( i + 1 ) % 8 == 0 ) )
        {
            cout << " ";
        }

        mask >>= 1;
    }
    cout << endl;
}



int parity ( unsigned int val )
{
    int i;
    int evenodd = 0;

    // same concept as the print binary.
    // no mask needed just use the lsb bit of 1 
    // and toggle value when a 1 is set
    for ( i = 0; i < sizeof ( val ) * 8; i++ )
    {
        // 4 possibilities base on val & 1
        // evenodd = 0    val & 1 = 0   // do not change state 0 ^ 0 = 0
        // evenodd = 0    val & 1 = 1   // change state 0 ^ 1 = 1
        // evenodd = 1    val & 1 = 0   // do not change state 1 ^ 0 = 1
        // evenodd = 1    val & 1 = 1   // change state 1 ^ 1 = 0
        evenodd = evenodd ^ ( val & 1 ); // gives 0 for even 1 for odd
        val >>= 1;
    }

    return evenodd;
}
