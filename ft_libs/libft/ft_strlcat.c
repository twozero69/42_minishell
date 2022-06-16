/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:06:52 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 20:09:31 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ui32_idx1;
	size_t	ui32_idx2;
	size_t	ui32_len1;
	size_t	ui32_len2;

	ui32_idx1 = ft_strlen(dst);
	ui32_idx2 = 0;
	ui32_len1 = ft_strlen(dst);
	ui32_len2 = ft_strlen(src);
	if (size <= ui32_len1)
		return (ui32_len2 + size);
	while (src[ui32_idx2] && ui32_idx1 < size - 1)
		dst[ui32_idx1++] = src[ui32_idx2++];
	dst[ui32_idx1] = '\0';
	return (ui32_len1 + ui32_len2);
}
