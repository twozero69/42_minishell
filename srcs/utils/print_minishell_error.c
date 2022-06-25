/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minishell_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:34:18 by younglee          #+#    #+#             */
/*   Updated: 2022/06/26 04:49:24 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_minishell_error(int shell_name_flag, char *msg1, char *msg2)
{
	if (shell_name_flag)
	{
		ft_putstr_fd("minishell", STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (msg1 != NULL)
	{
		ft_putstr_fd(msg1, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putendl_fd(msg2, STDERR_FILENO);
}
