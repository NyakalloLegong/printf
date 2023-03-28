#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - a function that produces output according to a format.
 * @format: is a character string.
 * Return: the number of characters printed
*/
int specifiers(const char *format, ...)
{
	va_list _print;
	unsigned int i = 0, count = 0, u, o, x;
	char bufU[20], bufO[20], bufX[20], hex_char;
	int lenU = 0, lenO = 0, lenX = 0, num;

	va_start(_print, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			format++;
			switch (format[i])
			{
				case 'u':
				{
				u = va_arg(_print, unsigned int);
					do {
					bufU[lenU++] = (u % 10) + '0';
					u /= 10;
					} while (u != 0);
					while (lenU > 0)
					{
					write(1, &bufU[--lenU], 1);
					count++;
					}
					break;
				}
				case 'o':
				{
				o = va_arg(_print, unsigned int);
				do {
					bufO[lenO++] = (o % 8) + '0';
					o /= 8;
					} while (o != 0);
				while (lenO > 0)
				{
				write(1, &bufO[--lenO], 1);
				count++;
				}

				break;
				}
		case 'x':
			case 'X':
		{
		x = va_arg(_print, unsigned int);
		hex_char = (format[i] == 'x') ? 'a' : 'A';
	do {
	num = x % 16;
	bufX[lenX++] = (num < 10) ? (num + '0') : (hex_char + num - 10);
	x /= 16;
	} while (x != 0);
		while (lenX > 0)
		{
			write(1, &bufX[--lenX], 1);
			count++;
		}
		break;
		}
	default:
	{
		write(1, format - 1, 2);
		count += 2;
		break;
	}
	}
	format++;
	}
	else
	{
		write(1, format, 1);
		format++;
		count++;
	}
}

va_end(_print);
return (count);
}
