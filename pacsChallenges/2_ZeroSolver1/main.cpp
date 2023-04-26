#include <numbers>
#include <cmath>
#include <functional>
#include <string>
#include <dlfcn.h>

#include "Traits.hpp"
#include "FunctionRtoR.hpp"
#include "LoadSolverFactory.hpp"

int main(){
    Solver::LoadSolverFactory loadPlugins("PluginListToLoad.txt");

    FunctionTraits::FunctionType FunctionToSolve = [](double x){return 0.5-std::exp(std::numbers::pi*x);};
    FunctionRtoR ChallengeFunction(FunctionToSolve);
    ChallengeFunction.setSovler("Secant");
    ChallengeFunction.solve();
    ChallengeFunction.print();

    return 0;
}
