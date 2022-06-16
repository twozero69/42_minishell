/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:19:40 by jubae             #+#    #+#             */
/*   Updated: 2022/06/04 21:56:49 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent_space(t_f *f, int ret)
{
	while (f->padding > ret)
		if (!f->minus && f->zero)
			ret += write(1, "0", 1);
	else
			ret += write(1, " ", 1);
	return (ret);
}

int	type_percent(t_f *f, va_list ap)
{
	int	ret;

	if (ap)
		ret = 1;
	ret = 1;
	if (f->minus)
	{
		write(1, "%", 1);
		ret = print_percent_space(f, ret);
	}
	else
	{
		ret = print_percent_space(f, ret);
		write (1, "%", 1);
	}
	return (ret);
}
