#include "main.h"

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @listPrecision: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list listPrecision)
{
	int j, precision;

	j = *i + 1;
	precision = -1;

	if (format[j] != '.')
	{
		return (precision);
	}
	precision = 0;
	for (j += 1; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
	{
		precision *= 10;
		precision += format[j] - '0';
	}
	else if (format[j] == '*')
	{
	j++;
	precision = va_arg(listPrecision, int);
	break;
	}
	else
	break;
	}
	*i = j - 1;
	return (precision);
}
