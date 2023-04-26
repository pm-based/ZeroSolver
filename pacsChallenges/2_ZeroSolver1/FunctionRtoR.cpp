#include "FunctionRtoR.hpp"


void FunctionRtoR::setSovler(std::string const s){
    auto it = Solver::solverFactory.find(s);
    solver = it->second();    
};