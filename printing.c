#include "main.h"
#include <stdio.h>
#include <string.h>
/**
* print_str - prints string
*@lalista: list of string
*Return: string length
*/
int print_str(va_list lalista)
{
	char *str;
	int i;

	str = va_arg(lalista, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		putchar(str[i]);
	}
	return (i - 1);
}

/**
* print_num - recursive function to print a number
* in string format
*@n: number to print
*@c: length of the number
*Return: number length
*/
int print_num(unsigned int n, int c)
{
	if (n / 10)
		c = print_num(n / 10, c);
	putchar(n % 10 + '0');
	return (c + 1);
}

/**
* print_int - function that print integer
*@lalista: list of integer
*Return: length of integer
*/
int print_int(va_list lalista)
{
	int num, count = 0;
	unsigned int unum;

	num = va_arg(lalista, int);
	if (num < 0)
	{
		unum = num * -1;
		putchar('-');
		count = print_num(unum, count);
		count += 1;
	}
	else
	{
		unum = num;
		count = print_num(unum, count);
	}
	return (count - 1);
}

/**
* print_rot13 - function that converts a string into rot 13 format
*@lalista: input of specific format
*Return: length of string
*/
int print_rot13(va_list lalista)
{
	int i, j;
	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char r[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *c, *str;

	c = va_arg(lalista, char *);
	if (c == NULL)
		return (0);
	str = malloc(1024);
	if (str == NULL)
		return (-1);
	for (i = 0; c[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (c[i] == a[j])
			{
				str[i] = r[j];
				break;
			}
			else
			{
				str[i] = c[i];
			}
		}
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		putchar(str[i]);
	}
	free(str);
	return (i - 1);
}
/**
 * print_b - this function print binaries
 * Description: this function prints integer in binary
 * @args: arguments
 * Return: len of buffer
 */
int print_b(va_list args)
{
	int len, i;
	unsigned int number;
	int result[32];

	number = va_arg(args, unsigned int);

	if (number == 0)
	{
		print_num(0, 0);
		return (1);
	}
	for (len = 0; number > 0; len++)
	{
		result[len] = number % 2;
		number = number / 2;
	}

	for (i = len - 1; i >= 0; i--)
	{
		print_num(result[i], 0);
	}
	return (len - 1);
}
/**
 * print_number_u - this function print unsigned integers
 * Description: this function prints print integers
 * @n: the integer of the entry
 * Return: nothing
 */
int print_number_u(unsigned int n)
{
	unsigned int  k, l, len = 0;

	k = 1;
	l = n;
	while (l > 9)
	{
		l = l / 10;
		k = k * 10;
	}

	while (k > 9)
	{
		putchar((n / k) % 10 + '0');
		k = k / 10;
		len++;
	}
	putchar(n % 10 + '0');
	len++;
	return (len);
}

/**
 * print_u - Prints unsigned integers
 * Description: This function prints unsigned integers
 * @args: Argument to print
 * Return: Length of number
 */
int print_u(va_list args)
{
	unsigned int number;
	int len;

	number = va_arg(args, unsigned int);
	len = print_number_u(number);

	return (len - 1);
}

/**
 * print_o - Prints octal number
 * Description: This function prints number in octal
 * @args: Argument to print
 * Return: length of @args
 */
int print_o(va_list args)
{
	unsigned int number;
	int len, i;
	long result[50];

	number = va_arg(args, unsigned int);
	if (number == 0)
	{
		print_num(0, 0);
		return (1);
	}
	for (len = 0; number > 0; len++)
	{
		result[len] = number % 8;
		number = number / 8;
	}
	for (i = len - 1; i >= 0; i--)
		print_num(result[i], 0);
	return (len - 1);
}

/**
 * print_x - Prints hexadecimal numbers
 * Description: This function prints number in  hexadecimal
 * @args: Argument to print
 * Return: length of @args
 */
int print_x(va_list args)
{
	unsigned int number;
	int len, i, result[32];

	number = va_arg(args, unsigned int);
	if (number == 0)
	{
		print_num(0, 0);
		return (1);
	}
	for (len = 0; number > 0; len++)
	{
		result[len] = number % 16;
		number = number / 16;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (result[i] >= 10)
			putchar(result[i] + 87);
		else
			putchar(result[i] + 48);
	}
	return (len - 1);
}

/**
 * print_X - Prints hexadecimal numbers in uppercase
 * Description: This function prints hexadecimals in uppsercase
 * @args: Arguments
 * Return: length of number
 */
int print_X(va_list args)
{
	unsigned int number;
	int len, i, result[32];

	number = va_arg(args, unsigned int);
	if (number == 0)
	{
		print_num(0, 0);
		return (1);
	}
	for (len = 0; number > 0; len++)
	{
		result[len] = number % 16;
		number = number / 16;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (result[i] >= 10)
			putchar(result[i] + 55);
		else
			print_num(result[i], 0);
	}
	return (len - 1);
}
/**
 * print_hexa - Prints hexadecimals in uppercase
 * Description: This function prints hexadecimals in uppsercase
 * @s: char to hexa
 * @buffer: Buffer
 * Return: length of @s
 */
int print_hexa(char s)
{
	char number;
	int len, len2, i, result[32];

	len2 = 0;

	number = s;
	if (number <= 16)
	{
		putchar('0');
		len2++;
	}
	for (len = 0; number > 0; len++)
	{
		result[len] = number % 16;
		number = number / 16;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (result[i] >= 10)
			putchar(result[i] + 55);
		else
			print_num(result[i], 0);
	}
	return (len + len2);
}

/**
 * print_S - Prints the string or hexa
 * Descripton -  this function prints the hexa of non valid chars
 * @args: Argument to print
 * Return: length of string
 */
int print_S(va_list args)
{
	char *s = va_arg(args, char *);
	int len, i, c;

	c = 0;
	if (s)
	{
		len = strlen(s);
		for (i = 0; i < len; i++)
			if (*(s + i) < 32 || *(s + i) >= 127)
			{
				putchar('\\');
				c++;
				putchar('x');
				if (*(s + i) == '\0')
					c += print_hexa(0);
				else
					c += print_hexa(*(s + i));
			}
			else
				putchar(*(s + i));
	}
	else
	{
		len = 6;
		s = "(null)";
		for (i = 0; i < len; i++)
			putchar(*(s + i));
	}
	return (len + c - 1);
}
/**
 * print_hex2 - Prints hexadecimal numbers
 * Description: This function prints numbers in hexadecimal
 * @number: Number to print
 * Return: length of input
 */
int print_hex2(unsigned long number)
{
	long len, i, result[32];

	if (number == 0)
	{
		print_num(0, 0);
		return (1);
	}
	for (len = 0; number > 0; len++)
	{
		result[len] = number % 16;
		number = number / 16;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (result[i] >= 10)
			putchar(result[i] + 87);
		else
			putchar(result[i] + 48);
	}
	return (len);
}

/**
 * print_p - Prints address of memory
 * Description: This function prints memmory addresses
 * @args: Arguments
 * Return: Length of address
 */
int print_p(va_list args)
{
	int len = 2, i;
	char *s;
	unsigned long p = (unsigned long) va_arg(args, void *);

	if (p)
	{
		putchar('0');
		putchar('x');
		len += print_hex2(p);
	}
	else
	{
		len = 5;
		s = "(nil)";
		for (i = 0; i < len; i++)
			putchar(*(s + i));
	}
	return (len - 1);
}
