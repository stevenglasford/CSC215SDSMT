#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct rec
{
    int id;
    char name[30];
    int grades[3];
    float average;
};

int main()
{
    int count;
    int filesize;
    int i, j;
    int sum;

    rec *recptr=nullptr;
    rec temp;

    fstream file;
    file.open("04 structbinary.bin", ios::binary | ios::out | 
                                  ios::in | ios::trunc);
    if (!file)
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(2);

    // enter in three students and write to binary files
    for (i = 0; i < 3; i++)
    {
        cout << "Enter Student ID: ";
        cin >> temp.id;

        cin.ignore();
        cout << "Enter Student Name: ";
        cin.getline(temp.name, 30);

        sum = 0;
        for (j = 0; j < 3; j++)
        {
            cout << "Enter the Students " << j << " test score: ";
            cin >> temp.grades[j];
            sum += temp.grades[j];
        }
        temp.average = sum / float(3.0);
        file.write((char *)&temp, sizeof(rec));
    }

    cout << "\n\n\n=============================\n\n\n" << endl;








    file.seekg(0, ios::end);
    // find out how many records are in the file
    filesize = (int)file.tellg();
    count = filesize / sizeof(rec);
    file.seekg(0, ios::beg);


    // read in the three students from the binary file
    // and output the information to the screen
    for (i = 0; i < count; i++)
    {
        file.read((char *)&temp, sizeof(rec));

        cout << setw(3) << temp.id << "  ";
        cout.setf(ios::left);
        cout << setw(30) << temp.name << endl << "\t\tTests: ";
        cout.unsetf(ios::left);

        for (j = 0; j < 3; j++)
        {
            cout << setw(4) << temp.grades[j] << "  ";
        }
        cout << endl << "\t\tAverage: "
            << setw(5) << temp.average << endl;
    }

    cout << "\n\n\n=============================\n\n\n" << endl;










    file.clear(0);
    file.seekg(0, ios::end);
    filesize = (int)file.tellg();

    // compute the number of records in the file
    count = filesize / sizeof(rec);
    file.seekg(0, ios::beg);

    // dynamically allocate enough records to 
    // hold the entire file
    recptr = new (nothrow) rec[count];
    if (recptr == NULL)
    {
        cerr << "Unable to allocate array" << endl;
        return 1;
    }

    // fill the array with the information from the file
    file.read((char *)recptr, count * sizeof(rec));
    for (i = 0; i < count; i++)
    {
        cout << setw(3) << recptr[i].id << "  ";
        cout.setf(ios::left);
        cout << setw(30) << recptr[i].name << endl << "\t\tTests: ";
        cout.unsetf(ios::left);

        for (j = 0; j < 3; j++)
        {
            cout << setw(4) << recptr[i].grades[j] << "  ";
        }
        cout << endl << "\t\tAverage: "
            << setw(5) << recptr[i].average << endl;

    }

    delete[] recptr;

    file.close();
    return 0;
}