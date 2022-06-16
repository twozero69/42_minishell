/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:21:38 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 18:14:49 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ps_tmp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		ps_tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ps_tmp;
	}
	*lst = NULL;
}
