#ifndef TRAITS_HPP
#define TRAITS_HPP

#include <tuple>
#include <functional>

struct FunctionTraits{
    using ArgType = double;
    using RootType = double;
    using FunctionType = std::function<RootType(ArgType)>;
    using point = double;
};

//Traits for the Solver
namespace Solver{
    using Concergence = bool;
    using NumericalSolutionType = std::pair<FunctionTraits::RootType, Concergence>;
}

#endif //TRAITS_HPP
