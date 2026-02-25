#include <iostream>
#include <memory>

using namespace std;

class CashDevice {
private:
    int cash;
public:
    CashDevice() = delete;
    CashDevice(const int& cash): cash{cash} {}
    void addCash(const int& amount) {
        cash += amount;
        cout << "[addCash] total cash : " <<  cash << "\n";
    }

    void dispenseCash(const int& amount) {
        cash -= amount;
        cout  << "[dispenseCash] total cash : " <<cash << "\n";
    }
    
    void printCash() const {
        cout << cash << " <-- total cash \n";
    }

    ~CashDevice() {
        cout << "destroyed ";
    }
};

void fun(unique_ptr<CashDevice> device) {
    device -> printCash();
    device -> addCash(5);
    device -> dispenseCash(3);
}

void fun_const_ref(const unique_ptr<CashDevice>& device) {
    device -> printCash();
    device -> addCash(5);
    device -> dispenseCash(3);
}

unique_ptr<CashDevice> fun_local_variable_returning() {
    unique_ptr<CashDevice> cd = make_unique<CashDevice>(200);
    cout << &cd <<"\n";
    return cd;
}


int main() {
    unique_ptr<CashDevice> u_ptr_cashdevice = make_unique<CashDevice>(3);
    u_ptr_cashdevice ->addCash(40);
    u_ptr_cashdevice -> dispenseCash(20);

    // trying to copy which is not valid so throwing error.
    // fun(u_ptr_cashdevice);
    fun(move(u_ptr_cashdevice));

    // Here we are u_ptr_cashdevice which is nullptr.
    //u_ptr_cashdevice -> dispenseCash(3);

    // --------------------pass by reference -----------------
    unique_ptr<CashDevice> u_ptr_cashdevice_two = make_unique<CashDevice>(100);
    fun_const_ref(u_ptr_cashdevice_two); // references passed, (no copy created.)
    cout << "after reference function call \n";
    u_ptr_cashdevice_two -> addCash(5);

    // -----------------taking values from local variable of function ----
    auto cd = fun_local_variable_returning();
    cout << &cd <<"\n";

    return 0;
}