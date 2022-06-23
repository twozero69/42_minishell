/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 10:20:47 by younglee          #+#    #+#             */
/*   Updated: 2022/06/24 01:49:52 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stddef.h>
#include <errno.h>
#include <readline/readline.h>
#include "minishell.h"

static void	my_dup(int *dst_fd, int src_fd)
{
	*dst_fd = dup(src_fd);
	if (*dst_fd == -1)
		print_clib_error("main.c", "dup");
}

static void	add_new_env(char *key_src, char *value_src, t_list **env_list)
{
	t_list	*new_node;
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	ft_memset(env, 0, sizeof(t_env));
	if (env == NULL)
		print_clib_error("init.c", "malloc");
	env->key = ft_strdup(key_src);
	if (env->key == NULL)
		print_clib_error("init.c", "ft_strdup: malloc");
	env->value = ft_strdup(value_src);
	if (env->value == NULL)
		print_clib_error("init.c", "ft_strdup: malloc");
	new_node = ft_lstnew((void *)env);
	if (new_node == NULL)
		print_clib_error("init.c", "ft_lstnew: malloc");
	ft_lstadd_back(env_list, new_node);
}

static void	init_env_list(char **envp, t_list **env_list)
{
	char	*equal;

	while (*envp != NULL)
	{
		equal = ft_strchr(*envp, '=');
		if (equal != NULL)
		{
			*equal = '\0';
			add_new_env(*envp, equal + 1, env_list);
			*equal = '=';
		}
		envp++;
	}
}

void	init(int argc, char **argv, char **envp, t_minishell *minishell)
{
	errno = 0;
	minishell->exit_status = 0;
	minishell->env_list = NULL;
	minishell->stdin_fd = -1;
	minishell->stdout_fd = -1;
	minishell->stderr_fd = -1;
	if (argc != 1 || argv == NULL || envp == NULL)
		exit_with_error("argument error", minishell);
	my_dup(&minishell->stdin_fd, STDIN_FILENO);
	my_dup(&minishell->stdout_fd, STDOUT_FILENO);
	my_dup(&minishell->stderr_fd, STDERR_FILENO);
	init_env_list(envp, &minishell->env_list);
	signal(SIGQUIT, SIG_IGN);
}
