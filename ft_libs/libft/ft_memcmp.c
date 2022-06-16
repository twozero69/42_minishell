/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:53:01 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 18:17:31 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *dst, const void *src, size_t n)
{
	size_t			ui32_cnt;
	unsigned char	*puc_tmp1;
	unsigned char	*puc_tmp2;

	ui32_cnt = 0;
	puc_tmp1 = (unsigned char *)dst;
	puc_tmp2 = (unsigned char *)src;
	while (ui32_cnt < n)
	{
		if (puc_tmp1[ui32_cnt] != puc_tmp2[ui32_cnt])
			return (puc_tmp1[ui32_cnt] - puc_tmp2[ui32_cnt]);
		ui32_cnt++;
	}
	return (0);
}
