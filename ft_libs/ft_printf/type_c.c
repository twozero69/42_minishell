/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:19:13 by jubae             #+#    #+#             */
/*   Updated: 2022/06/04 18:44:18 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c_space(t_f *f, int ret)
{
	while (f->padding > ret)
		if (!f->minus && f->zero)
			ret += write(1, "0", 1);
	else
			ret += write(1, " ", 1);
	return (ret);
}

int	type_c(t_f *f, va_list ap)
{
	int		ret;
	char	c;

	ret = 1;
	c = (char)va_arg(ap, int);
	if (f->minus)
	{
		write(1, &c, 1);
		ret = print_c_space(f, ret);
	}
	else
	{
		ret = print_c_space(f, ret);
		write(1, &c, 1);
	}
	return (ret);
}
