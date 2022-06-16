/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:20:23 by jubae             #+#    #+#             */
/*   Updated: 2022/06/04 17:59:11 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	d_len(long long d, int len)
{
	if (d <= 0 && ++len)
		d *= -1;
	while (d > 0 && ++len)
		d /= 10;
	return (len);
}

void	d_print(long long d)
{
	if (d < 0)
		d = d * -1;
	if (d >= 10)
	{
		d_print(d / 10);
		d_print(d % 10);
	}
	else
		write(1, &"0123456789"[d], 1);
}

int	h_len(unsigned long long h, int len)
{
	while (h >= 16 && ++len)
		h /= 16;
	return (len);
}

void	h_print(t_f *f, unsigned long long h)
{
	if (h >= 16)
		h_print(f, h / 16);
	if (f->type == 'x' || f->type == 'p')
		write(1, &"0123456789abcdef"[h % 16], 1);
	else if (f->type == 'X')
		write(1, &"0123456789ABCDEF"[h % 16], 1);
}
