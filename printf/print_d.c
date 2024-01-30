#include "main.h"
#include <stdio.h>

int print_d(va_list val)
{
    int n = va_arg(val, int);
    printf("%d", n);
    return 1;
}

