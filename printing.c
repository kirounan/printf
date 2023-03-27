#include "main.h"
#include <stdio.h>
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
	char *c;

	c = va_arg(lalista, char *);
	if (c)
		return 2;
	return 3;
}
/**
 * print_b - this function print binaries
 * Description: this function prints integer in binary
 * @args: arguments
 * @buffer: Buffer
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
