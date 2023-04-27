#include "BisectionPlugin.hpp"
#include "Traits.hpp"
#include "FactoryTraits.hpp"
#include <iostream>

namespace Solver{
	NumericalSolutionType Bisection::solve() const{
		point  a = opt.a; // to allow modification in the while-loop
		point  b = opt.b;
		double ya = fun(a);
		double yb = fun(b);
		if(ya * yb > 0){ // If the the function does not change sign at the two end values
			std::cerr << std::endl 
			<< "Function must change sign at the two end values"
			<< std::endl;
			return std::make_pair(0, false);
			}
		double delta = b - a;
		double yc{ya};
		double c{a};
		while(std::abs(delta) > 2 * opt.tol_abs)
			{
			c = (a + b) / 2.;
			yc = fun(c);
			if(yc * ya < 0.0)
				{
				yb = yc;
				b = c;
				}
			else
				{
				ya = yc;
				a = c;
				}
			delta = b - a;
			}
		return std::make_pair((a + b) / 2., true);
	}

	// Implementation of plugin architecture
	namespace
    {
        struct LoadF
        {
            LoadF(){
				// Adding the method (Definited by the SolverBase(_fun) constructor)
                // to solverFactory 
                solverFactory["Bisection"] = [](FunctionTraits::FunctionType _fun) {
                    return std::make_unique<Bisection>(_fun);
                    };
            }
        };

        const LoadF loadf; // local variable when created loads the stuff
    } // namespace

}// namespace Solver