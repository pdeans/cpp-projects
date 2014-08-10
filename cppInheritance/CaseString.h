//  CaseString.h

#ifndef __Inheritance_Lab__CaseString__
#define __Inheritance_Lab__CaseString__

#include <iostream>
#include "String.h"

class CaseString: public String {
private:
    char* upper;
    char* lower;
public:
    CaseString();
    CaseString(const CaseString&);
    CaseString(const char*);
    CaseString& operator=(const CaseString&);
    void print();
    ~CaseString();
};

#endif
