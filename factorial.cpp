//include factorial
#include "factorial.h"
#include <iostream>

int factorial(int n){

    int result = 1;
    for (int i = 1; i<= n; i++){

        result = result*i;

        //std::cout << "step: " << result << std::endl;

    }
    return result;
}