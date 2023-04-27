#include <numbers>
#include <cmath>
#include <functional>
#include <string>
#include <dlfcn.h>
#include <iostream> //only for debugging

#include "Traits.hpp"
#include "FunctionRtoR.hpp"
#include "LoadSolverFactory.hpp"

int main(){
    Solver::LoadSolverFactory loadPlugins("PluginListToLoad.txt");

    FunctionTraits::FunctionType FunctionToSolve = [](double x){return 0.5-std::exp(std::numbers::pi*x);};
    FunctionRtoR ChallengeFunction(FunctionToSolve);
    ChallengeFunction.setSovler("Secant");
    ChallengeFunction.setOptions(-1,0,1.e-6,1.e-10,10000);
    ChallengeFunction.solve();
    ChallengeFunction.print();

    ChallengeFunction.setSovler("Bisection");
    std::cout<< "afrer set solver"<<std::endl;
    ChallengeFunction.solve();
    std::cout<< "afrer solve"<<std::endl;
    ChallengeFunction.print();
    std::cout<< "afrer print"<<std::endl;

    return 0;
}
