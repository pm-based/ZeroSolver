#ifndef SOLVERS_HPP
#define SOLVERS_HPP

#include "Traits.hpp"

namespace Solver{

    class SolverBase : FunctionTraits{
        public:
        SolverBase() = default;
        virtual RootType solve() const = 0;
        virtual void setFun(FunctionType) const = 0;
        };
}

#endif //SOLVERS_HPP