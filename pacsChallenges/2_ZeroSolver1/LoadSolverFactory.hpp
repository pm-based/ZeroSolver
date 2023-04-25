#ifndef LOADSOLVERFACTORY_HPP
#define LOADSOLVERFACTORY_HPP

#include <dlfcn.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "FactoryTraits.hpp"


namespace Solver{
    class loadSolverFactory{
        public:
        loadSolverFactory() = default;
        loadSolverFactory(std::string s){this->load(s);}
        bool load(std::string listPluginFile);
        void close();

        private:
        std::vector<void *> loadedLibs;
    };

}// namespace Solver
#endif //LOADSOLVERFACTORY_HPP