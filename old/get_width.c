#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string to print the arguments
 * @i: Current position in the format string
 * @list: List of arguments
 * from the variable argument list using `va_arg`.
 * Return:
 * The calculated width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int selected_i;
	int width = 0;

	for (selected_i = *i + 1; format[selected_i] != '\0'; selected_i++)
	{
		if (is_digit(format[selected_i]))
		{
			width *= 10;
			width += format[selected_i] - '0';
		}
		else if (format[selected_i] == '*')
		{
			selected_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = selected_i - 1;

	return (width);
}
