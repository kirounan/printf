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

#endif
