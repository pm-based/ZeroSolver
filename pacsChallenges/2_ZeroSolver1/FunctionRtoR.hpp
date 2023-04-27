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
    void PRINTSOLVER(){std::cout<<solver<<std::endl;}

    void setOptions(const point _a,
            const point _b, 
            const double _tol_rel,
            const double _tol_abs, 
            const unsigned int _maxIter){
                solver->setOptions(_a, _b, _tol_rel, _tol_abs, _maxIter);}

    void solve(){sol = solver->solve();}
    void print() const;

    private:
    FunctionType fun;
    Solver::NumericalSolutionType sol;
    Solver::SolverType solver;
};

#endif //FUNCTIONRTOR_HPP
