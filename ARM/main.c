#include <stdio.h>
#include <stdlib.h>

extern void modify_array(int* array, int size);

int main() {
    int size = 200;
    int* array = malloc(size * sizeof(int));
    for(int i=0; i<size; i++){
	    array[i] = 160;
    }

    if (array == NULL) {
        // Handle allocation failure
        return 1;
    }

    // Initialize array or perform other operations

    modify_array(array, size);

    for(int i=0; i<size; i++){
	    printf("%i\n", array[i]);
    }

    // After calling modify_array, you can use the modified array

    free(array);
    return 0;
}

