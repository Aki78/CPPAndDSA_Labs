#include <stdio.h>
#include <stdlib.h>

extern int f1(int a, int b);



int f2c(int p) {
	int r;
	r = p + 5;
	return r + p;
}


int f1c(int a, int b) {
	int i, x;
	x = (a + b)*(a - b);
	for (i=0; i<a; i++)
		x = x + f2c(b+i);
	return x;
}

int main() {

    int n = f1(1, 2);

	printf("the chars are: %i\n", n);
	printf("the chars are: %i\n", f1c(1,2));

    return 0;
}



