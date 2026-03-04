#include<iostream>
#include <iomanip>
#include<ios>
using namespace std;

int main() {
    // basic pointers
    int var = 10 , num = 20 ;
    int *p_var = &var;
    setw(100);
    setfill('-');
    cout<<setw(100)<<setfill('-')<<" int" << (*p_var)<<" ";
    p_var = &num;
    cout<<(*p_var)<<endl;

    const int* cp_var = &var;
    cout<<" const int" <<setw(30) << (*cp_var)<<" ";
    cp_var = &num;
    // *cp_var = 30; 
    cout<<(*cp_var)<<endl;

    int const* pc_var = &var;
    cout<<" int const*" << (*pc_var)<<" ";    
    //pc_var = &num;
    // *pc_var = 30;
    cout<<(*pc_var)<<"\n";

    int* const icp_var = & var;
    cout<< " int *const " << (*icp_var) <<" ";
    // icp_var = &num;
    *icp_var = 50;
    
    return 0;
}