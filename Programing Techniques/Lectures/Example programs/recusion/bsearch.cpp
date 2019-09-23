#include <iostream>
using namespace std;

int bsearch(int array[], int lower, int upper, int n);

void main()
{ 
    int array[] = {1, 4, 7, 8, 9, 15, 16, 20, 21};
    int n;
    int index;


    cout << endl << "Enter the integer value to search for: ";
    cin >> n;
    index = bsearch(array,0,8,n);
    if(index == -1)
    {
        cout << "Your number is not in the list" << endl;
    }
    else
    {
        cout << "The number " << n << " is found at index: " << index
             << endl;
    }

}


int bsearch(int array[], int lower, int upper, int n)
{
    int mid;

    // base case for when the lower and upper cross each other
    if( lower > upper)
        return -1;

    mid = (upper + lower) / 2;

    // see if we have found the number
    if(array[mid] == n)
        return mid;

    // if n is larger than the integer at mid search to the right 
    if( array[mid] < n)
        return bsearch( array, mid + 1, upper, n);

    // if n is smaller than the integer at mid search to the mid 
    return bsearch( array, lower, mid-1, n);	
}