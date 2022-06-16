/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:42:01 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 18:15:07 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ps_ret;
	t_list	*ps_tmp;

	if (!f || !*f || !del)
		return (NULL);
	ps_ret = NULL;
	while (lst)
	{
		ps_tmp = ft_lstnew(f(lst->content));
		if (!ps_tmp)
		{
			ft_lstclear(&ps_ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ps_ret, ps_tmp);
		lst = lst->next;
	}
	return (ps_ret);
}
