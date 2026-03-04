#include <iostream>

using namespace std;
/*
Dont use legacy enums as it causes problems
*/
enum class DAY{
  MON  , 
  TUE  , 
  WED  , 
  THRU , 
  FRI  = 1000, 
  SAT  , 
  SUN  , 
  FRIDAY = FRI ,
  SATURDAY = SAT , 
  SUNDAY = SUN, 
};

// custom type enum classes.
enum class WEEKEND: unsigned char {
    FRIDAY,
    SATURDAY,
    SUNDAY,
};

int main() {
    cout << "[default] enum class element size: " << sizeof(DAY::MON) <<"\n";
    cout << static_cast<int>(DAY::MON) << " \n";     // for enum classes without static_cast it throws error.
    cout << static_cast<int>(DAY::SATURDAY) << "\n"; // 1001 as friday is 1000
    cout << "[custom] enum class element size: " << sizeof(WEEKEND::FRIDAY) <<"\n";
    return 0;
}