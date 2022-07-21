/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:44:35 by younglee          #+#    #+#             */
/*   Updated: 2022/03/16 11:32:53 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*current_pt;
	unsigned char		*last_pt;

	current_pt = s;
	last_pt = current_pt + n;
	while (current_pt < last_pt)
	{
		*current_pt = 0;
		current_pt++;
	}
}
