#include "main.h"

int print_c(va_list val) { /* implementation for %c */ }
int print_s(va_list val) { /* implementation for %s */ }
int print_i(va_list val) { /* implementation for %i */ }
int print_d(va_list val) { /* implementation for %d */ }
int print_percentage(va_list val) { /* implementation for %% */ }

int _printf(const char *format, ...)
{
    convert p[] = {
        {"%c", print_c},
        {"%s", print_s},
        {"%i", print_i},
        {"%d", print_d},
        {"%%", print_percentage},
    };

    va_list args;
    int i = 0, j, length = 0;

    va_start(args, format);
    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

Here:
    while (format[i] != '\0')
    {
        j = 4;
        while (j >= 0)
        {
            if (p[j].ph[0] == format[i] && p[j].ph[1] == format[i + 1])
            {
                length += p[j].function(args);
                i = i + 2;
                goto Here;
            }
            j--;
        }
        // Handle other characters or unsupported format specifiers
        putchar(format[i]);
        length++;
        i++;
    }
    va_end(args);
    return (length);
}

