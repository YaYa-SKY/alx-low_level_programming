#include "main.h"
/**
 * clear_bit - sets the value of a bit at a given index to 0
 *
 * @n: pointer to unsigned int to clear the bit value of
 * @index: index of the bit to clear the value of
 *
 * Return: 1 on success, or -1 if index is greater than 63
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63) /* check for valid index */
		return (-1);

	/* clear the bit at index to 0 using bitwise AND with complement */
	*n = *n & ~(1ul << index);

	return (1);
}
