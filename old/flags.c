#include "main.h"

/**
 * get_flags - Extracts and calculates the flags present in a formatted string
 * @format: The formatted string to analyze
 * @i: Pointer to an integer representing the starting index for flag analysis
 *
 * Return: An integer representing the flags calculated from the format string.
 */

int get_flags(const char *format, int *i)
{
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	curr_i = *i + 1;
	while (format[curr_i] != '\0')
	{
		j = 0;
		while (FLAGS_CH[j] != '\0')
		{
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
			j++;
		}

		if (FLAGS_CH[j] == '\0')
			break;

		curr_i++;
	}

	*i = curr_i - 1;

	return (flags);
}
