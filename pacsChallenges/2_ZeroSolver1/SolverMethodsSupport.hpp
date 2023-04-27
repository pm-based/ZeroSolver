#ifndef SOLVERMETHODSSUPPORT_HPP
#define SOLVERMETHODSSUPPORT_HPP

#include "Traits.hpp"

namespace Solver{
    struct OptionType {
        FunctionTraits::point a = 0;
        FunctionTraits::point b = 1;
        double tol_abs = 2;
        unsigned int maxIter = 1000;
    };
}

#endif //SOLVERMETHODSSUPPORT_HPP