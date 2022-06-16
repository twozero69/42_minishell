/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:17:42 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 20:19:26 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i32_idx;
	char	*sz_ret;

	i32_idx = -1;
	sz_ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s || !f || !sz_ret)
		return (NULL);
	while (s[++i32_idx])
		sz_ret[i32_idx] = f(i32_idx, s[i32_idx]);
	sz_ret[i32_idx] = 0;
	return (sz_ret);
}
