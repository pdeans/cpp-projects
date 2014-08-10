//  String.h

#ifndef __Inheritance_Lab__String__
#define __Inheritance_Lab__String__

#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class String {
private:
    char* buf;
    int length;
public:
    String();
    String(const char*);
    String(char);
    String(int);
    String(const String&);
    String(char, int);
    ~String();
    String& operator=(const String&);
    String& operator=(const char*);
    friend String operator+(const String&, const String&);
    friend String operator+(const String&, const char*);
    friend String operator+(const char*, const String&);
    friend String operator+(const String&, const char);
    friend String operator+(const char, const String&);
    String& operator+=(const String&);
    String operator+() const;
    friend int operator==(const String&, const String&);
    friend int operator!=(const String&, const String&);
    friend int operator< (const String&, const String&);
    friend int operator<=(const String&, const String&);
    friend int operator> (const String&, const String&);
    friend int operator>=(const String&, const String&);
    char& operator[](int);
    friend char* operator+(const String&, int);
    friend char* operator+(int, const String&);
    String& operator++();
    String& operator--();
    String& operator++(int);
    String& operator--(int);
    String substr(int, int);
    int getLength();
    void print();
    friend ostream& operator<<(ostream&, const String&);
};

#endif
