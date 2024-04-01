/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:11:41 by mkartit           #+#    #+#             */
/*   Updated: 2024/04/01 17:45:13 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	close_pipes(t_file *files)
{
	int	i;
	int	number;

	i = 0;
	number = (files->cmds_nmbs - 1) * 2;
	while (i < number)
	{
		close(files->pipe_fd[i]);
		i++;
	}
}

static void	double_dup(int fd1, int fd2)
{
	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
}

void	run_childs(int num, t_file file, char **av, char **envp)
{
	file.pid = fork();
	if (file.pid == -1)
		(perror("pipex: fork failed"), exit(1));
	if (file.pid == 0)
	{
		if (num == 0)
			double_dup(file.infile, file.pipe_fd[1]);
		else if (num == file.cmds_nmbs - 1)
			double_dup(file.pipe_fd[2 * num - 2], file.outfile);
		else
			double_dup(file.pipe_fd[2 * num - 2], file.pipe_fd[2 * num + 1]);
		close_pipes(&file);
		run_command_bonus(av[2 + file.flag + num], envp, &file);
	}
}

void	here_doc(char **av, t_file *files)
{
	int		file;
	char	*line;

	file = open(".here_doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file < 0)
		(perror("mypipex: here_doc"), exit(1));
	line = NULL;
	while (1)
	{
		ft_putstr_fd("mypipex heredoc> ", 1);
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, av[2], ft_strlen(line) - 1) == 0)
			break ;
		if (write(file, line, ft_strlen(line)) == -1)
			(perror("mypipex: here_doc"), exit(1));
		free(line);
	}
	if (line)
		free(line);
	close(file);
	files->infile = open(".here_doc_tmp", O_RDONLY);
	if (files->infile < 0)
		(unlink(".here_doc_tmp"), perror("mypipex: here_doc"), exit(1));
}
