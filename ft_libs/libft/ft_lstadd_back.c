/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:22:02 by jubae             #+#    #+#             */
/*   Updated: 2022/04/03 09:43:06 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ps_tmp;

	ps_tmp = *lst;
	if (!ps_tmp)
	{
		*lst = new;
		return ;
	}
	while (ps_tmp->next)
		ps_tmp = ps_tmp->next;
	ps_tmp->next = new;
}
