/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:45:03 by rmarcano          #+#    #+#             */
/*   Updated: 2024/05/16 15:55:11 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	get_path(char ***all_path, char **env)
{
	char	*path;

	while (*env)
	{
		if (ft_strnstr(*env, "PATH=", 5))
		{
			path = ft_strdup(*env + 5);
			break ;
		}
		env++;
	}
	*all_path = ft_split(path, ':');
	free(path);
}

void	get_real_path(char **all_path, char **cmd, char **real_path)
{
	int		i;
	char	*aux_path;

	i = 0;
	if (access(cmd[0], X_OK) == 0 && *cmd)
	{
		*real_path = cmd[0];
		return ;
	}
	while (all_path[i] && *cmd)
	{
		aux_path = ft_strjoin(all_path[i], "/");
		*real_path = ft_strjoin(aux_path, cmd[0]);
		free(aux_path);
		if (access(*real_path, X_OK) == 0)
			return ;
		free(*real_path);
		i++;
	}
	perror("Command not found");
	if (!*cmd)
		exit(0);
	exit(127);
}

void	free_array(char ***array)
{
	int	i;

	if (*array)
	{	
		i = 0;
		while ((*array)[i])
		{
			free((*array)[i]);
			i++;
		}
		free(*array);
		*array = NULL;
	}
}

void	execute_cmd(char ***all_path, char *comand)
{
	char	**cmd;
	char	*real_path;

	real_path = NULL;
	cmd = ft_split(comand, ' ');
	get_real_path(*all_path, cmd, &real_path);
	execve(real_path, cmd, NULL);
	free_array(&cmd);
	free(real_path);
}
