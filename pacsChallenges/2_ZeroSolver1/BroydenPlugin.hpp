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
        point x0 = -0.5;
        double dfx0 = 0.1;
    };
}

#endif //BISECTIONPLUGIN_HPP