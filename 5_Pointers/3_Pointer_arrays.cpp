#include <iostream>

using namespace std;

int main() {
    int scores[]{11,100,50,40};
    int* scores_ptr = scores;                      // no need to use &scores
    cout <<"scores_ptr[2] : " <<  scores_ptr[2] << "  scores[2] : " << scores[2] << "\n";
    cout <<scores << "   " << scores_ptr << "\n"; // both prints the addresses.
    cout << "*(scores_ptr + 2) : " << (*(scores_ptr + 2)) << "\n";
    

    // pointer arthametic
    for(int i = 0 ; i < 4 ; i ++) {
        cout << (*scores_ptr) <<" ";
        scores_ptr++;
    } cout <<"\n";


    int *p1 = scores_ptr , *p2 = scores_ptr + 2;
    cout << std::ptrdiff_t(p2 - p1) <<"\n";
    // comparision operations allowed on pointers.
    return 0;
}