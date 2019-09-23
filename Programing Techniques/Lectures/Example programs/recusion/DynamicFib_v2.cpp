#include <iostream>

using namespace std;


unsigned long long int iterative_fib ( unsigned long long int n );
unsigned long long int dynamic_recursion_fib ( unsigned long long int n );

int main()
{
    unsigned long long int n = 64; 
    unsigned long long int answer;
    
    answer = iterative_fib ( n );
    cout << "Rabbits after " << n << " months is " << answer << " pairs.";
    cout << endl;
    
    answer = iterative_fib ( 5 );
    cout << "Rabbits after " << n << " months is " << answer << " pairs.";
    cout << endl;
    
    
    answer = dynamic_recursion_fib ( n );
    cout << "Rabbits after " << n << " months is " << answer << " pairs.";
    cout << endl;
    
    answer = dynamic_recursion_fib ( 5 );
    cout << "Rabbits after " << n << " months is " << answer << " pairs.";
    cout << endl;
    
    
    return 1;
}

unsigned long long int iterative_fib ( unsigned long long int n )
{
    unsigned long long int i;
    static unsigned long long int values[100] = {0, 1, 1};
    static unsigned long long int lastmonth = 2;
    
    if ( n < 0 )
    {
        return 0;
    }
    
    for ( i = lastmonth + 1; i <= n; i++ )
    {
        values[i] = values[i - 1] + values[i - 2];
        lastmonth = n;
    }
    
    return values[n];
}


unsigned long long int dynamic_recursion_fib ( unsigned long long int n )
{
    static unsigned long long int values[100] = {0, 1, 1};
    static unsigned long long int lastmonth = 2;
    
    // validate n
    if ( n < 0 )
    {
        return 0;
    }
    
    // see if we have computed that value already
    if ( n <= lastmonth )
    {
        return values[n];
    }
    
    // compute the new month
    values[n] = dynamic_recursion_fib ( n - 1 ) + 
                dynamic_recursion_fib ( n - 2 );
    lastmonth = n;
    return values[n];
}