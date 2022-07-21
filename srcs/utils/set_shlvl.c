/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:39:04 by younglee          #+#    #+#             */
/*   Updated: 2022/07/08 02:21:14 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_numeric(char *value)
{
	if (*value == '+' || *value == '-')
		value++;
	if (*value == '\0')
		return (FAIL);
	while (*value != '\0')
	{
		if (ft_isdigit(*value) == FALSE)
			return (FALSE);
		value++;
	}
	return (TRUE);
}

static int	check_positive(char *value)
{
	if (*value != '-')
		return (TRUE);
	value++;
	while (*value != '\0')
	{
		if (*value != '0')
			return (FALSE);
		value++;
	}
	return (TRUE);
}

static int	check_overflow(char *value)
{
	size_t	value_len;
	size_t	cmp_len;

	if (*value == '+' || *value == '-')
		value++;
	while (*value == '0')
		value++;
	value_len = ft_strlen(value);
	cmp_len = ft_strlen("2147483647");
	if (value_len < cmp_len)
		return (FALSE);
	if (value_len > cmp_len)
		return (TRUE);
	if (ft_strncmp(value, "2147483647", cmp_len + 1) < 0)
		return (FALSE);
	return (TRUE);
}

static void	print_shlvl_max_over_error(int new_shlvl)
{
	ft_putstr_fd("minishell: warning: shell level (", STDERR_FILENO);
	ft_putnbr_fd(new_shlvl, STDERR_FILENO);
	ft_putendl_fd(") too high, resetting to 1", STDERR_FILENO);
}

int	set_shlvl(t_shell *shell)
{
	t_env	*shlvl_env;
	int		new_shlvl;

	shlvl_env = get_env_from_key("SHLVL", shell->env_list);
	if (shlvl_env == NULL)
		return (add_env_with_value("SHLVL", "1", shell));
	if (shlvl_env->value == NULL)
		return (add_env_with_value("SHLVL", "1", shell));
	if (check_numeric(shlvl_env->value) == FALSE)
		return (add_env_with_value("SHLVL", "1", shell));
	if (check_positive(shlvl_env->value) == FALSE)
		return (add_env_with_value("SHLVL", "0", shell));
	if (check_overflow(shlvl_env->value) == TRUE)
		return (add_env_with_value("SHLVL", "0", shell));
	new_shlvl = ft_atoi(shlvl_env->value) + 1;
	if (new_shlvl >= 1000)
	{
		print_shlvl_max_over_error(new_shlvl);
		return (add_env_with_value("SHLVL", "1", shell));
	}
	my_free((void **)&shlvl_env->value);
	shlvl_env->value = ft_itoa(new_shlvl);
	return (SUCCESS);
}
