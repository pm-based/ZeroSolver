#ifndef TRAITS_HPP
#define TRAITS_HPP

#include <functional>

struct FunctionTraits{
    using ArgType = double;
    using RootType = double;
    using FunctionType = std::function<RootType(ArgType)>;
};

#endif //TRAITS_HPP