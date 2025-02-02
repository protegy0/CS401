#include <stdio.h>
#include "factorial.h"

int main() {
    int num;

    printf("Enter a number!\n");
    scanf("%d", &num);

    printf("The factorial of that number is:\nIteratively: %d\nRecursively: %d\n", factorialIteratively(num), factorialRecursively(num));


    return 0;
}