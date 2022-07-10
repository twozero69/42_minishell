/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:03:39 by younglee          #+#    #+#             */
/*   Updated: 2022/07/08 16:39:50 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_identifier_error(char *arg)
{
	ft_putstr_fd("minishell: unset: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(": not a valid identifier", STDERR_FILENO);
}

static int	check_arg(char *arg)
{
	if (ft_isalpha(*arg) == FALSE && *arg != '_')
		return (FALSE);
	arg++;
	while (*arg != '\0')
	{
		if (ft_isalnum(*arg) == FALSE && *arg != '_')
			return (FALSE);
		arg++;
	}
	return (TRUE);
}

static void	free_env(t_list *list)
{
	t_env	*env;

	env = (t_env *)list->content;
	my_free((void **)&env->key);
	my_free((void **)&env->value);
	my_free((void **)&env);
	my_free((void **)&list);
}

static void	remove_env_from_envp(char *key, t_list *curr, t_list **env_list)
{
	t_env	*find_env;
	t_env	*curr_env;
	t_list	*prev;
	t_list	*next;

	find_env = get_env_from_key(key, *env_list);
	if (find_env == NULL)
		return ;
	prev = NULL;
	while (curr != NULL)
	{
		curr_env = (t_env *)curr->content;
		next = curr->next;
		if (find_env == curr_env)
		{
			if (prev == NULL)
				*env_list = next;
			else
				prev->next = next;
			free_env(curr);
			break ;
		}
		prev = curr;
		curr = next;
	}
}

void	builtin_unset(char **argv, t_shell *shell)
{
	int	idx;

	if (argv[1] == NULL)
	{
		shell->exit_status = EXIT_SUCCESS;
		return ;
	}
	idx = 1;
	while (argv[idx] != NULL)
	{
		if (check_arg(argv[idx]) == FALSE)
		{
			print_identifier_error(argv[idx]);
			shell->exit_status = EXIT_FAILURE;
			return ;
		}
		remove_env_from_envp(argv[idx], shell->env_list, &shell->env_list);
		idx++;
	}
	shell->exit_status = EXIT_SUCCESS;
}
