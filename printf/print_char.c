#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/* Function to print character */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    putchar(c);
    return 1;
}

