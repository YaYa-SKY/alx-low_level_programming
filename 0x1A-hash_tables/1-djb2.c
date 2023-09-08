/**
 * hash_djb2 - Hashes a string into a numeric value.
 * @str: The input string (unique in the hash table).
 *
 * Return: The resulting hash value.
 */

unsigned long int hash_djb2(const unsigned char *str)
{
    unsigned long int hash;
    int c;

    hash = 5381;
    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return (hash);
}
