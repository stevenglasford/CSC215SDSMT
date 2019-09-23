#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

void printBoard ( int chessBoard[], int n );

void setupLines(string &topLine, string &line, string &bottomLine, 
                int lineLength);

void nqueens ( int p[], int usedrows[],
               int usedPosDiag[], int usedNegDiag[],
               int n, int currcol );

int main()
{
    int n;
    int startcol = 0;
    int p[8] = {0};
    int rows[8] = {0};
    int usedPosDiag[2 * 8 - 1] = {0};
    int usedNegDiag[2 * 8 - 1] = {0};
    
    cout << "enter the number of rows/cols for the board (4-8): ";
    cin >> n;
    if ( n < 0 || n > 8 )
    {
        cout << "Value is out of the range 4-8" << endl;
        return 1;
    }

    nqueens ( p, rows, usedPosDiag, usedNegDiag, n, startcol );

    return 0;
}



void nqueens ( int p[], int usedRows[],
               int usedPosDiag[], int usedNegDiag[],
               int n, int currcol )
{
    int row;
    
    if ( currcol == n )
    {
        printBoard ( p, n );
        cout << endl;
        cout << endl;
        return;
    }
    
    for ( row = 0; row < n; row++ )
    {
        if ( usedRows[row] == 0 && usedPosDiag[ row + currcol ] == 0 &&
                usedNegDiag[ row - currcol + ( n - 1 ) ] == 0 )
        {
            // step 1
            p[currcol] = row;
            usedRows[row] = 1;
            usedPosDiag[ row + currcol ] = 1;
            usedNegDiag[ row - currcol + ( n - 1 ) ] = 1;
            
            // step 2
            nqueens ( p, usedRows, usedPosDiag, usedNegDiag, n, currcol + 1 );
            
            
            // step 3
            usedRows[row] = 0;
            usedPosDiag[ row + currcol] = 0;
            usedNegDiag[ row - currcol + ( n - 1 ) ] = 0;
        }
    }
}
void printBoard ( int chessBoard[], int n )
{
    char verticalChar = (char)186;
    int r, c;
    int lineLength = n*4+1;
    string topLine;
    string bottomLine;
    string line;

    setupLines(topLine, line, bottomLine, lineLength );

    cout <<  "Row:  ";
    for ( r = 0; r < n; r++ )
    {
        cout << setw ( 4 ) << chessBoard[r];
    }
    cout << endl;
    cout << topLine << endl;
    for ( r = 0; r < n; r++ )
    {
        cout << "       ";
        for ( c = 0; c < n; c++ )
            if ( r == chessBoard[c] )
            {
                cout << verticalChar << " Q ";
            }
            else
            {
                cout << verticalChar << "   ";
            }
        cout << verticalChar << endl;
        if( r < n-1 )
            cout << line<< endl;
    }
    cout << bottomLine << endl;
}

void setupLines(string &topLine, string &line, string &bottomLine, int lineLength)

{
    int c;
    line.resize(lineLength, (char)205);
    topLine = line;
    bottomLine = line;
    line = topLine;

    // right edge
    topLine[0] = (char)201;
    line[0] = (char)204;
    bottomLine[0] = (char)200;

    // left Edge
    topLine[topLine.size() - 1] = (char)187;
    line[line.size() - 1] = (char)185;
    bottomLine[topLine.size() - 1] = (char)188;

    // in the middle of all lines
    for (c = 4; c<lineLength - 1; c += 4)
    {
        topLine[c] = (char)203;
        line[c] = (char)206;
        bottomLine[c] = (char)202;
    }

    // add padding to shift board over 7 spaces
    topLine = "       " + topLine;
    line = "       " + line;
    bottomLine = "       " + bottomLine;
}
