/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:54:19 by jubae             #+#    #+#             */
/*   Updated: 2022/07/18 03:16:09 by jubae            ###   ########.fr       */
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
