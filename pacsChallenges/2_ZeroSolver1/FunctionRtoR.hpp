#ifndef FUNCTIONRTOR_HPP
#define FUNCTIONRTOR_HPP

#include "Traits.hpp"
#include "FactoryTraits.hpp"
#include <string>

class FunctionRtoR: FunctionTraits{
    public:
    FunctionRtoR(FunctionType _fun): fun(_fun){};
    void setSovler(std::string const s);
    void solve() const;
    void print() const;

    private:
    FunctionType fun;
    RootType sol;
    Solver::SolverType solver;
};

#endif //FUNCTIONRTOR_HPP
