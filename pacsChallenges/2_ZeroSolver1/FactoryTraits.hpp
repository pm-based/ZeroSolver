#ifndef FACTORYTRAITS_HPP
#define FACTORYTRAITS_HPP

#include <functional>
#include <map>
#include <memory>
#include <string>

#include "SolverBase.hpp"
#include "Traits.hpp"

namespace Solver{
    using SolverType = std::unique_ptr<Solver::SolverBase>;

    using SolverBuilder = std::function<SolverType()>;
    using SolverId = std::string;
    using SolverFactory = std::map<SolverId, SolverBuilder>;
    
    extern SolverFactory solverFactory;

}// namespace Solver

#endif //FACTORYTRAITS_HPP