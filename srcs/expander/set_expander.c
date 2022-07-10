/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_expander.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 00:08:11 by jubae             #+#    #+#             */
/*   Updated: 2022/07/11 00:15:53 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_set_envp(char *env_temp, char *result)
{
	int	j;

	j = 0;
	while (env_temp && env_temp[j])
	{
		if (env_temp[j] == ' ' || env_temp[j] == '\t' || env_temp[j] == '\n')
		{
			result = my_append_char(result, ' ');
			while (env_temp[j] == ' ' || \
			env_temp[j] == '\t' || env_temp[j] == '\n')
				j++;
		}
		else
		{
			result = my_append_char(result, env_temp[j]);
			j++;
		}
	}
	return (result);
}

int	when_other(char *arg, t_list *env_list, char **result, int i)
{
	char	*env_name;
	t_env	*env_temp;

	(void)env_list;
	if (arg[i] == '$')
	{
		if (arg[i + 1] == '?')
		{
			*result = my_append_char(*result, '0');
			i += 2;
		}
		else
		{
			env_name = NULL;
			while (!ft_strchr(" \t\n$\"\'\\/", arg[++i]))
				env_name = my_append_char(env_name, arg[i]);
			env_temp = get_env_from_key(env_name, env_list);
			if (env_temp != NULL)
				*result = get_env_set_envp(env_temp->value, *result);
			free(env_name);
		}
	}
	else
		*result = my_append_char(*result, arg[i++]);
	return (i);
}

int	when_dquote_env(char *arg, t_list *env_list, char **result, int i)
{
	char	*env_name;
	char	*temp;
	t_env	*env_temp;

	env_name = NULL;
	if (arg[i + 1] == '?')
	{
		*result = my_append_char(*result, '0');
		i += 2;
	}
	else
	{
		while (!ft_strchr(" \t\n$\"\'\\/", arg[++i]))
			env_name = my_append_char(env_name, arg[i]);
		env_temp = get_env_from_key(env_name, env_list);
		if (env_temp != NULL)
		{
			temp = *result;
			*result = ft_strjoin(temp, env_temp->value);
			free(temp);
		}
	}
	free(env_name);
	return (i);
}

int	when_dquote(char *arg, t_list *env_list, char **result, int i)
{
	i++;
	while (arg[i] != '\"')
	{
		if (arg[i] == '\\')
		{
			if (arg[i + 1] == '\"' || arg[i + 1] == '\\' || \
			arg[i + 1] == '`' || arg[i + 1] == '$')
				*result = my_append_char(*result, arg[++i]);
			else
				*result = my_append_char(*result, arg[i]);
			i++;
		}
		else if (arg[i] == '$')
			i = when_dquote_env(arg, env_list, result, i);
		else
			*result = my_append_char(*result, arg[i++]);
	}
	i++;
	return (i);
}

char	*set_expander(char *argv, t_list *env_list)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)ft_calloc(1, sizeof(char));
	while (argv[i])
	{
		if (argv[i] == '\'' && ++i)
			while (argv[i++] != '\'')
				ret = my_append_char(ret, argv[i - 1]);
		else if (argv[i] == '\"')
			i = when_dquote(argv, env_list, &ret, i);
		else
			i = when_other(argv, env_list, &ret, i);
	}
	free(argv);
	return (ret);
}
