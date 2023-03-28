#include "main.h"
#include <stdio.h>
/**
 * formatOutput - choose format of input
 * @lalista: list of parameters to print
 * @format: input format
 * Return: integer length of output
 **/
int formatOutput(va_list lalista, const char *format)
{
	int i, n = 0;
	char c;

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					c = va_arg(lalista, int);
					putchar(c);
					i++;
					break;
				case 's':
					n += print_str(lalista);
					i++;
					break;
				case '%':
					putchar('%');
					i++;
					break;
				case '\0':
					n = -2;
					break;
				case 'd':
				case 'i':
					n += print_int(lalista);
					i++;
					break;
				case 'b':
					n += print_b(lalista);
					i++;
					break;
				case 'R':
					n += print_rot13(lalista);
					n--;
					i++;
					break;
				case 'u':
					n += print_u(lalista);
					i++;
					n++;
					break;
				case 'o':
					n += print_o(lalista);
					i++;
					break;
				case 'x':
					n += print_x(lalista);
					i++;
					break;
				case 'X':
					n += print_X(lalista);
					i++;
					break;
				default:
					putchar('%');
					break;
			}
		}
		else
			putchar(format[i]);
		n++;
	}
	return (n);
}
