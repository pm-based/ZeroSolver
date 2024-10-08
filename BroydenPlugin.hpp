#ifndef BROYDENPLUGIN_HPP
#define BROYDENPLUGIN_HPP

#include "SolverBase.hpp"

namespace Solver{
    class Broyden final: public SolverBase, FunctionTraits {
        public:
        Broyden(FunctionType _fun): SolverBase(_fun) {};
        virtual NumericalSolutionType solve() const override;

        void setQuasiNewtonOpt(double _x0, double _dfx0){
            x0 = _x0;
            dfx0 = _dfx0;
        };
        
        private:
        point x0 = 0; // initial guess
        double dfx0 = 1; // guess of the derivative at x0
    };
}

#endif //BISECTIONPLUGIN_HPP