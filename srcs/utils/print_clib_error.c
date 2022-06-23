/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_clib_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:56:14 by younglee          #+#    #+#             */
/*   Updated: 2022/06/23 19:50:39 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

void	print_clib_error(char *file_name, char *func_name)
{
	if (errno == 0)
		return ;
	ft_putstr_fd(file_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(func_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	errno = 0;
}
