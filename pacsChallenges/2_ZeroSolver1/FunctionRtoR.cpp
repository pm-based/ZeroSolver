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

void FunctionRtoR::setOptions(const FunctionTraits::point _a,
            const FunctionTraits::point _b, 
            const double _tol_rel,
            const double _tol_abs, 
            const unsigned int _maxIter)
{
    if(solver=nullptr){ //in order to avoid segmentation fault
        std::cout<<"First set the solver"<<std::endl;
    }else{
        solver->setOptions(_a, _b, _tol_rel, _tol_abs, _maxIter);
        }
}