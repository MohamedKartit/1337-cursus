/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:13:49 by mkartit           #+#    #+#             */
/*   Updated: 2023/11/27 19:13:52 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_new_lines(char *read_lines)
{
	int		i;
	int		j;
	char	*new_lines;

	i = 0;
	while (read_lines[i] && read_lines[i] != '\n')
		i++;
	if (!read_lines[i])
	{
		free(read_lines);
		return (NULL);
	}
	new_lines = (char *)malloc(sizeof(char) * (ft_strlen(read_lines) - i + 1));
	if (!new_lines)
		return (NULL);
	i++;
	j = 0;
	while (read_lines[i])
		new_lines[j++] = read_lines[i++];
	new_lines[j] = '\0';
	free(read_lines);
	return (new_lines);
}

char	*ft_lines(char *read_lines)
{
	char	*lines;
	int		i;

	i = 0;
	if (!read_lines[i])
		return (NULL);
	while (read_lines[i] && read_lines[i] != '\n')
		i++;
	i++;
	lines = (char *)malloc(sizeof(char) * i + 1);
	if (!lines)
		return (NULL);
	i = 0;
	while (read_lines[i] && read_lines[i] != '\n')
	{
		lines[i] = read_lines[i];
		i++;
	}
	if (read_lines[i] == '\n')
	{
		lines[i] = read_lines[i];
		i++;
	}
	lines[i] = '\0';
	return (lines);
}

char	*ft_read_lines(int fd, char *read_lines)
{
	char	*buffer;
	int		r;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	r = 1;
	while (!ft_strchr(read_lines, '\n') && r != 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			if (read_lines)
				free(read_lines);
			return (NULL);
		}
		buffer[r] = '\0';
		read_lines = ft_strjoin(read_lines, buffer);
	}
	free (buffer);
	return (read_lines);
}

char	*get_next_line(int fd)
{
	static char	*read_lines[FD_MAX];
	char		*lines;

	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	read_lines[fd] = ft_read_lines(fd, read_lines[fd]);
	if (!read_lines[fd])
		return (NULL);
	lines = ft_lines(read_lines[fd]);
	read_lines[fd] = ft_new_lines(read_lines[fd]);
	return (lines);
}

/*
#include <stdio.h>
int main() {
    char *lines;

    int rd1 = open("test.txt", O_RDONLY);
    if (rd1 < 0)
        return (-1);
    int rd2 = open("test1.txt", O_RDONLY);
    if (rd2 < 0)
        return (-1);
    int rd3 = open("test2.txt", O_RDONLY);
    if (rd3 < 0)
        return (-1);

	for(int x = 0; x < 100; x++)
	{
		lines = get_next_line(rd1);
		printf("%d -> %s", x, lines);
		free(lines);
	}
	for(int x = 0; x < 100; x++)
	{
		lines = get_next_line(rd2);
		printf("%d -> %s", x, lines);
		free(lines);
	}
	for(int x = 0; x < 100; x++)
	{
		lines = get_next_line(rd3);
		printf("%d -> %s",x ,lines);
		free(lines);
	}
	close(rd1);
	close(rd2);
	close(rd3);
	system("leaks a.out");
    return 0;
}
*/