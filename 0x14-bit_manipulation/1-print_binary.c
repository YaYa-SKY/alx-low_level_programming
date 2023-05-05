#include "main.h"
#include <unistd.h>
#include <limits.h>
/**
 * print_binary - prints an unsigned int in binary
 *
 * @n: unsigned int to print in binary
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int printbit = 1ul << 63;
	char c = '0';

	/* find the highest bit that is set */
	while (!(printbit & n) && printbit != 0)
		printbit = printbit >> 1;

	if (printbit == 0) /* handle the case where n is 0 */
		write(1, &c, 1);

	/* print the binary representation of n */
	while (printbit)
	{
		if (printbit & n)
			c = '1';
		else
			c = '0';
		write(1, &c, 1);
		printbit = printbit >> 1;
	}
}
