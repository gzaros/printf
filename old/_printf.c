#include "main.h"

void print_buffer(char buffer[], int *buff_index);

/**
 * _printf - Printf function
 * @format: The format
 * Return: chars to be _printed
 */
int _printf(const char *format, ...)
{
	int increment, _printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);
	increment = 0;
	while (format && format[increment] != '\0')
	{
		if (format[increment] != '%')
		{
			buffer[buff_index++] = format[increment];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &increment);
			width = get_width(format, &increment, list);
			precision = get_precision(format, &increment, list);
			size = get_size(format, &increment);
			++increment;
			_printed = handle_print(format, &increment, list, buffer,
				flags, width, precision, size);
			if (_printed == -1)
				return (-1);
			printed_chars += _printed;
		}
		increment++;
	}

	print_buffer(buffer, &buff_index);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the existing contents of buffer
 * @buffer: array of chars
 * @buff_index: Index at which to add next char, length.
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}

