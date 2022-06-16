/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:10:14 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 21:12:40 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;

	if (!*find)
		return ((char *)str);
	if (!ft_strlen(str) || len < ft_strlen(find))
		return (NULL);
	i = 0;
	while (i + ft_strlen(find) <= len && str[i])
	{
		if (str[i] == find[0] && !ft_memcmp(&str[i], &find[0], ft_strlen(find)))
			return ((char *)str + i);
		++i;
	}
	return (NULL);
}
