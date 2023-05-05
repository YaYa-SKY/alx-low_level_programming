#include "main.h"
/**
 * set_bit - sets the value of a bit at a given index to 1
 *
 * @n: pointer to unsigned int to set the bit value of
 * @index: index of the bit to set the value of
 *
 * Return: 1 on success, or -1 if index is greater than 63
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63) /* check for valid index */
		return (-1);

	/* set the bit at index to 1 using bitwise OR */
	*n = *n | 1ul << index;

	return (1);
}
