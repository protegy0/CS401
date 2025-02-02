#include "factorial.h"

int factorialIteratively(int n) {
    int sum = 1;
    for (int i = n; i != 0; i--) {
        sum *= i;
    }
    return sum;
}

int factorialRecursively(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return factorialRecursively(n - 1) * n;
}