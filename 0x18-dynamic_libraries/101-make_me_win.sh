#!/bin/bash

echo -e '#include <stdio.h>\n\nvoid gm(int n1, int n2, int n3, int n4, int n5, int bonus) { printf("Please make me win!\\n"); }' > /tmp/libgm.c
gcc -Wall -fPIC -shared -o /tmp/libgm.so /tmp/libgm.c
LD_PRELOAD=/tmp/libgm.so ./gm 9 8 10 24 75 9
