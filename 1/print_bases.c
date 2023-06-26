#include "main.h"

/**
 * print_hex - Prints number in hexadecimal base.
 * in lowercase
 * @l: va_list arguments from _printf
 * @f: Pointer to flags struct for determination.
 * if a flag is passed to _printf
 * Description: Function calls convert() to convert the input.
 * Converts number into correct base and returns as string.
 * Return: Number of characters printed.
 */
int print_hex(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 16, 1);
	int cnt = 0;

	if (f->hash == 1 && str[0] != '0')
		cnt += _puts("0x");
	cnt += _puts(str);
	return (cnt);
}

/**
 * print_hex_big - Prints number in hexadecimal base.
 * in uppercase
 * @l: va_list arguments from _printf
 * @f: Pointer to determining struct.
 * if a flag is passed to _printf
 * Description: Function calls convert() to convert the input.
 * Converts number into the correct base and returns it as a string.
 * Return: the number of char printed
 */
int print_hex_big(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 16, 0);
	int cnt = 0;

	if (f->hash == 1 && str[0] != '0')
		cnt += _puts("0X");
	cnt += _puts(str);
	return (cnt);
}

/**
 * print_binary - Prints number in binary (base 2) format.
 * @l: va_list arguments from _printf
 * @f: pointer to the struct that determines
 * if a flag is passed to _printf
 * Description: Function calls convert() to convert the input.
 * Converts the number into the correct base and returns it as a string.
 * Return: the number of char printed
 */
int print_binary(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 2, 0);

	(void)f;
	return (_puts(str));
}

/**
 * print_octal - Prints number in octal (base 8) format.
 * @l: va_list arguments from _printf
 * @f: pointer to the struct that determines
 * if a flag is passed to _printf
 * Description: Function calls convert() to convert the input.
 * Converts the number into the correct base and returns it as a string.
 * Return: the number of char printed
 */
int print_octal(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 8, 0);
	int cnt = 0;

	if (f->hash == 1 && str[0] != '0')
		cnt += _putchar('0');
	cnt += _puts(str);
	return (cnt);
}
