/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:58:18 by mkartit           #+#    #+#             */
/*   Updated: 2024/01/10 16:16:40 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
// TODO 
# define NOFILE "mypipex: No such file or directory: "
# define NOCMD "mypipex: command not found: "

// function for printing erorrs
/*================ Pipex ==================*/
void	child_process(char **av, char **envp, int *fd);
void	parent_porcess(char **av, char **envp, int *fd);
void	run_command(char *av, char **envp);
void	close_fd(int *fd, int n);
char	*check_command(char *cmd, char **paths);
char	**get_path(char **envp);
void	run_curr(char **cmd_args, char **paths, char **envp);

/*================ parsing =================*/
char	**ft_split(char const *s, char c);
void	free_func(char **strings);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

/*================ Printing ===============*/
void	ft_putstr_fd(char *s, int fd);
void	print_errors(char *av, char *msg);

#endif /* PIPEX_H */
