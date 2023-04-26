#include <numbers>
#include <cmath>
#include "Traits.hpp"
#include "FunctionRtoR.hpp"

int main(){
    FunctionRtoR ChallengeFunction([](double x){return 0.5-std::exp(std::numbers::pi*x);});

    return 0;
}
