/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:43:46 by rmarcano          #+#    #+#             */
/*   Updated: 2024/05/08 14:53:15 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
#include <fcntl.h>

# include "../libft/libft.h"
# define READ_END 0
# define WRITE_END 1


void    get_path(char ***all_path, char **env);

#endif