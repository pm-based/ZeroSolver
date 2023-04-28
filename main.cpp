#include <numbers>
#include <cmath>
#include <functional>
#include <string>
#include <iostream>
#include <dlfcn.h> //To implement plugin architecture

#include "Traits.hpp"
#include "FunctionRtoR.hpp"
#include "LoadSolverFactory.hpp"

int main(){
    // Loading of plugin listed in the file: PluginListToLoad.txt
    Solver::LoadSolverFactory loadPlugins("PluginListToLoad.txt");

    /*  Definition of the function to solve in a function wrapper: FunctionType
    *   and of the relative class
    *   implement the methods to handle the FunctionType oject. */
    FunctionTraits::FunctionType FunctionToSolve = [](double x){
        return 0.5-std::exp(std::numbers::pi*x);
        };
    FunctionRtoR ChallengeFunction(FunctionToSolve);

    /*  Computing the zero of FunctionToSolve with the loaded methods.
    *   In order to do this we have to set whitch solver methods we want
    *   to use. Then we can set the paramenters of the solver. */
    ChallengeFunction.setSovler("Secant");
    ChallengeFunction.setOptions(-1,0,1.e-6,1.e-10,1000);
    ChallengeFunction.solve();
    ChallengeFunction.print();

    ChallengeFunction.setSovler("Bisection");
    ChallengeFunction.setOptions(-1,0,1.e-6,1.e-10,10000);
    ChallengeFunction.solve();
    ChallengeFunction.print();

    ChallengeFunction.setSovler("Broyden");
    ChallengeFunction.solve();
    ChallengeFunction.print();
    
    return 0;
}
