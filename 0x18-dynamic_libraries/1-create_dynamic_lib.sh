#!/bin/bash

# Compile all .c files into object files
gcc -c -Wall -Werror -fpic *.c

# Create the dynamic library liball.so from all the object files
gcc -shared -o liball.so *.o

# Clean up the object files
rm *.o
