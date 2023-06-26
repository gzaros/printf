#include "main.h"

/**
 * get_print - Selects appropriate printing function.
 * Selection of printing function based on conversion specifier.
 * @s: Character for conversion specifier.
 * Description: Loops through struct array.
 * func_arr[] Matches specifier in _printf.
 * Finds match with first struct element, then executes accordingly.
 * printing function
 * Return: Pointer to matching printing function.
 */
int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent}
		};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
