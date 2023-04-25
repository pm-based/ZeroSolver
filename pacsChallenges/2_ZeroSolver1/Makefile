PATH_PACSEXAMPLES = /home/p2/PACS

CXXFLAGS = -std=c++20
CPPFLAGS = -I. -I$(PATH_PACSEXAMPLES)/pacs-examples/Examples/src/Utilities -I$(PATH_PACSEXAMPLES)/pacs-examples/Examples/include -I./SolverPlugins
PLUGINDIR = ./SolverPlugins/

all: main

main: main.o libSolverFactory.so LoadSolverFactory.o
	$(CXX) main.o LoadSolverFactory.o -L. -L$(PLUGINDIR) -lSolverFactory -o main

main.o: libSecant.so #da togliere
	$(CXX) $(CXXFLAGS) -fPIC main.cpp -o main.o

#LoadSolverFactory
LoadSolverFactory.o:
	$(CXX) $(CXXFLAGS) -fPIC $(CPPFLAGS) -c LoadSolverFactory.cpp -o LoadSolverFactory.o

#Plugins
libSecant.so: SecantPlugin.o libSolverFactory.so
	$(CXX) $(CXXFLAGS) -shared $(PLUGINDIR)/SecantPlugin.o -lSolverFactory -o $(PLUGINDIR)libSecant.so

SecantPlugin.o:
	$(CXX) -fPIC $(CPPFLAGS) -c $(PLUGINDIR)SecantPlugin.cpp -o $(PLUGINDIR)/SecantPlugin.o


# Solver Factory
libSolverFactory.so: FactoryTraits.o
	$(CXX) $(CXXFLAGS) -shared FactoryTraits.o -o libSolverFactory.so

FactoryTraits.o:
	$(CXX) $(CXXFLAGS) -fPIC -c FactoryTraits.cpp

# # Traits
# Traits.o:
# 	$(CXX) $(CXXFLAGS) Traits.cpp -c 