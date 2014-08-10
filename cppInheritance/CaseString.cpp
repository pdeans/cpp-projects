//  CaseString.cpp

#include "CaseString.h"
#include <fstream>

extern ofstream csis;


CaseString::CaseString() : String() {}

CaseString::CaseString(const CaseString& cs) : String(cs){}

CaseString::CaseString(const char* ch) : String(ch) {}

CaseString& CaseString::operator=(const CaseString& cs)
{
    if (&cs != this) {
        String::operator=(cs);
    }

    return *this;
}

void CaseString::print()
{
    cout << lower << "  " << upper << endl;
    csis << lower << "  " << upper << endl;
}

CaseString::~CaseString()
{
    //delete [] lower;
    //delete [] upper;
}
