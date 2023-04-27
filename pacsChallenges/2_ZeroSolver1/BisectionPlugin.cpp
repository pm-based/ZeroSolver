#include "BisectionPlugin.hpp"
#include "Traits.hpp"
#include "FactoryTraits.hpp"

namespace Solver{




    
/*!
 * Computes the zero of a scalar function with the method of the bisection
 * The returned value is far from the zero at most the given tolerance;
 *
 * @tparam Function
 * @param f The function
 * @param a First end of initial interval
 * @param b Second end of initial interval
 * @param tol Tolerance
 * @return The approximation of the zero of f
 * @pre f(a)*f(b)<0
 * @note It the interval brackets the zero convergence should be guaranteed.
 *
 */
template <TypeTraits::ScalarFunction Function>
double
bisection(Function const &f, double a, double b, double tol = 1.e-5)
{
  double ya = f(a);
  double yb = f(b);
  double delta = b - a;
  SURE_ASSERT(ya * yb < 0, "Function must change sign at the two end values");
  double yc{ya};
  double c{a};
  while(std::abs(delta) > 2 * tol)
    {
      c = (a + b) / 2.;
      yc = f(c);
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
  return (a + b) / 2.;
}

}