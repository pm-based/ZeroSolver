#include "FunctionRtoR.hpp"
#include <iostream>

void FunctionRtoR::setSovler(std::string s){
    auto it = Solver::solverFactory.find(s);
    solver = it->second(fun);    
};

void FunctionRtoR::print() const{
    std::cout<<sol.first<<std::endl;
    std::cout<<sol.second<<std::endl;
}