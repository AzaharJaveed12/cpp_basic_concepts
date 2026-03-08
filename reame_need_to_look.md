# topics to deep dive if have time:
    1. cin , cout --> ostream & istream in cpp in depth usage.
                      how to read a line in c++.
                      how to read a paragram in c++.

    2. overloading vs overriding (compiletime = OL vs runtime = OR)
    3. inline functions :
            a. will expand this function at caller location
            b. when we have written functions in .h file, when we include in multiple files we may get multiple funciton definations error.
                to overcome this mark function as inline.
            3. class functions are inline by default. when defined inside. (talk about .h file class)
            4. class functions defied outside needs inline keyword
            5. constexpr is always inline.