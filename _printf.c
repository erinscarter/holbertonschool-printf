#include <stdio.h>
#include <stdarg.h>

int _printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // Count of characters printed

    const char* c = format;
    while (*c != '\0') {
        if (*c == '%') {
            // Handle format specifiers
            c++;
            switch (*c) {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char*));
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
    int result = _printf("Character: %c\nString: %s\nPercent: %%\n", 'A', "Hello, World!");
    printf("Total characters printed: %d\n", result);

    return 0;
}

