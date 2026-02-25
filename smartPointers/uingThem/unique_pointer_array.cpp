#include <iostream>
#include <memory>

using namespace std;

class Data {
private:
    int *cnt;
public:
    Data(const int& cnt) : cnt{new int(cnt)} {
        cout << "[Data] constructor " << (this->cnt)<< "   " << (*(this->cnt)) <<"\n";
    }

    Data(): Data(0) {
        cout <<"[Data] default constructor\n"; 
    }
    ~Data() {
        cout << "~[Data] destructor " << (this -> cnt ) << " " << (*(this -> cnt)) << "\n";
    }
};

/*
constuctotrs will be called but not distructors. we should call indivdually.
*/
void without_smart_pointers() {
    Data *data = new Data[3]{Data(1), Data(2) , Data(3)};
}

/*
constructors & destructos will get called here..!
*/
void with_smart_pointers() {
  //  unique_ptr<Data[]> u_ptr_data = unique_ptr<Data[]>(new Data[3]{Data(4) , Data(5) , Data(6)});
    unique_ptr<Data[]> u_ptr = make_unique<Data[]>(3); // works but cannot initialize individual
}

int main () {
//    without_smart_pointers();
    with_smart_pointers();
    return 0;
}