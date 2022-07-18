/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wilcard_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 05:30:05 by jubae             #+#    #+#             */
/*   Updated: 2022/07/19 05:37:20 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wilcard_sort_util(char **s, int c, int (*m)(const char *, char *))
{
	int		i;

	while (c > 1)
	{
		i = 0;
		while (i < c - 1)
		{
			if (m(s[i], s[i + 1]) > 0)
				_swap_str(&s[i], &s[i + 1]);
			i++;
		}
		c--;
	}
}

char	*subst_util(char *str, char from, char to)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == from)
			str[i] = to;
		i++;
	}
	return (str);
}
