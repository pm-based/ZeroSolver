#ifndef SOLVERS_HPP
#define SOLVERS_HPP

#include "Traits.hpp"

namespace Solver{

    class SolverBase : FunctionTraits{
        public:
        SolverBase(FunctionType _fun): fun(_fun){};
        virtual ~SolverBase() = default;
        virtual RootType solve() const = 0;
        protected:
        FunctionType fun;
        };
}

#endif //SOLVERS_HPP