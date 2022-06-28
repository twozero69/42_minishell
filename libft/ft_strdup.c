/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:40:35 by younglee          #+#    #+#             */
/*   Updated: 2022/03/18 16:40:35 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*s2;

	length = ft_strlen(s1);
	s2 = (char *)malloc((length + 1) * sizeof(char));
	if (s2 == 0)
		return (0);
	ft_memcpy(s2, s1, (length + 1) * sizeof(char));
	return (s2);
}
