/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:10:09 by rmarcano          #+#    #+#             */
/*   Updated: 2024/04/29 16:10:12 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char *get_path(char **envp)
{
    char *path;

    path = NULL;
    while(envp)
    {
        if(ft_strnstr(*envp, "PATH=", 5))
        {
            path = *envp + 5;
            break;
        }
        envp++;
    }
    ft_printf("%s", path);
    return(path);
}

int main(int argc, char **argv, char **envp)
{
    argc = 1 + argc;
    (void)argv;
    (void)envp;
    return 0;
}