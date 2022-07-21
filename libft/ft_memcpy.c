/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:50:21 by younglee          #+#    #+#             */
/*   Updated: 2022/03/19 15:50:16 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*uchar_dst;
	unsigned char	*uchar_src;
	size_t			idx;

	if (dst == 0 && src == 0)
		return (0);
	uchar_dst = (unsigned char *)dst;
	uchar_src = (unsigned char *)src;
	idx = 0;
	while (idx < n)
	{
		uchar_dst[idx] = uchar_src[idx];
		idx++;
	}
	return (dst);
}
