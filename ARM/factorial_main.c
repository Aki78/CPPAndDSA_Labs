#include <stdio.h>
#include <stdlib.h>

extern int factorial(int n);

int main() {

    int n = factorial(3);

	printf("the chars are: %i\n", n);

    return 0;
}

