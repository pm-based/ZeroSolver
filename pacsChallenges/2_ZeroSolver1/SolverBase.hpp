#ifndef SOLVERS_HPP
#define SOLVERS_HPP

#include "Traits.hpp"
#include "SolverMethodsSupport.hpp"

namespace Solver{

    class SolverBase : FunctionTraits{
        public:
        SolverBase(FunctionType _fun): fun(_fun){};
        virtual ~SolverBase() = default;

        virtual RootType solve() const = 0;
        void setOptions(
            const point _a, 
            const point _b, 
            const double _tol_abs, 
            const unsigned int _maxIter); 

        protected:
        FunctionType fun;
        OptionType opt;
        };
}

#endif //SOLVERS_HPP