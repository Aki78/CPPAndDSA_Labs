#include <stdio.h>
#include <stdlib.h>

extern int div_mod(int n, int m);

int main() {

    int a = div_mod(1234, 33);

    printf("%d/n", a);

    return 0;
}

