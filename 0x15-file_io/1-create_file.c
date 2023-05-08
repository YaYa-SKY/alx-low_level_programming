#include "main.h"

/**
 * create_file - This function creates a new file with given name and text content
 * @filename: The name of the new file
 * @text_content: The string to be written to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
    int fd, len, write_result;

    if (filename == NULL)
        return (-1);

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (fd == -1)
        return (-1);

    if (!text_content)
        text_content = "";

    len = 0;
    while (text_content[len])
        len++;

    write_result = write(fd, text_content, len);
    if (write_result == -1)
        return (-1);

    close(fd);
    return (1);
}
