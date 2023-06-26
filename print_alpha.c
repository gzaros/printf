#include "main.h"

/**
 * print_string - Loops through string and prints.
 * every character
 * @l: va_list arguments in _printf.
 * @f: Pointer to flags struct that determines.
 * Flag check in _printf.
 * Return: number of char printed
 */
int print_string(va_list l, flags_t *f)
{
	char *s = va_arg(l, char *);

	(void)f;

	if (!s)
		s = "(null)";
	return (_puts(s));
}

/**
 * print_char - prints a character
 * @l: va_list arguments from _printf
 * @f: Pointer to flags struct for determination.
 * Flag presence check in _printf.
 * Return: number of char printed
 */
int print_char(va_list l, flags_t *f)
{
	(void)f;
	_putchar(va_arg(l, int));
	return (1);
}
