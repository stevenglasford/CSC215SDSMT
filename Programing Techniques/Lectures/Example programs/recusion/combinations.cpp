#include <iostream>
using namespace std;

long choose ( int n, int k );
long factorial ( long n );

void main()
{
    int numelements;
    int quantity;
    long result;
    
    cout << "Enter the number of elements in your set: ";
    cin >> numelements;
    
    cout << "Enter the number of element to choose from the set: ";
    cin >> quantity;
    
    cout << endl;
    result = choose ( numelements, quantity );
    cout << "There are " << result << " combinations" << endl;
    
    if ( result > 0 )
        result = factorial ( numelements ) /
                 ( factorial ( quantity ) * 
                   factorial ( numelements - quantity ) );
                 
    cout << "The result using the equation is " << result << endl;
    cout << endl;
}

long choose ( int n, int k )
{
    long withX;
    long withoutX;
    
    // c(n,0) = 1 and c(n,n) = 1
    if ( k == 0 || n == k )
    {
        return 1;
    }
    
    // c(n,k) where k > n
    if ( k > n )
    {
        return 0;
    }
    
    // pick one element from our set and get k-1 elements
    // we picked one element so we can not use it again, hence n - 1
    // we filled a slot, hence k - 1
    withX = choose ( n - 1, k - 1 );
    
    // find all possible combinations that exclude
    // the element choosen above, hence n-1
    // we still need to choose k number of elements though
    withoutX = choose ( n - 1, k );
    
    return withX + withoutX;
}

long factorial ( long n )
{
    // the factorial of zero is one
    if ( n == 0 )
    {
        return 1;
    }
    
    // we have not reached the base case
    // compute the factorial of n-1
    return n * factorial ( n - 1 );
}
