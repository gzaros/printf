#include "main.h"

/**
 * convert - Converts number & base to string.
 * @number: input number
 * @base: input base
 * @lowercase: Flag for lowercase hexadecimal values.
 * Return: result string
 */
char *convert(unsigned long int number, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[number % base];
		number /= base;
	} while (number != 0);

	return (ptr);
}
