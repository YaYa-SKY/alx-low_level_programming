#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
void print_chessboard(char (*a)[8]);
void set_string(char **s, char *to);
int _putchar(char c);

#endif /* MAIN_H */
