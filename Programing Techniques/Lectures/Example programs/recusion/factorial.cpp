#include <iostream>
using namespace std;

unsigned long int factorial ( unsigned long int n );

int main()
{
    unsigned long int  num;
    unsigned long int  result;
    
    cout << "Enter the value to compute the factorial of: ";
    cin >> num;
    
    result = factorial ( num );
    cout << "The factorial of " << num << " (" << num << "!) is: "
         << result << endl;
    return 0;
}

unsigned long int  factorial ( unsigned long int  n )
{
    unsigned long int ans;
    
    if ( n == 0 )
    {
        return 1;
    }
    
    // we have not reached the base case
    // compute the factorial of n-1
    ans = n * factorial ( n - 1 );
    return ans;
}
