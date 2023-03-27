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
* print_integer - function that print integer
*@lalista: list of integer
*Return: length of integer
*/
int print_int(va_list lalista)
{
	int num, count = 0;
	unsigned int unum;

	number = va_arg(lalista, int);
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
