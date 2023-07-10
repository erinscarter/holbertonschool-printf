#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* prototypes */

int _printf(const char *format, ...);
int _putchar(char c);
void pr_string(char *buffer, va_list args, int *buf_count);
void pr_char(char *buffer, va_list args, int *buf_count);
void pr_int(char *buffer, va_list args, int *buf_count);
void (*get_category_functions(char cc))(char*, va_list args, int*);

/**
* struct specifiers - format specifiers
* @cat: pointer to format specifiers
* @box: function pointer to functions for format specifers
**/

typedef struct specifiers
{
	char *cat;
	void (*box)(char*, va_list, int*);
} specifiers;

#endif
