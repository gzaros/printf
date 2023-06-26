#include "main.h"

/**
 * print_address - Prints input address in hexadecimal format.
 * @l: va_list Arguments from _printf.
 * @f: Pointer to flags struct determining.
 * If flag passed to _printf.
 * Return: Number of characters printed.
 */
int print_address(va_list l, flags_t *f)
{
	char *str;
	unsigned long int p = va_arg(l, unsigned long int);

	register int count = 0;

	(void)f;

	if (!p)
		return (_puts("(nil)"));
	str = convert(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}
