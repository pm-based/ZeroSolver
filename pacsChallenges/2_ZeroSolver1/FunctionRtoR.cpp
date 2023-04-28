#include "FunctionRtoR.hpp"
#include <iostream>

void FunctionRtoR::setSovler(std::string s){
    auto it = Solver::solverFactory.find(s);
    if(it != Solver::solverFactory.end()){ //In order to avoid segmentation fault
        solver = it->second(fun);
    }else{
        std::cerr << std::endl << "The method entered does not exits" << std::endl;
    }
};

void FunctionRtoR::print() const{
    if(sol.second == true){
        std::cout<< sol.first <<std::endl;
    }else{
        std::cout << "does not converge" << std::endl;
    }
}

void FunctionRtoR::setOptions(const FunctionTraits::point _a,
            const FunctionTraits::point _b, 
            const double _tol_rel,
            const double _tol_abs, 
            const unsigned int _maxIter)
{
    if(solver==nullptr){ //in order to avoid segmentation fault
        std::cout<<"First set the solver"<<std::endl;
    }else{
        solver->setOptions(_a, _b, _tol_rel, _tol_abs, _maxIter);
        }
}