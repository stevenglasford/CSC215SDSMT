#include <iostream>

using namespace std;

unsigned long long int fib ( unsigned long long int n );

int main()
{
    // 42 months has a nice pause for computation
    unsigned long long int months;
    unsigned unsigned long long int rabbits;
    
    cout << "Enter the number of months" << endl;
    cin >> months;
    
    rabbits = fib ( months );
    cout << endl;
    cout << "You have " << rabbits << " pairs" << endl;
    
    return 0;
}


unsigned long long int fib ( unsigned long long int n )
{
    unsigned long long int alive;
    unsigned long long int born ;
    
    // write the base case first
    if ( n <= 2 )
    {
        return 1;
    }
    
    // return the computed average
    alive = fib(n-1);
    born = fib(n-2);
    return alive + born;
}
