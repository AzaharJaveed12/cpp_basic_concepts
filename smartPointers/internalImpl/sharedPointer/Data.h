#include <iostream>

namespace std {
    class Data {
    private:
        const char* name;
        int buffer;
    public:
        // constructor
        Data();
        Data(const char* name , const int& buffer);

        // distructor
        ~Data();

        // observers
        void print_data() const;
    };
}