#include "SecantPlugin.hpp"
#include "Traits.hpp"
#include "FactoryTraits.hpp"

namespace Solver{
    NumericalSolutionType Secant::solve() const{
        point           a = opt.a; // to allow modification in the while-loop
        double          ya = fun(a);
        double          resid = std::abs(ya);
        RootType        c{a};
        unsigned int    iter{0u};
        double          check = opt.tol_rel * resid + opt.tol_abs;
        bool            goOn = resid > check;
        while(goOn && iter < opt.maxIter)
            {
            ++iter;
            double yb = fun(opt.b);
            c = a - ya * (opt.b - a) / (yb - ya);
            double yc = fun(c);
            resid = std::abs(yc);
            goOn = resid > check;
            ya = yc;
            a = c;
            }
        return std::make_pair(c, (iter < opt.maxIter));
    }

    // Implementation of plugin architecture
    namespace
    {
        struct LoadF
        {
            LoadF(){
                // Adding the method (Definited by the SolverBase(_fun) constructor)
                // to solverFactory 
                solverFactory["Secant"] = [](FunctionTraits::FunctionType _fun) {
                    return std::make_unique<Secant>(_fun);
                    };
            }
        };

        const LoadF loadf; // local variable when created loads the stuff
    } // namespace
} // namespace Solver
