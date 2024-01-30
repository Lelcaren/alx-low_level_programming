#include "main.h"
#include <stdio.h>

int print_i(va_list val)
{
    int n = va_arg(val, int);
    printf("%d", n);
    return 1;
}

