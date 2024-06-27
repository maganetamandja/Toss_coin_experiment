#include "combination.h"
#include "factorial.h"

int combination(int n , int r){
   return factorial(n)/(factorial(r)*factorial(n-r));
}