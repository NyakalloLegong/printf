#include "main.h"

/**
 * get_flags - Counts active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
	int j, k, flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {FLAG_MINUS, FLAG_PLUS, FLAG_ZERO,
				FLAG_HASH, FLAG_SPACE, 0};

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[k] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}
	*i = k - 1;
	return (flags);
}
