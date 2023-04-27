# ENTER THE PACS (pacs-examples) DIRECTORY:
PACS-EXAMPLES_DIR=/home/p2/PACS/


include $(PACS-EXAMPLES_DIR)pacs-examples/Examples/Makefile.inc
-include Makefile.inc

# get all files *.cpp
SRCS=$(wildcard *.cpp)
# get the corresponding object file
OBJS = $(SRCS:.cpp=.o)
# get all headers in the working directory
HEADERS=$(wildcard *.hpp)
#
exe_sources=$(filter main%.cpp,$(SRCS))
EXEC=$(exe_sources:.cpp=)

CXXFLAGS+=-fPIC
LDFLAGS= $(OPTFLAGS) -Wl,-rpath,.
LDLIBS=-L. -lFactory -ldl
PLUGINDIR = ./SolverPlugins
#========================== ORA LA DEFINIZIONE DEGLI OBIETTIVI
.phony= all clean distclean doc

.DEFAULT_GOAL = all

all: $(DEPEND) library $(EXEC)

library: libFactory.so libSecant.so libBisection.so libBroyden.so

libFactory.so: FactoryTraits.o
	$(CXX) $(OPTFLAGS) -shared FactoryTraits.o  -o libFactory.so
	
libSecant.so: SecantPlugin.o
	$(CXX) $(OPTFLAGS) -shared SecantPlugin.o -L. -lFactory -o libSecant.so

libBisection.so: BisectionPlugin.o
	$(CXX) $(OPTFLAGS) -shared BisectionPlugin.o -L. -lFactory -o libBisection.so

libBroyden.so: BroydenPlugin.o
	$(CXX) $(OPTFLAGS) -shared BroydenPlugin.o -L. -lFactory -o libBroyden.so

clean:
	$(RM) -f $(EXEC) $(OBJS)

distclean:
	$(MAKE) clean
	$(RM) -f ./doc $(DEPEND)
	$(RM) *.out *.bak *~ *.so

doc:
	doxygen $(DOXYFILE)

$(EXEC): main.o LoadSolverFactory.o FunctionRtoR.o SolverBase.o


$(OBJS): $(SRCS)

$(DEPEND): $(SRCS)
	$(RM) $(DEPEND)
	for f in $(SRCS); do \
	$(CXX) $(STDFLAGS) $(CPPFLAGS) -MM $$f >> $(DEPEND); \
	done

-include $(DEPEND)



