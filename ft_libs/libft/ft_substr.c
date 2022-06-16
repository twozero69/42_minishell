/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:19:35 by jubae             #+#    #+#             */
/*   Updated: 2022/04/03 07:56:38 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sz_ret;
	size_t	ui32_tmp;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	ui32_tmp = ft_strlen(s + start);
	if (ui32_tmp < len)
		len = ui32_tmp;
	sz_ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!sz_ret)
		return (NULL);
	ft_strlcpy(sz_ret, s + start, len + 1);
	return (sz_ret);
}
