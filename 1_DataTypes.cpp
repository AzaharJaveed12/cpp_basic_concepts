#include<iostream>
#include<stdio.h>
#include <clocale>

using namespace std;

int main() {
    std::setlocale(LC_ALL, ""); 
    // 1 Byte
    bool isBoolean = true;

    // 1 Byte -127 to 128
    char ch = 'a', ch1 = 99;
    signed char sCh = 128;
    unsigned char usCh = 255;
    
    // 4 Bytes - used for different languages
    wchar_t wideCharector = L'\u03c0';
    wcout<< L"PI: "<< wideCharector <<endl;
    return 0;
}
