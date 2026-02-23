void square(int &n);
/*
   when some one needs to call this methods he uses :
    square(int &n)  --->      square(x)
    square(int n)   --->      square(x)
    square(const int& n) -->  square(5) || square(y) where y is {const int} type
    compiler gets confused which one to call and throws compilation error.

*/


// void square(int n);
void square(const int& n);

void cube(const int& n);