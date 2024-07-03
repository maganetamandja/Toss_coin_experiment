#include "combination.h"
#include "factorial.h"
#include <gmp.h>

int combination(int n , int r){
   return factorial(n)/(factorial(r)*factorial(n-r));
}