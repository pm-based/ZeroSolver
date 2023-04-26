#include <numbers>
#include <cmath>
#include "Traits.hpp"
#include "FunctionRtoR.hpp"
#include "LoadSolverFactory.hpp"
#include <string>
#include <dlfcn.h>

int main(){
    Solver::LoadSolverFactory loadPlugins("PluginListToLoad.txt");

    FunctionRtoR ChallengeFunction([](double x){return 0.5-std::exp(std::numbers::pi*x);});
    std::string s = "Secant";
    ChallengeFunction.setSovler(s);

    return 0;
}
