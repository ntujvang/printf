#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * string_app - append two strings
 * @base: initial string
 * @str: string to add
 *
 * Return: pointer to appended base
 */
char *string_app(char *base, char *str)
{
	/* concatenate two strings */
	_strcat(base, str);
	return (base);
}

/**
 * num_app - append string with converted number
 * @base: initial string
 * @num: number to be converted and added
 *
 * Return: pointer to appended base
 */
char *num_app(char *base, int num)
{
	char *temp;

	/* allocate dynamic memory for number */
	temp = malloc(100);
	/* convert number to string */
	itoa(num, temp);
	_strcat(base, temp);
	/* release allocated dynamic memory */
	free(temp);
	return (base);
}

/**
 * switchf - determine which specifier to use
 * @format: format string from _printf
 * @buffer: buffer string from _printf
 * @i: location in @format
 * @n: location in @buffer
 * @args: arguments
 *
 * Return: new position in @format
 */
int switchf(const char *format, char *buffer, int i, int n, va_list args)
{
	/* switch/case instead of long if statements */
	switch (format[i])
	{
	case '%':
		buffer[n] = '%';
		i++;
		break;
	case 's':
		buffer = string_app(buffer, va_arg(args, char*));
		i++;
		break;
	case 'i':
		num_app(buffer, va_arg(args, int));
		i++;
		break;
	case 'd':
		num_app(buffer, va_arg(args, int));
		i++;
		break;
	default:
		buffer[n] = '%';
		break;
	}
	return (i);
}