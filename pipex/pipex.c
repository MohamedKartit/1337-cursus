/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:24:35 by mkartit           #+#    #+#             */
/*   Updated: 2024/01/10 16:15:38 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_curr(char **cmd_args, char **paths, char **envp)
{
	if (access(cmd_args[0], F_OK) == 0 || cmd_args[0][0] == '.')
	{
		if (execve(cmd_args[0], cmd_args, envp) == -1)
		{
			print_errors(cmd_args[0], NOFILE);
			free_func(cmd_args);
			if (paths)
				free_func(paths);
			exit(1);
		}
	}
}

void	run_command(char *av, char **envp)
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
		exit(127);
	}
	if (execve(cmd, cmd_args, envp) == -1)
		(perror(""), exit(1));
}

void	child_process(char **av, char **envp, int *fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		(print_errors(av[1], NOFILE), exit(1));
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	run_command(av[2], envp);
}

void	parent_porcess(char **av, char **envp, int *fd)
{
	int	outfile;

	outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (outfile == -1)
	{
		perror("");
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	run_command(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int	n;
	int	child_id;
	int	fd[2];

	if (ac != 5)
		(ft_putstr_fd("Invalid number of arguments\n", 2), exit(1));
	if (pipe(fd) < 0)
		(perror("pipe"), exit(1));
	n = 0;
	child_id = fork();
	if (child_id == 0)
		child_process(av, envp, fd);
	else
	{
		child_id = fork();
		if (child_id == 0)
			parent_porcess(av, envp, fd);
		else
			close_fd(fd, n);
	}
	return (0);
}
