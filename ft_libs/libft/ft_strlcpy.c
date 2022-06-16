/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:13:21 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 20:16:28 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	ui32_len;
	size_t	ui32_idx;

	ui32_idx = 0;
	ui32_len = ft_strlen(src);
	if (size == 0)
		return (ui32_len);
	while (src[ui32_idx] && ui32_idx < size - 1)
	{
		dest[ui32_idx] = src[ui32_idx];
		ui32_idx++;
	}
	dest[ui32_idx] = '\0';
	return (ui32_len);
}
