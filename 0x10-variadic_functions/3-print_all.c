#include <stdio.h>
#include <stdarg.h>

void print_all(const char * const format, ...) {
    va_list args;
    va_start(args, format);

    char c;
    int i;
    float f;
    char *s;

    int char_printed = 0;

    while (*format) {
        if (*format == 'c') {
            c = (char)va_arg(args, int);
            printf("%c", c);
            char_printed = 1;
        } else if (*format == 'i') {
            i = va_arg(args, int);
            if (char_printed)
                printf(", ");
            printf("%d", i);
            char_printed = 1;
        } else if (*format == 'f') {
            f = (float)va_arg(args, double);
            if (char_printed)
                printf(", ");
            printf("%f", f);
            char_printed = 1;
        } else if (*format == 's') {
            s = va_arg(args, char *);
            if (char_printed)
                printf(", ");
            if (s == NULL) {
                printf("(nil)");
            } else {
                printf("%s", s);
            }
            char_printed = 1;
        }

        format++;
    }

    va_end(args);
    printf("\n");
}

int main(void) {
    print_all("ceis", 'B', 3, "stSchool");
    return 0;
}

