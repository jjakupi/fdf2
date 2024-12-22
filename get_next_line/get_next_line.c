#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static char	*join_leftovers_and_buffer(int fd, char *left_overs, char *buffer)
{
	ssize_t	read_line;
	char	*temp;

	while ((read_line = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_line] = '\0'; // Null-terminate the buffer
		if (!left_overs)
			left_overs = ft_strdup_gnl("");
		temp = left_overs;
		left_overs = ft_strjoin_gnl(temp, buffer);
		free(temp);
		if (ft_strchr_gnl(buffer, '\n')) // Stop when newline is found
			break ;
	}
	if (read_line == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (left_overs);
}

static char	*extract_line_from_leftovers(char *combined_da)
{
	ssize_t		i;
	char		*remaining_da;

	i = 0;
	if (!combined_da[i])
		return (NULL);
	while (combined_da[i] != '\n' && combined_da[i] != '\0')
		i++;
	if (combined_da[i] == 0 || combined_da[1] == 0)
		return (NULL);
	remaining_da = ft_substr_gnl(combined_da, i + 1, ft_strlen_gnl(combined_da) - i);
	if (*remaining_da == 0)
	{
		free(remaining_da);
		remaining_da = NULL;
	}
	combined_da[i + 1] = 0;
	return (remaining_da);
}

char	*get_next_line(int fd)
{
	static char			*remaining_da;
	char				*complete_line;
	char				*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(remaining_da);
		free(buffer);
		remaining_da = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	complete_line = join_leftovers_and_buffer(fd, remaining_da, buffer);
	free(buffer);
	buffer = (NULL);
	if (!complete_line)
		return (NULL);
	remaining_da = extract_line_from_leftovers(complete_line);
	return (complete_line);
	printf("Buffer: %s\n", buffer);
	printf("Remaining: %s\n", remaining_da);
	printf("Complete Line: %s\n", complete_line);

}
