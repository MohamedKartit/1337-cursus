/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:11:32 by mkartit           #+#    #+#             */
/*   Updated: 2024/02/09 15:11:34 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		if (access(command, 0) == 0)
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
	while (envp[x] && ft_strncmp("PATH=", envp[x], 5))
		x++;
	if (envp[x])
		cmd_paths = ft_split(envp[x] + 5, ':');
	return (cmd_paths);
}

void	run_command_bonus(char *av, char **envp, t_file *file)
{
	char	**cmd_args;
	char	**paths;
	char	*cmd;

	cmd = NULL;
	paths = NULL;
	cmd_args = ft_split(av, ' ');
	paths = get_path(envp);
	run_curr(cmd_args, paths, envp);
	cmd = check_command(cmd_args[0], paths);
	if (cmd == NULL)
	{
		print_errors(cmd_args[0], NOCMD);
		free_func(cmd_args);
		if (paths)
			free_func(paths);
		(free(file->pipe_fd), exit(127));
	}
	if (execve(cmd, cmd_args, envp) == -1)
		(perror(""), free(file->pipe_fd), exit(1));
}

void	print_errors(char *av, char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd("\n", 2);
}
