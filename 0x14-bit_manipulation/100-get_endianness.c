#include "main.h"
/**
 * get_endianness - determines the endianness of the machine
 *
 * Return: 0 for big endian, 1 for little endian
 */
int get_endianness(void)
{
	/* create integer value and examine its first byte */
	int n = 1;

	/* check whether the first byte is 0 or 1, indicating endianness */
	return (*((char *) &n) + '0');
}
