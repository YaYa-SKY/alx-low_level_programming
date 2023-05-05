#include "main.h"
/**
 * flip_bits - counts the number of bits that need to be flipped
 * to convert one number to another
 *
 * @n: first number to compare
 * @m: second number to compare
 *
 * Return: the number of bits that need to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;

	/* compare each bit of n and m, incrementing count if they differ */
	while (n != 0 || m != 0)
	{
		if ((n & 1) != (m & 1))
			count++;
		m = m >> 1;
		n = n >> 1;
	}

	return (count);
}
