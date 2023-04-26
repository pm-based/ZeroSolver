#ifndef FUNCTIONRTOR_HPP
#define FUNCTIONRTOR_HPP

#include "Traits.hpp"
#include "FactoryTraits.hpp"
#include <string>

class FunctionRtoR: FunctionTraits{
    public:
    FunctionRtoR(FunctionType _fun): fun(_fun){};
    void setSovler(std::string s);
    void solve() {sol = solver->solve();}
    void print() const;

    private:
    FunctionType fun;
    RootType sol = 0;
    Solver::SolverType solver;
};

#endif //FUNCTIONRTOR_HPP
