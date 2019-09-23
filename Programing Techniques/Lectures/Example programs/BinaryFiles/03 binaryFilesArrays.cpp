#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void write10( int *ptr);

int main()
{
    int size = 0;
    int *ptr = nullptr;
    ifstream fin;
    ofstream fout;

    fin.open( "03_1M.bin", ios::binary | ios::in);
    if( !fin )
    {
        cout << "Unable to open file: 1M.bin" << endl;
        return 1;
    }

    fout.open( "03_1Msort.bin", ios::binary | ios::out | ios::trunc);
    if( !fout )
    {
        fin.close();
        cout << "Unable to open file: 1Msort.bin" << endl;
        return 1;
    }

    fin.seekg(0,ios::end);
    size = (int)fin.tellg() / sizeof(int);

    ptr = new (nothrow) int [size];
    if( ptr == nullptr )
    {
        cout << "Unable to allocate memory" << endl;
        return 2;
    }

    fin.seekg(0,ios::beg);

    fin.read( (char *) ptr, size* sizeof(int) );

    write10( ptr );

    cout << endl << endl;

    sort( ptr, ptr + size );

    fout.write( (char *) ptr, size * sizeof(int) );

    write10( ptr );
    cout << endl << endl;

    fin.close();
    fout.close();
    delete [] ptr;

    return 0;
}

void write10( int *ptr)
{
    int i;

    for(i=0; i<100; i++)
    {
        cout << ptr[i] << " ";
        if( (i+1)%10 == 0)
            cout << endl;
    }

    for( i=999900; i<1000000; i++)
    {
        cout << ptr[i] << " ";
        if( (i+1)%10 == 0)
            cout << endl;
    }
}
