/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:57:59 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 20:06:19 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sz_ret;
	int		i32_tmp1;
	int		i32_tmp2;

	i32_tmp1 = 0;
	i32_tmp2 = 0;
	sz_ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sz_ret)
		return (NULL);
	while (s1[i32_tmp1])
		sz_ret[i32_tmp2++] = s1[i32_tmp1++];
	i32_tmp1 = 0;
	while (s2[i32_tmp1])
		sz_ret[i32_tmp2++] = s2[i32_tmp1++];
	sz_ret[i32_tmp2] = 0;
	return (sz_ret);
}
