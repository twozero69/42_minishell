/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_child_exit_status.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 06:19:14 by younglee          #+#    #+#             */
/*   Updated: 2022/07/17 06:28:55 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_child_exit_status(int status)
{
	if (WIFEXITED(status) == TRUE)
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status) == TRUE)
		return (WTERMSIG(status) + 128);
	return (EXIT_FAILURE);
}
