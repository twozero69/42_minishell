/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:08:27 by jubae             #+#    #+#             */
/*   Updated: 2022/06/01 17:57:23 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_find(char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return (1);
		s++;
	}
	return (0);
}

int	str_len(char *s, int ret)
{
	if (!s)
		return (ret);
	while (s[ret])
		ret++;
	return (ret);
}

char	*str_join(char *sz_input1, char *sz_input2)
{
	int		i;
	int		len1;
	int		len2;
	char	*sz_ret;

	len1 = str_len(sz_input1, 0);
	len2 = str_len(sz_input2, 0);
	sz_ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!sz_ret)
		return (NULL);
	i = -1;
	while (++i < len1)
		sz_ret[i] = sz_input1[i];
	i = -1;
	while (++i < len2)
		sz_ret[len1 + i] = sz_input2[i];
	sz_ret[len1 + len2] = '\0';
	if (sz_input1)
		free(sz_input1);
	return (sz_ret);
}
