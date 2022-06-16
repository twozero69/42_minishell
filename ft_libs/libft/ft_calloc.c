/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:41:26 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 18:08:27 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t cnt, size_t size)
{
	void	*pv_ret;

	pv_ret = (void *)malloc(cnt * size);
	if (!pv_ret)
		return (NULL);
	ft_bzero(pv_ret, cnt * size);
	return (pv_ret);
}
