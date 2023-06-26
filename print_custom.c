#include "main.h"

/**
 * print_bigS - Non printable characters
 * ASCII values that are either less than 32 or greater than or equal to 127.
 * Printed in the following format: \x, followed by the ASCII code.
 * Value in uppercase hexadecimal format (always 2 characters).
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_bigS(va_list l, flags_t *f)
{
	int i, cnt = 0;
	char *res;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");
			cnt += 2;
			res = convert(s[i], 16, 0);
			if (!res[1])
				cnt += _putchar('0');
			cnt += _puts(res);
		}
		else
			cnt += _putchar(s[i]);
	}
	return (cnt);
}

/**
 * print_rev - prints a string in reverse
 * @l: argument from _printf
 * @f: Pointer to the struct flags for determination.
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int print_rev(va_list l, flags_t *f)
{
	int i = 0, j;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		s = "(null)";

	while (s[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);

	return (i);
}

/**
 * print_rot13 - Converts a string using ROT13 encryption.
 * @l: List of arguments from _printf.
 * @f: Pointer to the struct flags that determines.
 * if a flag is passed to _printf
 * Return: Length of the printed string.
 */
int print_rot13(va_list l, flags_t *f)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(l, char *);

	(void)f;
	for (j = 0; s[j]; j++)
	{
		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
			_putchar(s[j]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (s[j] == rot13[i])
					_putchar(ROT13[i]);
			}
		}
	}

	return (j);
}

/**
 * print_percent - prints a percent
 * @l: va_list arguments from _printf
 * @f: Pointer to flags struct for flag activation.
 * Return: Number of characters printed.
 */
int print_percent(va_list l, flags_t *f)
{
	(void)l;
	(void)f;
	return (_putchar('%'));
}
