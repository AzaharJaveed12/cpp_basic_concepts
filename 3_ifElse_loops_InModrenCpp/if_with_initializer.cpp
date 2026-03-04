#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> st{1,4,5,7,8,9};
    
    if(const auto& it = st.lower_bound(3); *it == 3) {
        cout << "found the element : " << *it << "\n";
    } else {
        cout << "got the lower_bound of element 3 which is : " << *it << "\n";;
    }

    return 0;
}