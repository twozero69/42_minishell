/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:40:49 by younglee          #+#    #+#             */
/*   Updated: 2022/03/18 16:40:49 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			length;
	char			*new_str;
	unsigned int	idx;

	if (s == 0 || f == 0)
		return (0);
	length = ft_strlen(s);
	new_str = (char *)malloc((length + 1) * sizeof(char));
	if (new_str == 0)
		return (0);
	idx = 0;
	while (s[idx] != '\0')
	{
		new_str[idx] = f(idx, s[idx]);
		idx++;
	}
	new_str[idx] = '\0';
	return (new_str);
}
