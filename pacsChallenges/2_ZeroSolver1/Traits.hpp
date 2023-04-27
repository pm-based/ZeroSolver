#ifndef TRAITS_HPP
#define TRAITS_HPP

#include <tuple>
#include <functional>

// Traits useful to handle functions
struct FunctionTraits{
    using ArgType = double;
    using RootType = double;
    using FunctionType = std::function<RootType(ArgType)>;
    using point = double;
};

//Traits for the Solver
namespace Solver{
    using Concergence = bool;   // It indicate if the method has converged
    using NumericalSolutionType = std::pair<FunctionTraits::RootType, Concergence>;
}

#endif //TRAITS_HPP
