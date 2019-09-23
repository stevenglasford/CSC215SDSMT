#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

void fillArray6( int arr[][6], int row, int col);
void printArray6( int arr[][6], int row, int col );

void fillArray4( int arr[][4], int row, int col);
void printArray4( int arr[][4], int row, int col );

int main()
{
    int arr6[2][6];
    int arr4[3][4];



    fillArray6( arr6, 2, 6);
    fillArray4( arr4, 3, 4);

    printArray6( arr6, 2, 6 );
    printArray4( arr4, 3, 4 );

    return 0;
}

void fillArray6( int arr[][6], int row, int col)
{
    int i,j;
    default_random_engine generator;
    uniform_int_distribution<int> distribute( 1000,9999);

    generator.seed( unsigned (time(nullptr)));

    for(i=0; i<row; i++)
    {
        for( j=0; j<col; j++)
             arr[i][j] = distribute(generator);
    }
}


void printArray6( int arr[][6], int row, int col )
{
    int i,j;

    for(i=0; i<row; i++)
    {
        for( j=0; j<col; j++)
            cout << setw(5) << arr[i][j];
        cout << endl;
    }
    cout << endl;

}
void fillArray4( int arr[][4], int row, int col)
{
    int i,j;
    default_random_engine generator;
    uniform_int_distribution<int> distribute( 1000,9999);

    generator.seed( unsigned (time(nullptr)));

    for(i=0; i<row; i++)
    {
        for( j=0; j<col; j++)
             arr[i][j] = distribute(generator);
    }
}


void printArray4( int arr[][4], int row, int col )
{
    int i,j;

    for(i=0; i<row; i++)
    {
        for( j=0; j<col; j++)
            cout << setw(5) << arr[i][j];
        cout << endl;
    }
    cout << endl;

}