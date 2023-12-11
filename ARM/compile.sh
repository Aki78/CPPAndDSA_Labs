as -o $1.o $1.asm
gcc -g $1_main.c $1.o
rm *.o
