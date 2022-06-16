/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:48:24 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 18:16:18 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	ui32_cnt;

	ui32_cnt = 0;
	while (ui32_cnt < n)
	{
		if (((unsigned char *)s)[ui32_cnt] == (unsigned char)c)
			return ((void *)s + ui32_cnt);
		ui32_cnt++;
	}
	return ((void *)0);
}
