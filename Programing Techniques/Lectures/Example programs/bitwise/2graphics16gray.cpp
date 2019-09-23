#include <iostream>

using namespace std;

typedef unsigned char pixel;


int main()
{
    // comppixel is a byte that is extracted from
    // a 4bit grayscale image ( 16 shades )
    // each pixel contains 2 shades

    // two compressed numbers bin 1101 0101
    // pixel1 = 5   - has bit pattern of 0000 0101
    // pixel2 = 13  - has bit pattern of 0000 1101
    pixel comppixel = 213;
    pixel newpixel = 0;

    // binary mask to extract values 00001111
    pixel mask = 15;
    //pixel mask = 0x0F; // hex assignment
    //pixel mask = 017;  // octal assignement

    pixel pix1, pix2;    // storage for the two integer shades

    // get the first value from the upper for bits
    pix1 = comppixel & mask;
    // get the second value from the lower bits
    pix2 = ( comppixel >> 4 ) & mask;

    cout << "Pixel one's color value: " << ( int ) pix1 << endl;
    cout << "Pixel two's color value: " << ( int ) pix2 << endl;

    // Exercise - put the two values back into a single
    // variable named newpixel



    return 0;
}