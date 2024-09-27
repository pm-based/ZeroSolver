# Root-Finding Solver with Plugin Architecture

This project implements three numerical methods to solve root-finding problems using a plugin architecture. The methods provided are:
- **Bisection**
- **Secant**
- **Broyden**

The core idea of this project is to model a scalar function of one variable using the `FunctionRtoR` class. This class includes methods to calculate the root of the function and print the results. The project uses an object factory design pattern to dynamically load solvers, making it easy to extend or change the available root-finding methods.

## Features

### `FunctionRtoR` Class
The `FunctionRtoR` class is responsible for modeling scalar functions and providing utility methods to calculate their zeros. The following methods are implemented:
- **`setSolver`**: Allows the user to select a numerical method from the ones loaded in the solver factory. It checks whether the chosen method is available.
- **`setOption`**: Sets the parameters associated with the solver and verifies that a method has already been selected.
- **`print`**: Prints the result if the algorithm has converged; otherwise, it communicates that convergence was not achieved.

### Plugin Architecture

The plugin architecture allows the solver methods to be loaded dynamically using a factory pattern implemented with maps. This is efficient as all root-finding methods are constructed with the same argument, `FunctionType`. The object factory is designed to easily load and manage multiple solver methods via plugins.

### Supported Solvers
The project currently supports three root-finding methods, which are loaded as plugins:
- **Bisection**
- **Secant**
- **Broyden**

The plugins are listed in `PluginListToLoad.txt`: ./libSecant.so ./libBisection.so ./libBroyden.so

## Requirements

- You need to set the directory of `pacs-examples` in the `Makefile`. This is because the project relies on external libraries and examples from the [pacs-examples repository](https://github.com/pacs-course/pacs-examples.git).
- The `Boost` library is required for certain functionality in the program, including dynamic loading of plugins.

## Compilation

To compile the project, follow these steps:

1. Clone the `pacs-examples` repository:
   git clone https://github.com/pacs-course/pacs-examples.git
2. Set the PATH_PACSEXAMPLE variable in the Makefile to point to the path where you cloned pacs-examples.
3. Ensure that the Boost library is installed on your system.

Once these steps are complete, you can compile the project using the provided Makefile

## Usage
You can use the setSolver method to choose between the available root-finding methods (Bisection, Secant, or Broyden). Use setOption to configure the solver options and call print to display the results after the computation.

## Plugin Management

The solver plugins are specified in the PluginListToLoad.txt file. To add new solvers, simply update this file with the paths to the new plugin shared objects (e.g., libYourNewMethod.so) and place them in the appropriate directory.
