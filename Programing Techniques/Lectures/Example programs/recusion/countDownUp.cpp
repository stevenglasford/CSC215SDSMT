#include <iostream>

using namespace std;

void recursiveIntro( int n );

int main()
{
    recursiveIntro(5);

    return 0;
}

void recursiveIntro( int n )
{
    if (n <= 0)
    {
        cout << "Base Case reached, back out printing n" << endl;
        return;
    }

    cout << n << endl;
    recursiveIntro( n-1 );
    cout << n << endl;
}
