#include <iostream>
void passArrayToFunction_A(int arr[5], int &size) // array decays to pointer.
{
    for(int i =0 ;i < size; i++ ) {
        arr[i]++;
    }
}

void passArrayToFunction_B(int *arr, int &size) // array decays to pointer.
{
    for(int i =0 ;i < size; i++ ) {
        arr[i]++;
    }
}


void passArrayToFunctionAsReference(int (&arr)[10]) // treats as original array only. size should be same..!!
{
    for(int i =0 ;i < std::size(arr); i++ ) {
        arr[i]++;
    }
}