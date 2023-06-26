#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a characters
 * @types: List of the arguments
 * @size: Size of specifier
 * @_precision: Precision specifier
 * @buffer: Array to handle print
 * @_flags:  Calculates active number of flags
 * @width:  The width
 * Return: characters printed
 */
int print_char(va_list types, char buffer[],
	int _flags, int width, int _precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, _flags, width, _precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: Arguments
 * @buffer: Array to handle print
 * @_flags: Calculates active number of flags
 * @width: The width
 * @_precision: Precision specification
 * @size: Specifier of size
 * Return: chars printed
 */
int print_string(va_list types, char buffer[],
	int _flags, int width, int _precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(_flags);
	UNUSED(width);
	UNUSED(_precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (_precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (_precision >= 0 && _precision < length)
		length = _precision;

	if (width > length)
	{
		if (_flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: Arguments
 * @buffer: Array to handle print
 * @flags: Active flags
 * @width: The width
 * @_precision: Specifier of precision
 * @size: Specifier of size
 * Return: chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int _precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(_precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: List of  the arguments
 * @buffer: Array to handle print
 * @_flags: Active flags
 * @size: Size specifier
 * @width: The width
 * @precision: Precision specifier
 * Return: characters printed
 */
int print_int(va_list types, char buffer[],
	int _flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, _flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: List of  the arguments
 * @buffer: Array to handle print
 * @_flags:  Number of active flags
 * @width: The width
 * @_precision: Precision specifier
 * @size: Specifier
 * Return: char printed.
 */
int print_binary(va_list types, char buffer[],
	int _flags, int width, int _precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(_flags);
	UNUSED(width);
	UNUSED(_precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

