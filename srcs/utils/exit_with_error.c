/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 04:42:05 by younglee          #+#    #+#             */
/*   Updated: 2022/06/26 04:10:14 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_with_error(char *error_msg, t_shell *shell)
{
	print_minishell_error(TRUE, NULL, error_msg);
	free_resources(shell);
	exit(EXIT_FAILURE);
}
