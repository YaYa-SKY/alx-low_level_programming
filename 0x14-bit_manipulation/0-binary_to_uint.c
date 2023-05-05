#include "main.h"
/**
 * binary_to_uint - converts binary string to unsigned int
 * @b: binary string to convert
 *
 * Return: unsigned integer result of conversion, or 0 if b
 *         is NULL or contains non-binary characters
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int base = 1, i = 0;

	if (b == NULL) /* check for null pointer */
		return (0);

	while (b[i + 1]) /* check for non-binary characters */
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		i++;
	}

	while (i >= 0) /* convert to decimal */
	{
		result += ((b[i] - '0') * base);
		base *= 2;
		i--;
	}

	return (result);
}
