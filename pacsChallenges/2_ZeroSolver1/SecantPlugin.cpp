#include "SecantPlugin.hpp"
#include "Traits.hpp"


namespace Solver{
    FunctionTraits::RootType Secant::solve() const{
        double tol = 1e-4;
        double tola = 1.e-10;
        unsigned int maxIt = 150;
        double       a = -1.;
        double			 b = 0;
        double       ya = fun(a);
        double       resid = std::abs(ya);
        RootType     c{a};
        unsigned int iter{0u};
        double       check = tol * resid + tola;
        bool         goOn = resid > check;
        while(goOn && iter < maxIt)
            {
            ++iter;
            double yb = fun(b);
            c = a - ya * (b - a) / (yb - ya);
            double yc = fun(c);
            resid = std::abs(yc);
            goOn = resid > check;
            ya = yc;
            a = c;
            }
        return c;
    }
}