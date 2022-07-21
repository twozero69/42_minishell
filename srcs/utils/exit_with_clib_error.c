/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_clib_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:06:28 by younglee          #+#    #+#             */
/*   Updated: 2022/07/18 18:36:34 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_with_clib_error(char *error_msg, t_shell *shell)
{
	print_minishell_error(TRUE, error_msg, strerror(errno));
	free_resources(shell);
	exit(EXIT_FAILURE);
}
