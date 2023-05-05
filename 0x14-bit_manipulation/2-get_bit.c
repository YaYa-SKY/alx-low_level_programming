#include "main.h"
/**
 * get_bit - gets the value of a bit at a given index
 *
 * @n: unsigned int to check the bit value of
 * @index: index of the bit to get the value of
 *
 * Return: value of the bit at index, or -1 if index is
 *         greater than 63
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	if (index > 63) /* check for valid index */
		return (-1);

	mask = 1ul << index; /* create mask to isolate bit at index */
	return ((n & mask) > 0); /* return the value of the bit */
}
