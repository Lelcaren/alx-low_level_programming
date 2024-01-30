#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Structure to hold conversion specifier and corresponding function */
typedef struct specifier
{
    char *specifier;
    int (*printer)(va_list args);
} convert;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_str(va_list args);
int print_percent(va_list args);
int print_decimal(va_list args);
int print_integer(va_list args);

#endif /* MAIN_H */

