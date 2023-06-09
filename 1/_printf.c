#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _printf - Format output message.
 * @format: Format string with characters and specifiers.
 * Description: Call get_print() function.
 * Call appropriate printing function based on conversion.
 * specifiers contained into fmt
 * Return: Length of formatted output string.
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	va_list args;
	flags_t flags = {0, 0, 0};

	register int cnt = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				cnt += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			cnt += (pfunc)
				? pfunc(args, &flags)
				: _printf("%%%c", *p);
		} else
			cnt += _putchar(*p);
	}
	_putchar(-1);
	va_end(args);
	return (cnt);

}
