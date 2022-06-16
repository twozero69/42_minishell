/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pxX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:19:49 by jubae             #+#    #+#             */
/*   Updated: 2022/06/04 18:45:31 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_px_sharp(t_f *f, unsigned long long h, int ret)
{
	if ((h && f->sharp) || f->type == 'p')
	{
		if (f->type == 'X')
			ret = write(1, "0X", 2);
		else
			ret = write(1, "0x", 2);
	}
	return (ret);
}

int	print_px_zero(t_f *f, unsigned long long h, int ret)
{
	int	len;

	len = h_len(h, 1);
	if (f->precision > len)
		len = f->precision;
	if (f->sharp || f->type == 'p')
		len += 2;
	if (f->dot && !f->precision && !h)
		len = 0;
	if (!(f->minus || f->dot) && f->zero)
		while (f->padding > len + ret)
			ret += write(1, "0", 1);
	return (ret);
}

int	print_px_space(t_f *f, unsigned long long h, int ret)
{
	int	len;

	len = h_len(h, 1);
	if (f->precision > len)
		len = f->precision;
	if (f->sharp || f->type == 'p')
		len += 2;
	if (f->dot && !f->precision && !h)
		len = 0;
	if (f->minus || f->dot || !f->zero)
		while (f->padding > len + ret)
			ret += write(1, " ", 1);
	return (ret);
}

int	print_px_h(t_f *f, unsigned long long h)
{
	int	xnbr_len;

	xnbr_len = h_len(h, 1);
	while (f->precision > xnbr_len)
		xnbr_len += write(1, "0", 1);
	if (f->dot && !f->precision && !h)
		return (0);
	h_print(f, h);
	return (xnbr_len);
}

int	type_px(t_f *f, va_list ap)
{
	int					ret;
	unsigned long long	h;

	ret = 0;
	if (f->type == 'p')
		h = va_arg(ap, unsigned long long);
	else
		h = va_arg(ap, unsigned int);
	if (f->minus)
	{
		ret += print_px_sharp(f, h, 0);
		ret += print_px_h(f, h);
		ret += print_px_space(f, h, 0);
	}
	else
	{
		ret += print_px_space(f, h, 0);
		ret += print_px_sharp(f, h, 0);
		ret += print_px_zero(f, h, 0);
		ret += print_px_h(f, h);
	}
	return (ret);
}
