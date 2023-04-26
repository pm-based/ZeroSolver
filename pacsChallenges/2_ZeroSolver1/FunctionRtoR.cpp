#include "FunctionRtoR.hpp"

void FunctionRtoR::setSovler(std::string s){
    auto it = Solver::solverFactory.find(s);
    solver = it->second(fun);    
    //solver->setFun(fun);
};