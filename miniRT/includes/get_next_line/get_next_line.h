/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho <aghergho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:57:34 by aghergho          #+#    #+#             */
/*   Updated: 2025/03/14 17:57:16 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
int		ftt_strlen(char *str);
int		check_end_line(char *str);
char	*str_sub(char *str, int len);

#endif