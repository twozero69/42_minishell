/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:33:06 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 18:15:17 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ps_ret;

	ps_ret = (t_list *)malloc(sizeof(*ps_ret));
	if (!ps_ret)
		return (NULL);
	ps_ret->content = content;
	ps_ret->next = NULL;
	return (ps_ret);
}
