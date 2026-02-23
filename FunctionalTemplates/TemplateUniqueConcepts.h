// default arguments 
template<typename R = double , typename T>
R& square(T& n);


// non-type functional template
template<typename T , T maxHeightAllowed >
bool condition_met(const T& heights);

// auto function template
// auto findFirstElementGreaterThan(auto arr, auto size);