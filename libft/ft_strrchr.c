/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:22:04 by younglee          #+#    #+#             */
/*   Updated: 2022/03/24 16:57:51 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		character;
	ssize_t		idx;
	ssize_t		length;

	character = (char)c;
	length = ft_strlen(s);
	idx = length - 1;
	while (idx >= 0)
	{
		if (s[idx] == character)
			return ((char *)&s[idx]);
		idx--;
	}
	if (c == '\0')
		return ((char *)(s + length));
	return (0);
}
