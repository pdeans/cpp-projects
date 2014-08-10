//  ZipCode.h
//  BarcodeLab

#ifndef __BarcodeLab__ZipCode__
#define __BarcodeLab__ZipCode__

#include <iostream>
#include <string.h>

using namespace std;

class ZipCode {
private:
    string barcode;
    int zipcode;
    void toBarCode(int z);
    void toZipCode(string b);
    string getSum(string s);
public:
    ZipCode(int z);
    ZipCode(string b);
    int getZipCode();
    string getBarCode();
};

#endif /* defined(__BarcodeLab__ZipCode__) */
