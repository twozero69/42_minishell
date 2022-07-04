/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:20:43 by younglee          #+#    #+#             */
/*   Updated: 2022/07/04 23:28:05 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_env_list_to_array(t_env **env_array, t_list *env_list)
{
	int	idx;

	idx = 0;
	while (env_list != NULL)
	{
		env_array[idx] = (t_env *)env_list->content;
		idx++;
		env_list = env_list->next;
	}
	env_array[idx] = NULL;
}

static void	sort_env_array(t_env **env_array, int num_env)
{
	int		i;
	int		j;
	char	*key1;
	char	*key2;
	t_env	*term;

	i = num_env - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			key1 = env_array[j]->key;
			key2 = env_array[j + 1]->key;
			if (ft_strncmp(key1, key2, ft_strlen(key1) + 1) > 0)
			{
				term = env_array[j];
				env_array[j] = env_array[j + 1];
				env_array[j + 1] = term;
			}
			j++;
		}
		i--;
	}
}

static t_env	**get_sorted_array(t_list *env_list)
{
	int		num_env;
	t_env	**sorted_array;

	num_env = ft_lstsize(env_list);
	sorted_array = (t_env **)malloc((num_env + 1) * sizeof(t_env *));
	if (sorted_array == NULL)
		return (NULL);
	copy_env_list_to_array(sorted_array, env_list);
	sort_env_array(sorted_array, num_env);
	return (sorted_array);
}

static void	print_env(t_env *env)
{
	char	*value;

	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	ft_putendl_fd(env->key, STDOUT_FILENO);
	if (env->value == NULL)
		return ;
	ft_putstr_fd("=\"", STDOUT_FILENO);
	value = env->value;
	while (*value != '\0')
	{
		if (*value == '"' || *value == '\\' || *value == '$')
			ft_putchar_fd('\\', STDOUT_FILENO);
		ft_putchar_fd(*value, STDOUT_FILENO);
		value++;
	}
	ft_putendl_fd("\"", STDOUT_FILENO);
}

int	print_export_list(t_shell *shell)
{
	t_env	**sorted_array;

	sorted_array = get_sorted_array(shell->env_list);
	if (sorted_array == NULL)
		return (FAIL);
	while (*sorted_array != NULL)
	{
		print_env(*sorted_array);
		sorted_array++;
	}
	return (SUCCESS);
}
