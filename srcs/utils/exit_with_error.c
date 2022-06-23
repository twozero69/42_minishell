/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 04:42:05 by younglee          #+#    #+#             */
/*   Updated: 2022/06/23 20:16:51 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

void	exit_with_error(char *error_msg, t_minishell *minishell)
{
	ft_putendl_fd(error_msg, STDERR_FILENO);
	free_resources(minishell);
	exit(EXIT_FAILURE);
}
