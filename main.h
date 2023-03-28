#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);
int formatOutput(va_list lalista, const char *format);
int print_str(va_list lalista);
int print_int(va_list lalista);
int print_num(unsigned int n, int c);
int print_rot13(va_list lalista);
int print_b(va_list args);
int print_u(va_list args);
int print_o(va_list args);
int print_x(va_list args);
int print_X(va_list args);
int print_number_u(unsigned int);
int print_hexa(char s);

#endif
