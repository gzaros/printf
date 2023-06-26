#include "main.h"

/**
* get_precision - Calculates the precision to print
* @format: Format string
* @i: Pointer to the current index in the format string
* @lst: Argument list
* Return: Precision value
*/
int get_precision(const char *format, int *i, va_list lst)
{
	int curr_i = *i + 1;
	int _precision = -1;

	if (format[curr_i] != '.')
		return (_precision);

	_precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			_precision *= 10;
			_precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			_precision = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (_precision);
}

