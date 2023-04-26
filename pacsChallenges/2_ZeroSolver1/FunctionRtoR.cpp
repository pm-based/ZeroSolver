#include "FunctionRtoR.hpp"
#include <iostream>

void FunctionRtoR::setSovler(std::string s){
    auto it = Solver::solverFactory.find(s);
    solver = it->second(fun);    
    //solver->setFun(fun);
};

void FunctionRtoR::print() const{
    std::cout<<"AAAAAA"<<std::endl;
}