/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:31:17 by younglee          #+#    #+#             */
/*   Updated: 2022/03/24 17:05:20 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*uchar_s1;
	unsigned char	*uchar_s2;
	size_t			idx;

	uchar_s1 = (unsigned char *)s1;
	uchar_s2 = (unsigned char *)s2;
	idx = 0;
	while (idx < n)
	{
		if (uchar_s1[idx] == '\0')
			return (uchar_s1[idx] - uchar_s2[idx]);
		if (uchar_s1[idx] != uchar_s2[idx])
			return (uchar_s1[idx] - uchar_s2[idx]);
		idx++;
	}
	return (0);
}
