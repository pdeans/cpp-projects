/************************************************************************************
 Program Name:      main.cpp - Driver for cppPolymorphism
 Author:            Patrick Stearns
 Date:              August 8, 2014
 Compiler:          Xcode 5
 OS:                OS X - 10.9.3
 Description:       Program takes in data for library holdings and outputs the data.
 Input Files:       None
 Output Files:      csis.txt
 ************************************************************************************/

#include <fstream>
#include "library.h"

using namespace std;

ofstream csis;

int main(int argc, const char * argv[])
{
    Holding** holding = new Holding*[5];

    csis.open("csis.txt");

    cout << "Enter holdings to be stored in a list: " << endl << endl;
    csis << "Enter holdings to be stored in a list: " << endl << endl;
    for (int i = 0; i < 5; i++) {
        holding[i] = setHolder();
    }

    cout << endl;
    cout << "Here are the holdings:" << endl << endl;
    csis << endl;
    csis << "Here are the holdings:" << endl << endl;
    for (int i = 0; i < 5; i++) {
        holding[i]->print();
    }

    csis.close();

    delete [] holding;

    return 0;
}

Holding * setHolder()
{
    char choice;
    char title[100];
    int number = 0;
    Holding *holder;

    cout << "Enter B for book or R for recording: ";
    cin >> choice;
    cin.ignore();
    csis << "Enter B for book or R for recording: " << choice << endl;

    if (choice == 'B') {
        char author[100];

        cout << "Enter book title: ";
        cin.getline(title, 100);
        csis << "Enter book title: " << title << endl;

        cout << "Enter book author: ";
        cin.getline(author, 100);
        csis << "Enter book author: " << author << endl;

        cout << "Enter call number: ";
        cin >> number;
        csis << "Enter call number: " << number << endl;

        holder = new Book(title, number, author);

        return holder;
    }

    if (choice == 'R') {
        char performer[100];
        char format;

        cout << "Enter recording title: ";
        cin.getline(title, 100);
        csis << "Enter recording title: " << title << endl;

        cout << "Enter performer: ";
        cin.getline(performer, 100);
        csis << "Enter performer: " << performer << endl;

        cout << "Enter format: (M)P3, (W)AV, (A)IFF): ";
        cin >> format;
        csis << "Enter format: (M)P3, (W)AV, (A)IFF): " << format << endl;

        cout << "Enter call number: ";
        cin >> number;
        csis << "Enter call number: " << number << endl;

        holder = new Recording(title, number, performer, format);

        return holder;
    }

    return holder;
}

