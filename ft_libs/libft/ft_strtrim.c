/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:14:03 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 21:17:49 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_isset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		++set;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*sz_ret;
	char	*sz_tmp1;
	char	*sz_tmp2;
	size_t	ui32_len;

	if (!s1 || !set)
		return (NULL);
	sz_tmp1 = (char *)s1;
	sz_tmp2 = sz_tmp1 + ft_strlen(s1);
	while (*sz_tmp1 && my_isset(*sz_tmp1, set))
		sz_tmp1++;
	while (sz_tmp1 < sz_tmp2 && my_isset(*(sz_tmp2 - 1), set))
		sz_tmp2--;
	ui32_len = sz_tmp2 - sz_tmp1 + 1;
	sz_ret = (char *)malloc(sizeof(char) * ui32_len);
	if (!sz_ret)
		return (NULL);
	ft_strlcpy(sz_ret, sz_tmp1, ui32_len);
	return (sz_ret);
}
