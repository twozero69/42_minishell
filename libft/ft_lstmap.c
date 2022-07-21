/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:39:37 by younglee          #+#    #+#             */
/*   Updated: 2022/03/18 16:39:37 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_lst_begin;

	if (lst == 0 || f == 0)
		return (0);
	new_lst = ft_lstnew(f(lst->content));
	if (new_lst == 0)
		return (0);
	new_lst_begin = new_lst;
	lst = lst->next;
	while (lst != 0)
	{
		new_lst->next = ft_lstnew(f(lst->content));
		if (new_lst == 0)
		{
			ft_lstclear(&new_lst_begin, del);
			return (0);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (new_lst_begin);
}
