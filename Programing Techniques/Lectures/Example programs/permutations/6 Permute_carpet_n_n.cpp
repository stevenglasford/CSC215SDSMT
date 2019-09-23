#include <iostream>
#include <string>
using namespace std;

void permute( int *p, int *used, int n, string items[], int pos );

int main()
{
    int p[100] = {0};
    int used[100] = {0};
    int n = 5;
    int pos = 0;
    string carpets[10] = {"Red", "Blue", "Green", "Orange", "Black",
                          "White", "Gray", "Eggshell", "Turqoise", "Aqua"};

    permute( p, used, n, carpets, pos );

    return 0;
}

void permute( int *p, int *used, int n, string items[], int pos )
{
    int i;

    if( pos == n)
    {
        for( i=0; i<n; i++)
            cout << items[ p[i] ] << " ";
        cout << endl;
        return;
    }

    for( i=0; i<n; i++)
    {
        if( used[i] == 0 )
        {
            p[pos] = i;
            used[i] = 1;
            permute( p, used, n, items, pos+1 );
            used[i] = 0;
        }
    }
}
