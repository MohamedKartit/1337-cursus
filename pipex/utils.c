/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:01:45 by mkartit           #+#    #+#             */
/*   Updated: 2024/01/10 17:54:48 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_command(char *cmd, char **paths)
{
	char	*path_part;
	char	*command;

	command = NULL;
	path_part = NULL;
	if (!paths || !cmd)
		return (NULL);
	while (*paths)
	{
		path_part = ft_strjoin(*paths, "/");
		command = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	free_func(char **strings)
{
	int	x;

	x = -1;
	while (strings[++x])
		free(strings[x]);
	free(strings);
}

char	**get_path(char **envp)
{
	int		x;
	char	**cmd_paths;

	cmd_paths = NULL;
	x = 0;
	while (envp[x] && ft_strncmp("PATH", envp[x], 4))
		x++;
	if (envp[x])
		cmd_paths = ft_split(envp[x] + 5, ':');
	return (cmd_paths);
}

void	print_errors(char *av, char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd("\n", 2);
}

void	close_fd(int *fd, int n)
{
	close(fd[0]);
	close(fd[1]);
	while (wait(&n) > 0)
		;
	if (WIFEXITED(n))
		exit(WEXITSTATUS(n));
	exit(0);
}
