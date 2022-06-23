/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:00:53 by younglee          #+#    #+#             */
/*   Updated: 2022/05/03 21:03:36 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"

static int	find_needle(const char *haystack, const char *needle)
{
	size_t	idx;

	idx = 0;
	while (needle[idx] != '\0')
	{
		if (haystack[idx] != needle[idx])
			return (0);
		idx++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*last_pt;
	size_t		haystack_len;
	size_t		needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (len > haystack_len)
		last_pt = haystack + haystack_len - needle_len + 1;
	else
		last_pt = haystack + len - needle_len + 1;
	while (haystack < last_pt)
	{
		if (find_needle(haystack, needle))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
