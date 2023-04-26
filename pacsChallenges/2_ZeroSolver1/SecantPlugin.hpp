#ifndef SECANTPLUGIN_HPP
#define SECANTPLUGIN_HPP

#include "SolverBase.hpp"

namespace Solver{
    class Secant : public SolverBase, FunctionTraits {
        public:
        Secant(FunctionType& _fun): fun(_fun) {};
        virtual RootType solve() const override;
        private:
        FunctionType& fun;
    };

}

#endif //SECANTPLUGIN_HPP