/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:41:54 by younglee          #+#    #+#             */
/*   Updated: 2022/03/18 21:25:39 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*current_pt;
	unsigned char	*last_pt;
	unsigned char	character;

	if (n == 0)
		return (0);
	current_pt = (unsigned char *)s;
	last_pt = current_pt + n;
	character = (unsigned char)c;
	while (current_pt < last_pt)
	{
		if (*current_pt == character)
			return ((void *)current_pt);
		current_pt++;
	}
	return (0);
}
