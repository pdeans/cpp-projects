//  ZipCode.cpp
//  BarcodeLab

#include "ZipCode.h"

// Public member functions

ZipCode::ZipCode(int z)
{
    zipcode = z;
}

ZipCode::ZipCode(string b)
{
    toZipCode(b);
}

int ZipCode::getZipCode()
{
    return zipcode;
}

string ZipCode::getBarCode()
{
    toBarCode(zipcode);
    
    return barcode;
}

// Private member functions

void ZipCode::toBarCode(int z)
{
    barcode = "1";
    string temp = to_string(z);
    
    for (int i = 0; i < temp.length(); i++) {
        switch (temp.at(i)) {
            case '0': barcode += string("11000");
                break;
            case '1': barcode += string("00011");
                break;
            case '2': barcode += string("00101");
                break;
            case '3': barcode += string("00110");
                break;
            case '4': barcode += string("01001");
                break;
            case '5': barcode += string("01010");
                break;
            case '6': barcode += string("01100");
                break;
            case '7': barcode += string("10001");
                break;
            case '8': barcode += string("10010");
                break;
            case '9': barcode += string("10100");
                break;
        }
    }
    barcode += string("1");
}

void ZipCode::toZipCode(string b)
{
    zipcode = 0;
    string temp_zipcode;
    string temp1 = b.substr(1, 5);
    string temp2 = b.substr(6, 5);
    string temp3 = b.substr(11, 5);
    string temp4 = b.substr(16, 5);
    string temp5 = b.substr(21, 5);
    
    temp_zipcode += string(getSum(temp1));
    temp_zipcode += string(getSum(temp2));
    temp_zipcode += string(getSum(temp3));
    temp_zipcode += string(getSum(temp4));
    temp_zipcode += string(getSum(temp5));
    
    zipcode = atoi(temp_zipcode.c_str());
}

string ZipCode::getSum(string s)
{
    int sum = 0;
    
    if (s.at(0) == '1') {
        sum += 7;
    }
    
    if (s.at(1) == '1') {
        sum += 4;
    }
    
    if (s.at(2) == '1') {
        sum += 2;
    }
    
    if (s.at(3) == '1') {
        sum += 1;
    }
    
    if (s.at(4) == '1') {
        sum += 0;
    }
    
    if (sum == 11) {
        sum = 0;
    }
    
    return to_string(sum);
}