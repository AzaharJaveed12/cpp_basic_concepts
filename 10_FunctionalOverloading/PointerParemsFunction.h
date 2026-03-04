#include<iostream>
void min( int  ,     int  );
void min( int* ,     int* );


/*
 We should have any one of this below methods.
 Reason : Compiler consider all of this as same functional Signature.
          When we use arr[] , arr[10] internally they all decay to int*
          Soo compiler see all of this as same functions.
 */
void minScore(int *arr    , size_t n);
void minScore(int arr[]   , size_t n);
void minScore(int arr[10] , size_t n);