//  ReverseString.h

#ifndef __Inheritance_Lab__ReverseString__
#define __Inheritance_Lab__ReverseString__

#include <iostream>
#include "String.h"


class ReverseString: public String {
private:
    char* rstring;
public:
    ReverseString();
    ReverseString(const ReverseString&);
    ReverseString(const char*);
    ReverseString& operator=(const ReverseString&);
    ReverseString operator~();
};

#endif
