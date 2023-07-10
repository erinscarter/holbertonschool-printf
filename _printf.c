#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/*
* int _printf(const
**/

int _printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; 

    const char* c = format;
    while (*c != '\0') {
        if (*c == '%') {
            c++;
            switch (*c) {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    count += _printf("%s", va_arg(args, char*));
                    break;
                case 'd':
                case 'i':
                    count += _printf("%d", va_arg(args, int));
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(*c);
                    count += 2;
                    break;
            }
        } else {
            putchar(*c);
            count++;
        }
        c++;
    }

    va_end(args);

    return count;
}

int main() {
    int number = 42;
    int result = _printf("Character: %c\nString: %s\nInteger: %d\nPercent: %%\n", 'A', "Hello, World!", number);
    _printf("Total characters printed: %d\n", result);

    return 0;
}
        } else {
            putchar(*c);
            count++;
        }
        c++;
    }

    va_end(args);

    return count;
}

int main() {
    int result = _printf("Character: %c\nString: %s\nPercent: %%\n", 'A', "Hello, World!");
    printf("Total characters printed: %d\n", result);

    return 0;
}

