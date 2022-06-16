/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:55:56 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 19:56:27 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i32_cnt;

	i32_cnt = 0;
	if (!s || !f)
		return ;
	while (s[i32_cnt])
	{
		f(i32_cnt, s + i32_cnt);
		i32_cnt++;
	}
}
