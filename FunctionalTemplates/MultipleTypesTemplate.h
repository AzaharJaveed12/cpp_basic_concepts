/*
    ReturnType is mandatory to declare as we cannot deduce it automatically.
*/
template<typename ReturnType, typename T,typename P>
ReturnType maximumInArray(T array , P size);


/*
    If we want to remove returnType, then we should use decltype to deduce returntype by using some 
    expression
*/
template<typename T , typename P>
auto mainimumInArray(T array , P size) -> decltype( size > 0 ? array[0]: size);
