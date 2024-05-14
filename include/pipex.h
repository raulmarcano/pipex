/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:43:46 by rmarcano          #+#    #+#             */
/*   Updated: 2024/05/14 19:23:03 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
#include <sys/wait.h>
# include "../libft/libft.h"

# define READ 0
# define WRITE 1

	// UTILS
void	ft_error(void);
void	get_path(char ***all_path, char **env);
void	get_real_path(char **all_path, char **cmd, char **real_path);
void	free_array(char ***array);
void	execute_cmd(char ***all_path, char *comand);

	//PROCESSES
void	parent_process(int *fd, char **argv, char ***all_path);
void	child_process(int *fd, char **argv, char ***all_path);

#endif