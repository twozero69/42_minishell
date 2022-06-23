/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:43:59 by younglee          #+#    #+#             */
/*   Updated: 2022/03/18 16:43:59 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	check_set(int c, char const *set)
{
	size_t	idx;

	idx = 0;
	while (set[idx] != '\0')
	{
		if (c == set[idx])
			return (1);
		idx++;
	}
	return (0);
}

static size_t	get_new_len(char const *s1, char const *set)
{
	size_t		idx;
	size_t		trim_len;
	size_t		s1_len;

	idx = 0;
	trim_len = 0;
	s1_len = ft_strlen(s1);
	while (idx < s1_len && check_set(s1[idx], set))
	{
		trim_len++;
		idx++;
	}
	if (s1_len == trim_len)
		return (0);
	idx = s1_len - 1;
	while (check_set(s1[idx], set))
	{
		trim_len++;
		idx--;
	}
	return (s1_len - trim_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*new_str;
	size_t		new_len;
	size_t		idx;

	if (s1 == 0 || set == 0)
		return (0);
	new_len = get_new_len(s1, set);
	new_str = (char *)malloc((new_len + 1) * sizeof(char));
	if (new_str == 0)
		return (0);
	idx = 0;
	while (s1[idx] != '\0' && check_set(s1[idx], set))
		idx++;
	ft_memcpy(new_str, &s1[idx], new_len);
	new_str[new_len] = '\0';
	return (new_str);
}
