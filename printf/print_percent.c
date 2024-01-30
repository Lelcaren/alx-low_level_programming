#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/* Function to print percent sign */
int print_percent(va_list args)
{
    (void)args; // Unused parameter
    putchar('%');
    return 1;
}

