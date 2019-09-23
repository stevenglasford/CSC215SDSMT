#include <iostream>
#include <fstream>

using namespace std;

int main()
{
   int num = 1633903975; // 01100001 01100011 01100101 01100111
                         //     a        c        e        g
   int num1;
   fstream file;
   char filename[] = "01intro.bin";
   
   file.open(filename, ios::in | ios::out | ios::binary | ios::trunc);
   if( !file )
   {
      cerr << "Unable to open file: " << filename << endl;
      exit (1);
   }

   // write out 3 numbers, 1633903975 1633903976 1633903977
   cout << "Writing " << num << endl;
   file.write( (char *) &num, sizeof(int) );

   num += 1;
   cout << "Writing " << num << endl;
   file.write( (char *) &num, sizeof(int) );

   num += 1;
   cout << "Writing " << num << endl;
   file.write( (char *) &num, sizeof(int) );

   
   // retrieve numbers using num1
   file.clear(0);
   file.seekg(0,ios::beg);
   file.read( (char *) &num1, sizeof(int) );
   cout << "First number written to the file: " << num1 << endl;

   file.seekg(-((int)sizeof(int)),ios::end);
   file.read( (char *) &num1, sizeof(int) );
   cout << "last number written to the file : " << num1 << endl;

   file.close();

   return 0;
}

