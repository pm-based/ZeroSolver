#ifndef SECANTPLUGIN_HPP
#define SECANTPLUGIN_HPP

#include "SolverBase.hpp"

namespace Solver{
    class Secant final: public SolverBase, FunctionTraits {
        public:
        Secant(FunctionType _fun): SolverBase(_fun) {};
        virtual RootType solve() const override;
    };

}

#endif //SECANTPLUGIN_HPP