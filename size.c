#include "main.h"

/**
 * get_size - Calculates argument's size for casting.
 * @fmt: Print destination string for arguments.
 * @i: Argument list for printing.
 *
 * Return: Precision
 */
int get_size(const char *fmt, int *i)
{
	int curr_i = *i + 1;
	int _size = 0;

	if (fmt[curr_i] == 'l')
		_size = S_LONG;
	else if (fmt[curr_i] == 'h')
		_size = S_SHORT;

	if (_size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (_size);
}


