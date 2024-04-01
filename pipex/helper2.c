/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:34:42 by mkartit           #+#    #+#             */
/*   Updated: 2024/01/24 16:34:44 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		if ((unsigned char)s1[len] > (unsigned char)s2[len])
			return (1);
		else if ((unsigned char)s1[len] < (unsigned char)s2[len])
			return (-1);
		else if ((unsigned char)s1[len] == 0 || (unsigned char)s2[len] == 0)
			return ((unsigned char)s1[len] - (unsigned char)s2[len]);
		len++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*new_string;
	int		i;

	i = 0;
	new_string = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	while (s[i])
	{
		new_string[i] = s[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*ptr;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ptr = str;
	while (*s1 != '\0' && s1)
		*ptr++ = *s1++;
	while (*s2 != '\0' && s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (str);
}

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	l;

	if (fd < 0 || !s)
		return ;
	l = 0;
	while (s[l])
		write(fd, &s[l++], 1);
}
