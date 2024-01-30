#include "main.h"
#include <stdio.h>

int print_c(va_list val)
{
    char c = va_arg(val, int);
    putchar(c);
    return (1);
}

