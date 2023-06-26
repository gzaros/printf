#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints pointer value.
 * @types: List of the arguments
 * @width: The width
 * @buffer: Array to handle print
 * @_flags:  Calculates active flags.
 * @_precision: Precision specifier
 * @size: Specifier of size
 * Return: chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int _flags, int width, int _precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(_precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((_flags & F_ZERO) && !(_flags & F_MINUS))
		padd = '0';
	if (_flags & F_PLUS)
		extra_c = '+', length++;
	else if (_flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, _flags, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: List the arguments
 * @buffer: Array to handle print
 * @_flags: Calculates active flags.
 * @width: The width
 * @_precision: Precision specifier
 * @size: Specifier of size
 * Return: chars to print
 */
int print_non_printable(va_list types, char buffer[],
	int _flags, int width, int _precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(_flags);
	UNUSED(width);
	UNUSED(_precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string
 * @types: List the arguments
 * @_precision: Precision specifier
 * @buffer: Array to handle print
 * @_flags: Calculates active flags.
 * @width: The width
 * @size: Specifier of size
 * Return: chars to print
 */

int print_reverse(va_list types, char buffer[],
	int _flags, int width, int _precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(_flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(_precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/************************* Prints string in ROT13 *************************/
/**
 * print_rot13string - Prints string in ROT13.
 * @types: Lists the arguments
 * @size: Specifier of size
 * @buffer: Array to handle print
 * @_flags: Calculates active flags.
 * @width: The width
 * @_precision: Precision specifier
 * Return: chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int _flags, int width, int _precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(_flags);
	UNUSED(width);
	UNUSED(_precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

