#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/* Function to print string */
int print_str(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;
    while (*str)
    {
        putchar(*str);
        str++;
        count++;
    }
    return count;
}

