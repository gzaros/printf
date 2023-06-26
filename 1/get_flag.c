#include "main.h"

/**
 * get_flag - Turns on flags if _printf finds.
 * Flag modifier in format string.
 * @s: Character for flag specifier.
 * @f: Pointer to flags struct for flag activation.
 *
 * Return: Flag status: 1 if turned on, 0 otherwise.
 */
int get_flag(char s, flags_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}

	return (i);
}
