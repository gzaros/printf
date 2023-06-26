#include "main.h"

/**
* handle_print - Prints the arguments based on their types.
* @fmt: The string containing the format specifier.
* @list: The list of arguments to be printed.
* @index: The index.
* @buffer: An array used to handle printing.
* @_flags: Stores the active _flags for formatting.
* @width: The width of the output.
* @precision: The precision specification.
* @size: The specifier for size.
*
* Return: 1 or 2, indicating success or failure.
*/

int handle_print(const char *fmt, int *index, va_list list, char buffer[],
	int width, int precision, int size, int _flags)
{
	int i, unknow_length = 0, show_chars = -1;
	_fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i]._fmt != '\0'; i++)
		if (fmt[*index] == fmt_types[i]._fmt)
			return (fmt_types[i].fn(list, buffer, _flags, width, precision, size));

	if (fmt_types[i]._fmt == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		unknow_length += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			unknow_length += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
				--(*index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		unknow_length += write(1, &fmt[*index], 1);
		return (unknow_length);
	}
	return (show_chars);
}
