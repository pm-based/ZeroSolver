#ifndef SECANTPLUGIN_HPP
#define SECANTPLUGIN_HPP

#include "SolverBase.hpp"

namespace Solver{
    class Secant final: public SolverBase, FunctionTraits {
        public:
        // Using the constructor of SolverBase
        Secant(FunctionType _fun): SolverBase(_fun) {};
        virtual NumericalSolutionType solve() const override;
    };
}

#endif //SECANTPLUGIN_HPP