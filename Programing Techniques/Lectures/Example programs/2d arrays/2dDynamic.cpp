#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

int **alloc2d( int row, int col);
void fillArray( int **ptr, int row, int col);
void free2d( int **ptr, int row);
void printArray( int ** ptr, int row, int col );

int main()
{
    int **ptr1 = nullptr;
    int **ptr2 = nullptr;

    ptr1 = alloc2d( 2, 6);
    ptr2 = alloc2d( 3, 4);
    if( ptr1 == nullptr || ptr2 == nullptr )
    {
        cout << "Unable to allocate memory" << endl;
        free2d( ptr1, 2 );
        free2d( ptr2, 3 );
        return 1;
    }


    fillArray( ptr1, 2, 6);
    fillArray( ptr2, 3, 4);

    printArray( ptr1, 2, 6 );
    printArray( ptr2, 3, 4 );

    free2d( ptr1, 2 );
    free2d( ptr2, 3 );
    return 0;
}

int **alloc2d( int row, int col)
{
    int i;
    int **ptr = nullptr;

    ptr = new (nothrow) int *[row];
    if( ptr == nullptr )
        return nullptr;

    for( i=0; i<row; i++)
    {
        ptr[i] = new (nothrow) int [col];
        if( ptr[i] == nullptr )
        {
            free2d( ptr, i);
            return nullptr;
        }
    }
    return ptr;
}
void fillArray( int **ptr, int row, int col)
{
    int i,j;
    default_random_engine generator;
    uniform_int_distribution<int> distribute( 1000,9999);

    generator.seed( unsigned (time(nullptr)));

    for(i=0; i<row; i++)
    {
        for( j=0; j<col; j++)
             ptr[i][j] = distribute(generator);
    }
}

void free2d( int **ptr, int row)
{
    int i;

    if( ptr == nullptr )
        return;

    for( i=0; i<row; i++)
        delete [] ptr[i];

    delete [] ptr;
    ptr = nullptr;
}


void printArray( int ** ptr, int row, int col )
{
    int i,j;

    for(i=0; i<row; i++)
    {
        for( j=0; j<col; j++)
            cout << setw(5) << ptr[i][j];
        cout << endl;
    }
    cout << endl;

}