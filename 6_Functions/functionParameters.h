#pragma once

void passByValue(int age);
void passByConstValue(const int age);
void passByPointer(int* age);
void passByPointerConst(const int* age);
void passByConstPointerConst(const int* const age);
void passByReference(int& age);                       // passByReference(age) - age can be modified
void passByConstReference(const int& age);            // passByConstReference(age) - age cannot be modified

// arrays
void passArrayToFunction_A(int arr[5] , int& size);    // implicitly arr decayed to pointer & ignores the size of arr[5] mentioned. (can take any size array)
void passArrayToFunction_B(int *arr , int& t);         // above one become same as this parameter types only.
void passArrayToFunctionAsReference(int (&arr)[10]);   // here arr should be exactly 10 elements. (not decayed to pointer here.)

// multidimentional array
void passMultiDimentionalArray(int arr[][5] , int& n);  // one dimention can be computed by function but remining dimentions should be provided.

// default arguments
void defaultArgs(int a = 0 , int b = 0);

// implicit conversions
void constParamFunctions(const int& data);