//  IntArray.cpp

#include "IntArray.h"
#include <fstream>

extern ofstream csis;

IntArray::IntArray()
{
    min = 0;
    max = 9;
    size = 10;
    array[size];
}

IntArray::IntArray(int upper)
{
    min = 0;
    max = upper - 1;
    size = upper;
    array[size];
}

IntArray::IntArray(int lower, int upper)
{
    if (lower > upper) {
        cout << "Error: Lower boundary out of range - Program Halt..." << endl;
        csis << "Error: Lower boundary out of range - Program Halt..." << endl;
    }
    else if (lower == upper) {
        min = lower;
        max = upper;
        size = 1;
        array[size];
    }
    else {
        min = lower;
        max = upper;
        size = ((upper) - (lower)) + 1;
        array[size];
    }
}

IntArray::IntArray(const IntArray& arr)
{
    min = arr.min;
    max = arr.max;
    size = arr.size;
    for (int i = arr.min; i <= arr.max; i++) {
        array[i] = arr.array[i];
    }
}

void IntArray::setName(string s)
{
    name = s;
}

int IntArray::low()
{
    return min;
}

int IntArray::high()
{
    return max;
}

IntArray& IntArray::operator=(IntArray& arr)
{
    min = arr.min;
    max = arr.max;
    int offset = arr.min;
    int* ptr = (arr.array+offset);

    if (size != arr.size) {
        cout << "Error: Size mismatch. Program halt..." << endl << endl;
        csis << "Error: Size mismatch. Program halt..." << endl << endl;
    }

    for (int i = min; i <= max; i++) {
        array[i] = *(ptr+i);
    }

    return *this;
}

int IntArray::operator==(IntArray& arr)
{
    int offset = arr.min;
    int* ptr1 = (array+min);
    int* ptr2 = (arr.array+offset);
    int check = 0;

    if ( (size) == (arr.size) ) {
        for (int i = min; i <= max; i++) {
            if ( *(ptr1+i) == *(ptr2+i) ) {
                check = 1;
            }
            else {
                return 0;
            }
        }
    }

    return check;
}

int IntArray::operator!=(IntArray& arr)
{
    int offset = arr.min;
    int* ptr1 = (array+min);
    int* ptr2 = (arr.array+offset);
    int check = 1;

    if ( (size) == (arr.size) ) {
        for (int i = min; i <= max; i++) {
            if ( *(ptr1+i) == *(ptr2+i) ) {
                check = 0;
            }
            else {
                return 1;
            }
        }
    }

    return check;
}

int& IntArray::operator[](int val)
{
    if (val < min || val > max) {
        cout << "Error: Out of legal range. Program halt..." << endl;
        csis << "Error: Out of legal range. Program halt..." << endl << endl;
    }

    return val;
}

void IntArray::operator+=(IntArray& arr)
{
    int offset = arr.min;
    int* ptr = (arr.array+offset);

    if ( (max - min) != (arr.max - arr.min) ) {
        cout << "Error: Must have same number of elements. Program halt..." << endl;
        csis << "Error: Must have same number of elements. Program halt..." << endl;
    }
    else {
        for (int i = min; i <= max; i++) {
            array[i] = *(array+i) + *(ptr+i);
        }
    }
}

IntArray operator+(IntArray& arr1, IntArray& arr2)
{
    IntArray temp(arr1.size);
    int offset = arr1.min;
    int offset2 = arr2.min;
    int* ptr1 = (arr1.array+offset);
    int* ptr2 = (arr2.array+offset2);

    if ( (arr1.size) != (arr2.size) ) {
        cout << "Error: Must have same number of elements. Program halt..." << endl;
        csis << "Error: Must have same number of elements. Program halt..." << endl;
    }
    else {
        for (int i = 0; i <= temp.size; i++) {
            temp.array[i] = *(ptr1+i) + *(ptr2+i);
        }
    }
    return IntArray(temp);
}

ostream& operator<<(ostream& os, const IntArray& arr)
{
    if (arr.min == arr.max) {
        int i = arr.min;
        os << arr.name << "[" << i << "] = " << arr.array[i] << endl;
    }
    else {
        for (int i = arr.min; i <= arr.max; i++) {
            os << arr.name << "[" << i << "] = " << arr.array[i] << endl;
        }
    }

    return os;
}




