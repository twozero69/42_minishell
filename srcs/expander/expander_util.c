/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:54:19 by jubae             #+#    #+#             */
/*   Updated: 2022/07/18 05:19:29 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tda_free(char **tda)
{
	char	**temp;

	temp = tda;
	while (*temp)
		free(*temp++);
	free(tda);
}

int	get_lst_num(t_list *ret)
{
	int	len;

	len = 0;
	while (ret && ++len)
		ret = ret->next;
	return (len);
}

void	_swap_str(char **a, char **b)
{
	char	*x;

	if (a == b)
		return ;
	x = *a;
	*a = *b;
	*b = x;
}

int	my_strcmp(const char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
