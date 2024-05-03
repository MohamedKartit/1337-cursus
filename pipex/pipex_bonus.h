/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:25:38 by mkartit           #+#    #+#             */
/*   Updated: 2024/04/16 11:35:15 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

typedef struct s_file
{
	int	infile;
	int	outfile;
	int	cmds_nmbs;
	int	*pipe_fd;
	int	flag;
	int	pid;
}	t_file;

# define NOFILE "mypipex: No such file or directory: "
# define NOCMD "mypipex: command not found: "

/*=============== helper functions ===============*/
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

/*=============== pipex bonus ====================*/
char	**get_path(char **envp);
void	free_func(char **strings);
char	*check_command(char *cmd, char **paths);
void	run_command_bonus(char *av, char **envp, t_file *file);
void	run_childs(int num, t_file file, char **argv, char **envp);
void	close_pipes(t_file *files);
void	here_doc(char **av, t_file *files);
void	run_curr(char **cmd_args, char **paths, char **envp);

/*=============== get_next_line ===================*/
char	*ft_strchr(char *s, char c);
char	*get_next_line(int fd);
char	*ft_strjoin_get_next_line(char *s1, char *s2);
size_t	ft_strlen_get_next_line(const char *s);

/*================= printing =====================*/
void	ft_putstr_fd(char *s, int fd);
void	print_errors(char *av, char *msg);

#endif /* PIPEX_BONUS_H */
