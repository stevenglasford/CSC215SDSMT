#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Point
{
    int x;
    int y;
};

int main()
{
    int sum1 = 0;
    int x;
    double sum2 = 0.0;
    double y;
    char word[100];
    char line[100];
    Point p1;
    string str;

    // if entering integers
    while (cin >> x)
        sum1 += x;

    // if entering doubles
    while (cin >> y)
        sum2 += y;

    // if entering a word
    while (cin >> word)
        cout << word;

    // if entering a line
    while (cin.getline(word, 100))
        cout << line;

    // if entering a structure
    while (cin >> p1.x >> p1.y)
        cout << "(" << p1.x << "," << p1.y << ")" << endl;

    // if entering a structure
    while (cin >> p1.x)
    {
        cin >> p1.y;
        cout << "(" << p1.x << "," << p1.y << ")" << endl;
    }

    // reading in a word to a c++ string
    while( cin >> str )
        cout << str;

    // reading in a line to a c++ string
    while( getline( cin, str )
        cout << str;
    return 0;
}

int fromafile()
{
    int sum1 = 0;
    int x;
    double sum2 = 0.0;
    double y;
    char word[100];
    char line[100];
    Point p1;
    string str;

    ifstream fin("somefile.txt");
    ifstream bfin("anotherfile.bin", ios::binary | ios::in);

    // if reading a integers from a text file
    while (fin >> x)
        sum1 += x;

    // if reading a doubles from a text file
    while (fin >> y)
        sum2 += y;

    // if reading a word from a text file
    while (fin >> word)
        cout << word;

    // if reading a line from a text file
    while (fin.getline(word, 100))
        cout << line;

    // if reading a structure from a text file
    while (fin >> p1.x >> p1.y)
        cout << "(" << p1.x << "," << p1.y << ")" << endl;

    // if reading a structure from a text file
    while (fin >> p1.x)
    {
        fin >> p1.y;
        cout << "(" << p1.x << "," << p1.y << ")" << endl;
    }



    // if reading a integers from a binary file
    while (bfin.read((char*)&x, sizeof(int)))
        sum1 += x;

    // if reading a doubles from a binary file
    while (bfin.read((char*)&y, sizeof(double)))
        sum2 += y;

    // if reading a word from a binary file
    // assuming all words occupy 15 characters in file
    while (bfin.read(word, 15))
        cout << word;

    // if reading a structure from a binary file
    while (fin.read((char*)&p1, sizeof(Point)))
        cout << "(" << p1.x << "," << p1.y << ")" << endl;

    // reading in a word to a c++ string
    while( fin >> str )
        cout << str;

    // reading in a line to a c++ string
    while( getline( fin, str )
        cout << str;
}





