#include <cstring>
#include <iostream>
using namespace std;

void backwards1(char str[], int position);
void backwards2(char *str, int position);

void main()
{
   char string[] = "This is my string to print backwards";

   // call method 1, print char after the remaining n-1 characters
   backwards1(string, 0);
   
   cout << endl;

   // call method 2, print the first n-1 characters then print this character
   backwards2(string, (int)strlen(string)-1);

   cout << endl;

}

void backwards1(char str[], int position)
{
   // see if we have reached the end of the array
   if(str[position] == '\0')
      return;

   //move forward one position
   backwards1(str, position+1);

   // as we come back through recursion print characters
   cout << str[position];
}


void backwards2(char *str, int position)
{
   // see if we have stepped of the front of the array
   if( position < 0 )
      return;

   // as we move backwards print character first
   cout << str[position];

   // move backwards one position
   backwards2(str , position-1);
}
