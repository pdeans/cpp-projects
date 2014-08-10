//  String.cpp

#include "String.h"
#include <fstream>

extern ofstream csis;

String::String()
{
    buf = new char[1];
    buf[0] = '\0';
    length = 0;
}

String::String(const char* str)
{
    length = int(strlen(str));
    buf = new char[length+1];

    for (int i = 0; i < length; i++) {
        buf[i] = str[i];
    }
    buf[length] = '\0';
}

String::String(char ch)
{
    buf = new char[2];

    buf[0] = ch;
    length = 1;
    buf[length] = '\0';
}

String::String(int i)
{
    int count = 0,
        temp = i;

    if (i < 0) {
        i = 0;
    }

    while (temp > 0) {
        temp /= 10;
        count++;
    }

    buf = new char[count+1];
    sprintf(buf, "%d", i);
    length = count;
    buf[length] = '\0';
}

String::String(const String& str)
{
    length = str.length;
    buf = new char[length];
    buf = str.buf;
}

String::String(char ch, int i)
{
    buf = new char[i];
    char charArray[i];

    for (int index = 0; index < i; index++) {
        charArray[index] = ch;
    }
    charArray[i] = '\0';
    buf = charArray;
    length = int(strlen(buf));
}

String::~String()
{
    //delete [] buf;
    length = 0;
}

String& String::operator=(const String& str)
{
    if (this == &str) {
        return *this;
    }

    length = str.length;
    buf = str.buf;

    return *this;
}

String& String::operator=(const char* ch)
{
    length = int(strlen(ch));
    buf = (char*)ch;

    return *this;
}

String operator+(const String& str1, const String& str2)
{
    int i, j;
    int combinedLength = str1.length + str2.length;
    String temp(combinedLength);
    temp.length = combinedLength;

    for (i = 0; i < str1.length; i++) {
        temp.buf[i] = str1.buf[i];
    }

    for (j = 0, i = str1.length; j < str2.length; j++, i++) {
        temp.buf[i] = str2.buf[j];
    }
    temp[combinedLength] = '\0';

    return temp;
}

String operator+(const String& str1, const char* ch)
{
    int i, j;
    int combinedLength = str1.length + int(strlen(ch));
    String temp(combinedLength);
    temp.length = combinedLength;

    for (i = 0; i < str1.length; i++) {
        temp.buf[i] = str1.buf[i];
    }

    for (j = 0, i = str1.length; j < int(strlen(ch)); j++, i++) {
        temp.buf[i] = ch[j];
    }
    temp[combinedLength] = '\0';

    return temp;
}

String operator+(const char* ch, const String& str1)
{
    int i, j;
    int combinedLength = str1.length + int(strlen(ch));
    String temp(combinedLength);
    temp.length = combinedLength;

    for (i = 0; i < int(strlen(ch)); i++) {
        temp.buf[i] = ch[i];
    }

    for (j = 0, i = int(strlen(ch)); j < str1.length; j++, i++) {
        temp.buf[i] = str1.buf[j];
    }

    temp[combinedLength] = '\0';

    return temp;
}

String operator+(const String& str1, const char ch)
{
    int i;
    int combinedLength = str1.length + 1;
    String temp(combinedLength);
    temp.length = combinedLength;

    for (i = 0; i < str1.length; i++) {
        temp.buf[i] = str1.buf[i];
    }
    temp[combinedLength-1] = ch;
    temp[combinedLength] = '\0';

    return temp;
}

String operator+(const char ch, const String& str1)
{
    int i, j;
    int combinedLength = str1.length + 1;
    String temp(combinedLength);
    temp.length = combinedLength;

    temp[0] = ch;
    for (i = 0, j = 1; i < str1.length; i++, j++) {
        temp.buf[j] = str1.buf[i];
    }
    temp[combinedLength] = '\0';

    return temp;
}

String& String::operator+=(const String& str)
{
    int i, j;
    int tempLength = length + str.length;
    char* temp = new char[tempLength];

    for (i = 0; i < length; i++) {
        temp[i] = buf[i];
    }

    for (i = length, j = 0; j < str.length; i++, j++) {
        temp[i] = str.buf[j];
    }

    delete [] buf;
    buf = new char[tempLength];
    length = tempLength;

    for (i = 0; i < length; i++) {
        buf[i] = temp[i];
    }

    delete [] temp;

    return *this;
}

String String::operator+() const
{
    String temp;
    temp.buf = buf;
    temp.length = length;

    for (int i = 0; i < temp.length; i++) {
        temp[i] = toupper(temp[i]);
    }

    return temp;
}

int operator==(const String& str1, const String& str2)
{
    return str1.buf == str2.buf;
}

int operator!=(const String& str1, const String& str2)
{
    return str1.buf != str2.buf;
}

int operator< (const String& str1, const String& str2)
{
    return str1.buf < str2.buf;
}

int operator<=(const String& str1, const String& str2)
{
    return str1.buf <= str2.buf;
}

int operator> (const String& str1, const String& str2)
{
    return str1.buf > str2.buf;
}

int operator>=(const String& str1, const String& str2)
{
    return str1.buf >= str2.buf;
}

char& String::operator[](int i)
{
    static char ch = '\0';

    if (i < 0 || i > length) {
        cout << "Error: Index out of range" << endl;
        return ch;
    }
    else {
        return buf[i];
    }
}

char* operator+(const String& str, int i)
{
    return &str.buf[i];
}

char* operator+(int i, const String& str)
{
    return &str.buf[i];
}

String& String::operator++()
{
    for (int i = 0; i < length; i++) {
        buf[i] = buf[i+1];
    }

    return *this;
}

String& String::operator--()
{
    for (int i = length; i > 0; i--) {
        buf[i] = buf[i-1];
    }

    return *this;
}

String& String::operator++(int val)
{
    String temp(*this);
    ++(*this);

    return temp;
}

String& String::operator--(int val)
{
    String temp(*this);
    --(*this);

    return temp;
}

String String::substr(int start, int end)
{
    String s;

    for (int i = start, j = 0; j < end; i++, j++) {
        s.buf[j] = buf[i];
        s.length++;
    }
    return s;
}

int String::getLength()
{
    return length;
}

void String::print()
{
    cout << "\"" << buf << "\"" << "  " << "Length = " << length << endl;
    csis << "\"" << buf << "\"" << "  " << "Length = " << length << endl;
}

ostream& operator<<(ostream& os, const String& str)
{
    for (int i = 0; i < str.length; i++) {
        os << str.buf[i];
    }

    return os;
}







