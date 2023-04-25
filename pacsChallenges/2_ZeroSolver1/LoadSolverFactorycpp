#include "LoadSolverFactory.hpp"
#include "string_utility.hpp"

namespace Solver
{
bool
LoadSolverFactory::load(std::string listPluginFile)
{
  bool          good = true;
  std::ifstream pFile(listPluginFile);
  if(pFile.bad())
    {
      std::cerr << " Cannot open plugin files" << std::endl;
      return false;
    }
  while(pFile.good() && (!pFile.eof()))
    {
      std::string line;
      //! get a line
      std::getline(pFile, line);
      // I am assuming no spaces in file name and I use the utility trim in
      // string_utility to eliminate possible trailing blanks
      line = Utility::trim(line);
      if(!line.empty())
        {
          std::string libName = line;
          // open the dynamic library
          void *sdl_library = dlopen(libName.c_str(), RTLD_NOW);
          // check if error
          if(sdl_library == nullptr)
            {
              std::cerr << " Cannot load Library " << libName << " "
                        << dlerror() << std::endl;
              good = false;
            }
          else
            {
              std::clog << libName << " Library opened" << std::endl;
              good = (good && true);
              loadedLibs.push_back(sdl_library);
            }
        }
      else if(!pFile.eof())
        std::clog << "Empty line in plugins file\n";
    }
  return good;
}

void
LoadSolverFactory::close()
{
  // close all hold libraries
  for(auto l : this->loadedLibs)
    {
      dlclose(l);
    }
  this->loadedLibs.clear();
}
}// namespace Solver