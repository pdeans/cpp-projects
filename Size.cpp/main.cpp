/****************************************************************************
 Program Name:      main.cpp (C++ data type sizes)
 Author:            Patrick Stearns
 Date:              June 20, 2014
 Compiler:          Xcode 5
 OS:                OS X 10.9.1
 Description:       Outputs size of various data types
 Input Files:       None
 Output Files:      None
 ****************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    char c;
    int i;
    short int si;
    long int li;
    float f;
    double d;
    long double ld;

    // Pointers
    char* pc;
    int* pi;
    short int* psi;
    long int* pli;
    float* pf;
    double* pd;
    long double* pld;

    // Output data types
    cout << "Size of char: " << sizeof(c) << endl;
    cout << "Size of int: " << sizeof(i) << endl;
    cout << "Size of short int: " << sizeof(si) << endl;
    cout << "Size of long int: " << sizeof(li) << endl;
    cout << "Size of float: " << sizeof(f) << endl;
    cout << "Size of double: " << sizeof(d) << endl;
    cout << "Size of long double: " << sizeof(ld) << endl;

    // Output pointer to data types
    cout << "Size of char pointer: " << sizeof(pc) << endl;
    cout << "Size of int pointer: " << sizeof(pi) << endl;
    cout << "Size of short int pointer: " << sizeof(psi) << endl;
    cout << "Size of long int pointer: " << sizeof(pli) << endl;
    cout << "Size of float pointer: " << sizeof(pf) << endl;
    cout << "Size of double pointer: " << sizeof(pd) << endl;
    cout << "Size of long double pointer: " << sizeof(pld) << endl;
}
