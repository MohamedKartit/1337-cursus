/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:07:47 by mkartit           #+#    #+#             */
/*   Updated: 2024/02/09 15:11:08 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	get_outfile(char *av, t_file *files)
{
	if (files->flag == 1)
		files->outfile = open(av, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		files->outfile = open(av, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (files->outfile < 0)
		(perror("mypipex: outfile"), exit(1));
}

static void	spawn_pipes(t_file *files)
{
	int	i;

	i = 0;
	while (i < (files->cmds_nmbs - 1))
	{
		if (pipe(files->pipe_fd + 2 * i) < 0)
		{
			close(files->infile);
			close(files->outfile);
			if (files->flag == 1)
				unlink(".here_doc_tmp");
			free(files->pipe_fd);
		}
		i++;
	}
}

static void	init_function(char **av, t_file *file)
{
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		here_doc(av, file);
		file->flag = 1;
	}
	else
	{
		file->infile = open(av[1], O_RDONLY);
		if (file->infile < 0)
			(print_errors(av[1], NOFILE));
		file->flag = 0;
	}
}

static int	count_args(char *av)
{
	if (av && ft_strncmp(av, "here_doc", 9) == 0)
		return (6);
	return (5);
}

int	main(int ac, char **av, char **envp)
{
	t_file	file;
	int		i;

	if (ac < count_args(av[1]))
		(ft_putstr_fd("Invalid number of arguments\n", 2), exit(1));
	init_function(av, &file);
	get_outfile(av[ac - 1], &file);
	file.cmds_nmbs = ac - 3 - file.flag;
	file.pipe_fd = (int *)malloc(sizeof(int) * (file.cmds_nmbs - 1) * 2);
	if (!file.pipe_fd)
		(perror("mypipex: pipe_fd"), exit(1));
	spawn_pipes(&file);
	i = -1;
	while (++i < file.cmds_nmbs)
		run_childs(i, file, av, envp);
	close_pipes(&file);
	waitpid(-1, NULL, 0);
	close(file.infile);
	close(file.outfile);
	if (file.flag == 1)
		unlink(".here_doc_tmp");
	free(file.pipe_fd);
	return (0);
}
