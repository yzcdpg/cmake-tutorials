#include <iostream>
#include "config.h"
#include "MathFunctions.h"
using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 2) {
    cout << argv[0] << " version: " 
         << MAIN_VERSION_MAJOR << "." 
         << MAIN_VERSION_MINOR << "." 
         << MAIN_VERSION_PATCH << endl;
         cout << "Usage: " << argv[0] << " number" << endl;
    }
 
    double const inputValue = std::stod(argv[1]);
    double const outputValue = mathfunctions::sqrt(inputValue);
    std::cout << "The square root of " << inputValue << " is " << outputValue << std::endl;

    return 0;
}
