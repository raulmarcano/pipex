/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:10:09 by rmarcano          #+#    #+#             */
/*   Updated: 2024/05/13 19:54:00 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_process(int *fd, char **argv, char **all_path)
{
	int	fd_infile;

	fd_infile = open(argv[1], O_RDONLY, 0777);
	if (fd_infile == -1)
	{
		perror("Can't access infile");
		exit(1);
	}
	dup2(fd[WRITE], STDOUT_FILENO);
	dup2(fd_infile, STDIN_FILENO);
	close(fd[READ]);
	execute_cmd(&all_path, argv[2]);
}

void	parent_process(int *fd, char **argv, char **all_path)
{
	int	fd_outfile;

	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile == -1)
	{
		perror("Can't access outfile");
		exit(1);
	}
	dup2(fd[READ], STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd[WRITE]);
	execute_cmd(&all_path, argv[3]);
}

int	main(int argc, char **argv, char **env)
{
	int			fd[2];
	char		**all_path;
	pid_t		pid;
	int			status;

	if (argc != 5)
		ft_error();
	else
	{
		if (pipe(fd) == -1)
			ft_error();
		pid = fork();
		if (pid == -1)
			ft_error();
		get_path(&all_path, env);
		if (pid == 0)
			child_process(fd, argv, all_path);
		parent_process(fd, argv, all_path);
		waitpid(pid, &status, 0);
	//	status = WEXITSTATUS(status);		funciona igual
	}
	return (status);
}
