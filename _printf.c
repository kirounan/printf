#include "main.h"
/**
 * _printf - Variadic function prints dynamic input
 * in a specific format chosen
 * @format: format chosen
 * Return: integerthat represents number of charachters
 */
int _printf(const char *format, ...)
{
	int n;
	va_list Vlist;

	va_start(Vlist, format);
	if (format == NULL)
		return (-1);
	n = formatOutput(Vlist, format);
	va_end(Vlist);
	return (n);
}
