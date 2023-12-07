#include <stdio.h>
#include <stdlib.h>

extern void to_upper(char* array);

int main() {

    char array[13] = "Hello World.";

    to_upper(array);

	printf("the chars are: %s\n", array);

    // After calling modify_array, you can use the modified array

    return 0;
}

