#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>   // For open() and O_RDONLY
#include <unistd.h>  // For close()

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc != 2) // Ensure correct usage
    {
        printf("Usage: %s <file>\n", argv[0]);
        return (1);
    }

    fd = open(argv[1], O_RDONLY); // Open the file in read-only mode
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL) // Call get_next_line in a loop
    {
        printf("%s\n", line); // Print each line returned
        free(line); // Free the allocated memory for the line
    }

    close(fd); // Close the file descriptor
    return (0);
}
