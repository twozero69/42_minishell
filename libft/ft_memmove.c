/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:52:33 by younglee          #+#    #+#             */
/*   Updated: 2022/03/18 21:12:58 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*char_dst;
	char	*char_src;
	size_t	idx;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	char_dst = (char *)dst;
	char_src = (char *)src;
	idx = len;
	while (idx != 0)
	{
		idx--;
		char_dst[idx] = char_src[idx];
	}
	return (dst);
}
