#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef struct format
{
    char *ph;
    int (*function)(va_list);
} convert;

int print_c(va_list val);
int print_s(va_list val);
int print_i(va_list val);
int print_d(va_list val);
int print_percentage(va_list val);
int _printf(const char *format, ...);

#endif

