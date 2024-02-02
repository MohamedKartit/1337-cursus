/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:02:05 by mkartit           #+#    #+#             */
/*   Updated: 2023/11/04 14:02:06 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_checker(char c, const char *set)
{
	unsigned int	len;

	len = 0;
	while (set[len])
	{
		if (c == set[len])
			return (1);
		len++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			end;
	size_t			start;
	char			*res;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	end = ft_strlen(s1);
	start = 0;
	while (s1[start] && set_checker(s1[start], set))
		start++;
	while (end > start && set_checker(s1[end - 1], set))
		end--;
	res = ft_substr(s1, start, end - start);
	return (res);
}
