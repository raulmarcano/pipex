/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:10:09 by rmarcano          #+#    #+#             */
/*   Updated: 2024/05/07 17:52:38 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void    get_path(char ***all_path, char **env)
{
    char *path;

    while(*env)
    {
        if(ft_strnstr(*env, "PATH=", 5))
        {
            path = *env + 5;
            break;
        }
        env++;
    }
    *all_path = ft_split(path, ':');
    return ;
}

void    get_real_path(char **all_path, char **cmd, char **real_path)
{
    int i;
    char *aux_path;
    
    aux_path = NULL;
    i = 0;
    while (all_path[i])
    {
        aux_path = ft_strjoin(all_path[i], "/");
        *real_path = ft_strjoin(aux_path, cmd[0]);
        free(aux_path);
        if (access(*real_path, X_OK) != -1)
            break;
        free(*real_path);
        i++;
    }
    return ;
}

void free_array(char **array)
{
    int i = 0;

    while(array[i])
    {
        if(array)
            free(array[i]);
        i++;
    }
    free(array);
}


int main(int argc, char **argv, char **env)
{
    char **all_path;
    char **cmd;
    char *real_path;
    
    real_path = NULL;
    get_path(&all_path, env);
    cmd = ft_split(argv[2], ' ');
    get_real_path(all_path, cmd, &real_path);
    free_array(all_path);
    //ft_printf("Real full path: %s\n", real_path);
    //execve(real_path, cmd, NULL);
    free_array(cmd);
    free(real_path);
    (void)argc;
    (void)argv;
    (void)env;
    return (0);
}