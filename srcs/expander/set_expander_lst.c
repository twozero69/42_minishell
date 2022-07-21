/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_expander_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 00:08:11 by jubae             #+#    #+#             */
/*   Updated: 2022/07/19 09:20:43 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_env_set_envp_lst(char *env_temp, t_list *ret)
{
	int	j;

	j = 0;
	while (env_temp && env_temp[j])
	{
		if (env_temp[j] == ' ' || env_temp[j] == '\t' || env_temp[j] == '\n')
		{
			my_append_char_lst(ret, ' ');
			while (env_temp[j] == ' ' || \
			env_temp[j] == '\t' || env_temp[j] == '\n')
				j++;
		}
		else
		{
			find_wilcard_lst(env_temp, ret, j);
			j++;
		}
	}
}

int	when_other_lst(char *argv, t_shell *shell, t_list *ret, int i)
{
	char	*env_name;
	t_env	*env_temp;

	if (argv[i] == '$')
		if (argv[i + 1] == '?' && ++i && i++)
			my_append_str_lst(ret, ft_itoa(shell->exit_status));
	else
	{
		env_name = NULL;
		env_temp = NULL;
		while (!ft_strchr(" \t\n$\"\'\\/", argv[++i]))
			env_name = my_append_char(env_name, argv[i]);
		if (env_name != NULL)
			env_temp = get_env_from_key(env_name, shell->env_list);
		else
			my_append_char_lst(ret, '$');
		if (env_temp != NULL)
			get_env_set_envp_lst(env_temp->value, ret);
		if (env_name != NULL)
			free(env_name);
	}
	else
		find_wilcard_lst(argv, ret, i++);
	return (i);
}

int	when_dquote_env_lst(char *argv, t_shell *shell, t_list *ret, int i)
{
	char	*env_name;
	char	*temp;
	t_env	*env_temp;

	env_name = NULL;
	env_temp = NULL;
	if (argv[i + 1] == '?' && ++i && ++i)
		my_append_char_lst(ret, '0');
	else
	{
		while (!ft_strchr(" \t\n$\"\'\\/", argv[++i]))
			env_name = my_append_char(env_name, argv[i]);
		if (env_name != NULL)
			env_temp = get_env_from_key(env_name, shell->env_list);
		else
			my_append_char_lst(ret, '$');
		if (env_temp != NULL)
		{
			temp = (char *)ft_lstlast(ret)->content;
			(ft_lstlast(ret)->content) = ft_strjoin(temp, env_temp->value);
			free(temp);
		}
	}
	free(env_name);
	return (i);
}

int	when_dquote_lst(char *argv, t_shell *shell, t_list *ret, int i)
{
	i++;
	while (argv[i] != '\"')
	{
		if (argv[i] == '\\')
		{
			if (argv[i + 1] == '\"' || argv[i + 1] == '\\' || \
			argv[i + 1] == '`' || argv[i + 1] == '$')
				my_append_char_lst(ret, argv[++i]);
			else
				my_append_char_lst(ret, argv[i]);
			i++;
		}
		else if (argv[i] == '$')
			i = when_dquote_env_lst(argv, shell, ret, i);
		else
			my_append_char_lst(ret, argv[i++]);
	}
	i++;
	return (i);
}

void	set_expander_lst(char *argv, t_shell *shell, t_list *ret)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '\'' && ++i)
			while (argv[i++] != '\'')
				my_append_char_lst(ret, argv[i - 1]);
		else if (argv[i] == '\"')
			i = when_dquote_lst(argv, shell, ret, i);
		else
			i = when_other_lst(argv, shell, ret, i);
	}
}
