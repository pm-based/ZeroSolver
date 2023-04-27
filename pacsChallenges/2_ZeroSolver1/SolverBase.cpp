#include "SolverBase.hpp"

namespace Solver{
    void SolverBase::SetOptions(
        const point _a, 
        const point _b, 
        const double _tol_abs, 
        const unsigned int _maxIter){
            opt.a = _a;
            opt.b = _b;
            opt.tol_abs = _tol_abs;
            opt.maxIter = _maxIter;
    }
}