#ifndef BISECTIONPLUGIN_HPP
#define BISECTIONPLUGIN_HPP

#include "SolverBase.hpp"

namespace Solver{
    class Bisection final: public SolverBase, FunctionTraits {
        public:
        Bisection(FunctionType _fun): SolverBase(_fun) {};
        virtual NumericalSolutionType solve() const override;
    };
}

#endif //BISECTIONPLUGIN_HPP