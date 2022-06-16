/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:54:42 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 18:33:39 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	ui32_cnt;

	if (!dst && !src)
		return (NULL);
	ui32_cnt = 0;
	while (ui32_cnt < n)
	{
		((unsigned char *)dst)[ui32_cnt] = ((unsigned char *)src)[ui32_cnt];
		ui32_cnt++;
	}
	return (dst);
}
