#include <iostream>
using namespace std;


void towers( int ndisks, int srcpole, int destpole, int sparepole);

int main()
{
   int num;

   cout << "Enter the number of disks on the pole: ";
   cin >> num;

   towers( num, 1, 3, 2);

   return 0;
}



void towers( int ndisks, int srcpole, int destpole, int sparepole)
{
   if( ndisks == 1 )
   {
      cout << "Move 1 disk from pole " << srcpole 
           << " to pole " << destpole << endl;
      return;
   }

   // need to move n-1 disks of the largest 
   // disk to the spare pole 
   towers( ndisks - 1, srcpole, sparepole, destpole );

   // move the largest disk
   towers( 1, srcpole, destpole, sparepole);

   // need to move the n-1 disks from the 
   // spare pole to the destination pole
   towers( ndisks - 1, sparepole, destpole, srcpole);
}