/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:44:03 by younglee          #+#    #+#             */
/*   Updated: 2022/03/18 16:44:03 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	idx;
	size_t	copy_length;

	if (s == 0)
		return (0);
	copy_length = ft_strlen(s + start);
	if (copy_length > len)
		copy_length = len;
	substr = (char *)malloc((copy_length + 1) * sizeof(char));
	if (substr == 0)
		return (0);
	if (start >= ft_strlen(s))
	{
		*substr = '\0';
		return (substr);
	}
	idx = 0;
	while (idx < len && s[start + idx] != '\0')
	{
		substr[idx] = s[start + idx];
		idx++;
	}
	substr[idx] = '\0';
	return (substr);
}
