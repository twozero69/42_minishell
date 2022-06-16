/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:44:09 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 19:52:00 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sz_ret;
	int		i32_len;
	int		i32_cnt;

	i32_cnt = -1;
	i32_len = ft_strlen(s);
	sz_ret = (char *)malloc(sizeof(char) * (i32_len + 1));
	if (!sz_ret)
		return (NULL);
	ft_memset(sz_ret, 0, i32_len + 1);
	while (s[++i32_cnt] != '\0')
		sz_ret[i32_cnt] = s[i32_cnt];
	return (sz_ret);
}
