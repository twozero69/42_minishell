/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:55:38 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 18:18:19 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	cnt;

	if (dst == src || n == 0)
		return (dst);
	if (dst > src)
	{
		cnt = n + 1;
		while (--cnt)
			((unsigned char *)dst)[cnt - 1] = ((unsigned char *)src)[cnt - 1];
	}
	else
	{
		cnt = -1;
		while (++cnt < n)
			((unsigned char *)dst)[cnt] = ((unsigned char *)src)[cnt];
	}
	return (dst);
}
