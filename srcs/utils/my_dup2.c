/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 03:02:54 by younglee          #+#    #+#             */
/*   Updated: 2022/07/03 16:16:34 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_dup2(int old_fd, int new_fd, t_shell *shell)
{
	if (dup2(old_fd, new_fd) == FAIL)
		exit_with_clib_error("my_dup2.c: dup2", shell);
}
