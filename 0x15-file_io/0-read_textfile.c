#include "main.h"

/**

Function to read and print a text file to stdout

@param filename Pointer to the filename

@param letters Number of letters to be read and printed

@return Number of letters read and printed
*/
ssize_t read_file(const char *filename, size_t letters)
{
int file;
ssize_t n_In, n_Out;
char *fptr;

if (!filename)
return 0;

file = open(filename, O_RDONLY);
if (file == -1)
return 0;

fptr = malloc(letters * sizeof(char));
if (!fptr)
return 0;

n_In = read(file, fptr, letters);
n_Out = write(STDOUT_FILENO, fptr, n_In);

if (n_Out != n_In && n_Out == -1)
return 0;

free(fptr);
close(file);
return n_In;
}
