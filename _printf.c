#include "main.h"
/**
 * _printf - recreation of printf to find certain specifiers
 * Description: Funtion that prints string format.
 *
 * @format: arguments function
 * Return: an int len of string to '\0'
 */

int _printf(const char *format, ...)
{
	int i = 0, bf_count = 0;
	char *buffer = NULL;
	void (*category_functions)(char *, va_list, int *);
	va_list args;

	va_start(args, format), buffer = malloc(sizeof(char) * 2048);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				continue;

			category_functions = get_category_functions(format[i + 1]);
			if (category_functions == NULL)
			{
				buffer[bf_count] = format[i];

				if (format[i + 1] != '%')
				{
					buffer[bf_count + 1] = format[i + 1];
					bf_count += 2;
				}
				else
					bf_count++;
			}
			else
				category_functions(buffer, args, &bf_count);
			i++;
			continue;
		}
		buffer[bf_count] = format[i];
		bf_count++;
	}
	va_end(args), write(1, buffer, bf_count), free(buffer);
	return (bf_count);
}

