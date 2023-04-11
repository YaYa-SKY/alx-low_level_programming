#include <stdlib.h>
#include "main.h"

/**
 * *str_concat - concatenates two strings
 * @s1: string to concatenate
 * @s2: other string to concatenate
 *
 * Return: pointer to the new string created (Success), or NULL (Error)
 */
char *str_concat(char *s1, char *s2)
{
	char *s3;
	unsigned int i = 0, j = 0, len1 = 0, len2 = 0;

	while (s1 && s1[len1])
		len1++;
	while (s2 && s2[len2])
		len2++;

	s3 = malloc(sizeof(char) * (len1 + len2 + 1)); //5
	if (s3 == NULL)
		return (NULL);

	i = 0;//s1=he
	j = 0;//s2=is

	if (s1)
	{
		while (i < len1) //i=0 len=2
		{
			s3[i] = s1[i]; // s3[0]=s1[0]=h
			i++; //s3[i]=1 s1[1]=e
		}		// s3[i]=he;
	}

	if (s2)
	{
		while (i < (len1 + len2))
		{
			s3[i] = s2[j];   // s3[i]=he, s2[j]=0
			i++;             //s3[i]=he,i=2+1 s2[j]=i == s3[i]=hei
			j++;             //s3[i]=he,i=3+1 s2[j]=s == s3[i]=heis
		}
	}// i=4
	s3[i] = '\0';   add null char                 // s3[i]=heis + '\0'

	return (s3);
}
