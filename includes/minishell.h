/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:24:41 by jubae             #+#    #+#             */
/*   Updated: 2022/06/23 22:08:06 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_env
{
	char	*key;
	char	*value;
}	t_env;

typedef struct s_minishell
{
	int				exit_status;
	int				stdin_fd;
	int				stdout_fd;
	int				stderr_fd;
	t_list			*env_list;
}	t_minishell;

//exit_with_error.c
void	exit_with_error(char *error_msg, t_minishell *minishell);

//print_clib_error.c
void	print_clib_error(char *file_name, char *func_name);

//free_resources.c
void	free_resources(t_minishell *minishell);

//init.c
void	init(int argc, char **argv, char **envp, t_minishell *minishell);

#endif
