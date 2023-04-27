#include "BroydenPlugin.hpp"
#include "Traits.hpp"
#include "FactoryTraits.hpp"
#include <iostream>


namespace Solver{
	NumericalSolutionType Broyden::solve() const{
        double          Dfx0{dfx0};
        double          X0{x0};
        double          fx0{fun(x0)};
        unsigned int    iter{0u};
        double          deltax;
        double          X1;
        double          fx1;
        double          diff{opt.tol_abs+1};
        
        while(diff >= opt.tol_abs && iter < opt.maxIter){
            ++iter;
            deltax = -fx0/Dfx0;
            std::cout<<deltax<<" "<<Dfx0 << "  " << X0<< std::endl;
            X1=X0+deltax;
            fx1 = fun(X1);
            Dfx0 += (fx1*deltax)/(deltax*deltax);
            diff = std::abs(deltax);
            X0 = X1;
            fx0 = fx1;
        }
        if (iter == opt.maxIter && diff > opt.tol_abs){
            return std::make_pair(X1, false);
        }else{
            return std::make_pair(X1, true);
        }


    }
    
	namespace
    {
        struct LoadF
        {
            LoadF(){
                solverFactory["Broyden"] = [](FunctionTraits::FunctionType _fun) {
                    return std::make_unique<Broyden>(_fun);
                    };
            }
        };

        const LoadF loadf; // local variable when created loads the stuff
    } // namespace

}// namespace Solver