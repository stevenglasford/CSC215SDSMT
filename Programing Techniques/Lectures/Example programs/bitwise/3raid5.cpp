#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

typedef unsigned char byte;

int main()
{
   int disk;

   byte a = 169;  // byte on disk 1
   byte b = 120;  // byte on disk 2
   byte c = 192;  // byte on disk 3
   byte d = 240;  // byte on disk 4
   byte e;        // byte on disk 5
   byte result;

   e = a ^ b ^ c ^ d;   // calculate the error code for redundancy 

   cout << "Enter (1-5) for which disk fails" << endl;
   cin >> disk;

   if( disk == 1 )
   {
      result = b ^ c ^ d ^ e;
   }
   else if( disk == 2 )
   {
      result = a ^ c ^ d ^ e;
   }
   else if( disk == 3 )
   {
      result = a ^ b ^ d ^ e;
   }
   else if ( disk == 4 )
   {
      result = a ^ b ^ c ^ e;
   }
   else if ( disk == 5 )
   {
      result = a ^ b ^ c ^ d ;
   }

   cout << "The missing byte is: " << (int)result << endl;
   return 0;
   
}