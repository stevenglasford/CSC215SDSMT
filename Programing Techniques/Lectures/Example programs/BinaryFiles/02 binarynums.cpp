#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void outputBinaryFile(fstream &file);
void fillFiles( fstream &afile, fstream &bfile, int quantity);
int readNumber(fstream &file, int position);
void writeNumber(fstream &file, int position, int value);
void updateMultFive( fstream &file );

int main()
{
    int x;
    int num;
    int recallnum;
    fstream file;
    fstream file2;

    srand((unsigned)time(NULL));


    file2.open("02text.txt", ios::out | ios::in | ios::trunc);
    file.open("02binary.bin", ios::binary | ios::out | ios::in | ios::trunc);
    if (!file || !file2)
    {
        file.close();
        file2.close();
        cout << "Unable to open file" << endl;
        return 1;
    }

    cout << "Enter how many random numbers to store: ";
    cin >> num;

    // generate a random number and write it out to both files
    fillFiles(file2, file, num);
    cout << endl << endl;

    // read the numbers from a binary file
    outputBinaryFile(file);
    
    if( !file )
        cout << "File has an error" << endl;

    // seek to a give number and read its contents
    cout << endl;
    cout << "Enter which number to view(1 - " << num << "): ";
    cin >> recallnum;
    x = readNumber( file, recallnum);
    cout << "The " << recallnum << " number is using, ios::beg is : " 
         << x << endl;

    // recall the 8th number, multiply it by 10 and write it back out
    cout << endl;
    x = readNumber( file, 8);
    cout << "The old value for the 8th number is: " << x << endl;
    x *= 10;
    writeNumber( file, 8, x);
    cout << "The new value for the 8th number is: " << x << endl;

    outputBinaryFile(file);
    system("pause");

    // read the numbers from a binary file
    updateMultFive(file);
    outputBinaryFile(file);

    file.close();
    file2.close();

    return 1;
}

void outputBinaryFile(fstream &file)
{
    int i,
        num,
        val;

    // compute the number of integers in file
    file.clear();
    file.seekp(0, ios::end);

    // number of bytes in file divided by the size of an integer
    num = (int)file.tellg() / sizeof(int);

    // seek back to the beginning
    file.seekg(0, ios::beg);

    for (i = 0; i < num; i++)
    {
        file.read((char *)&val, sizeof(int));
        cout << "Number read in from file (" << i + 1
            << "): " << val << endl;
    }

    file.clear();
}

void fillFiles(fstream &afile, fstream &bfile, int quantity)
{
    int i,
        val;

    // clear all flags and move to beginning
    afile.clear();
    afile.seekp(0, ios::beg);

    bfile.clear();
    bfile.seekp(0, ios::beg);

    for (i = 0; i < quantity; i++)
    {
        val = rand();
        // write the number to a text file
        afile << val;
        if ((i + 1) % 10 == 0)
            afile << endl;
        else
            afile << " ";

        // write the number to a binary file
        bfile.write((char *)&val, sizeof(int));

        // output the number
        cout << "Number wrote to the file (" << i + 1
            << "): " << val << endl;
    }
}

int readNumber(fstream &file, int position)
{
    int val;
    streampos pos;


    // save current spot
    pos = (int)file.tellg();

    // move and read in the integer value
    file.clear();
    file.seekg( (position-1) * sizeof(int), ios::beg);
    file.read((char *)&val, sizeof(int));

    // return to original spot
    file.clear();
    file.seekg(pos, ios::beg);

    return val;
}

void writeNumber(fstream &file, int position, int value)
{
    streamoff pos;

    // save current spot
    pos = file.tellp();

    // move and read in the integer value
    file.clear();
    file.seekp((position-1) * sizeof(int), ios::beg);
    file.write((char *)&value, sizeof(int));

    // return to original spot
    file.clear();
    file.seekp(pos, ios::beg);

}



void updateMultFive( fstream &file )
{
    int value;
    int datasize = (int) sizeof(int);

    file.clear();
    file.seekg( 0,ios::beg);
    file.seekp( 0, ios::beg );
    
    while( file.read( (char *) &value, datasize) )
    {
        cout << value << " ==>";
        value *= 5;
        cout << value << endl;
        
        // location after a reading a number
        cout << "After Read   - Tellg() = " << file.tellg() << "\t\tTellp() = " 
             << file.tellp() << endl;

        // backup 4 bytes and output both locations
        file.seekp( -datasize, ios::cur);
        cout << "Before Write - Tellg() = " << file.tellg() << "\t\tTellp() = " 
             << file.tellp() << endl;
        
        // overwrite the old value with the new value
        file.write( (char *) &value, 4);
        
        // output both locations before reading next value
        cout << "After Write  - Tellg() = " << file.tellg() << "\t\tTellp() = " 
             << file.tellp() << endl;
        cout << endl << endl;
        
        file.seekg( file.tellg(), ios::beg);
    }

    file.clear();
    
}
