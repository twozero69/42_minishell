/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:13:34 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 21:13:35 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	ui32_idx;

	ui32_idx = ft_strlen(s);
	while (ui32_idx > 0 && s[ui32_idx] != (char)c)
		ui32_idx--;
	if (s[ui32_idx] == (char)c)
		return ((char *)(s + ui32_idx));
	return (0);
}
