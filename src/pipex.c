/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:10:09 by rmarcano          #+#    #+#             */
/*   Updated: 2024/05/06 18:36:49 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char **get_path(char **envp)
{
    char *path;
    char **path_splitted;

    while(*envp)
    {
        if(ft_strnstr(*envp, "PATH=", 5))
        {
            path = *envp + 5;
            break;
        }
        envp++;
    }
    path_splitted = ft_split(path, ':');
    return(path_splitted);
}

int main(int argc, char **argv, char **envp)
{
    get_path(envp);
    char **cmd;

    cmd = ft_split(argv[2], ' ');
    while (cmd)
    {
        ft_printf("%s\n", *cmd);
        cmd++;
    }
    argc = 1 + argc;
    (void)argv;
    (void)envp;
    return 0;
}