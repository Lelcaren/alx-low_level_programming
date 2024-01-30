#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/* Main _printf function */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;

    va_start(args, format);

    for (ptr = format; *ptr; ptr++)
    {
        if (*ptr == '%' && *(ptr + 1) != '\0')
        {
            ptr++;
            int j = 0;
            convert specifiers[] = {
                {"c", print_char},
                {"s", print_str},
                {"%", print_percent},
                {"d", print_decimal},
                {"i", print_integer}, /* Added 'i' specifier */
                {NULL, NULL}
            };

            while (specifiers[j].specifier != NULL)
            {
                if (*ptr == *specifiers[j].specifier)
                {
                    count += specifiers[j].printer(args);
                    break;
                }
                j++;
            }
        }
        else
        {
            putchar(*ptr);
            count++;
        }
    }

    va_end(args);

    return count;
}

