#ifndef FUNCTIONRTOR_HPP
#define FUNCTIONRTOR_HPP

#include "Traits.hpp"
#include "FactoryTraits.hpp"
#include <string>
#include <iostream>

class FunctionRtoR final: FunctionTraits{
    public:
    FunctionRtoR(FunctionType _fun): fun(_fun){};

    // Solver settings:
    void setSovler(std::string s);
    void setOptions(const point _a,
            const point _b, 
            const double _tol_rel,
            const double _tol_abs, 
            const unsigned int _maxIter);

    // 
    void solve(){sol = solver->solve();}
    void print() const;

    /*  The solver is public therefore it is possibile to use
    *   the methods of the solver. This allows, for example, to 
    *   load plugins of numerical method which need more
    *   parameters (as Broyden that needs to set the initial guess
    *   and the approximation of initial derivative) or simply
    *   plugins with more functions. */
    Solver::SolverType solver = nullptr;

    private:
    FunctionType fun;
    Solver::NumericalSolutionType sol;
};

#endif //FUNCTIONRTOR_HPP
