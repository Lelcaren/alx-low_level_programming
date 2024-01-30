#include "main.h"
#include <stdio.h>

int print_s(va_list val)
{
    char *s = va_arg(val, char*);
    if (s == NULL)
        s = "(null)";
    int length = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        putchar(s[i]);
        length++;
    }
    return length;
}

