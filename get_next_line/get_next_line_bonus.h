/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:14:18 by mkartit           #+#    #+#             */
/*   Updated: 2023/11/27 19:15:20 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
char	*ft_read_lines(int fd, char *get_line);
char	*ft_lines(char *read_lines);
char	*ft_new_lines(char *read_lines);
char	*get_next_line(int fd);

#endif /* GET_NEXT_LINE_H */
