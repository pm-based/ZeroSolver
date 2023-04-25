#ifndef FUNCTIONRTOR_HPP
#define FUNCTIONRTOR_HPP

#include "Traits.hpp"

class FunctionRtoR: FunctionTraits{
    public:
    FunctionRtoR(FunctionType _fun): fun(_fun){};

    private:
    FunctionType fun;
    RootType sol;
    
};

#endif //FUNCTIONRTOR_HPP