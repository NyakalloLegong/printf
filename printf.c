#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 * @format: is a character string.
 * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list _printfList;
	int i = 0, count = 0, _strlen;
	char c;
	char *s;

	va_start(_printfList, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case '%':
				{
					c = '%';
					write(1, &c, 1);
					count++;
					break;
				}
				case 'c':
				{
					c = (char) va_arg(_printfList, int);
					write(1, &c, 1);
					count++;
					break;
				}
				case 's':
				{
					s = va_arg(_printfList, char *);
					_strlen = 0;

						while (s[_strlen] != '\0')
						{
							_strlen++;
						}
					write(1, s, _strlen);
					count += _strlen;

					break;
				}
				default:
					write(1, format - 1, 2);
					return (-1);
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
	format++;
		}
	va_end(_printfList);
return (count);
}
