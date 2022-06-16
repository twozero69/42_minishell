/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:06:47 by jubae             #+#    #+#             */
/*   Updated: 2022/06/17 01:07:04 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BONUS_H
# define MINISHELL_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <termcap.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_global	t_global;

struct	s_global
{
	int		exit;
	pid_t	pid;
	int		signal_on;
};

void	minishell(char **envp);

# define B_RED "\033[1;5;31m"
# define B_GREEN "\033[1;5;92m"
# define C_RESET "\e[0m"

# define PATH_MAX 1024
# define PID_MAX 100000
# define OFF 0
# define ON 1

#endif
