void passByValue(int age);
void passByConstValue(const int age);
void passByPointer(int* age);
void passByPointerConst(const int* age);
void passByConstPointerConst(const int* const age);
void passByReference(int& age); // passByReference(age) - age can be modified
void passByConstReference(const int& age); // passByConstReference(age) - age cannot be modified