/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:38:10 by younglee          #+#    #+#             */
/*   Updated: 2022/03/21 20:40:38 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	idx;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dst_length + 1 < dstsize)
	{
		idx = 0;
		while (src[idx] != '\0' && idx + dst_length + 1 < dstsize)
		{
			dst[dst_length + idx] = src[idx];
			idx++;
		}
		dst[dst_length + idx] = '\0';
	}
	if (dst_length < dstsize)
		return (dst_length + src_length);
	return (dstsize + src_length);
}
