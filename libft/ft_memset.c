/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:38:39 by younglee          #+#    #+#             */
/*   Updated: 2022/03/16 11:33:45 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*current_pt;
	unsigned char	*last_pt;

	current_pt = b;
	last_pt = current_pt + len;
	while (current_pt < last_pt)
	{
		*current_pt = c;
		current_pt++;
	}
	return (b);
}
