#ifndef SOLVERMETHODSSUPPORT_HPP
#define SOLVERMETHODSSUPPORT_HPP

#include "Traits.hpp"

namespace Solver{
    struct OptionType {
        FunctionTraits::point a = 0;
        FunctionTraits::point b = 1;
        double tol_rel = 1.e-5;
        double tol_abs = 1.e-8;
        unsigned int maxIter = 20;
    };
}

#endif //SOLVERMETHODSSUPPORT_HPP