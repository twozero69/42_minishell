/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_diu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:19:31 by jubae             #+#    #+#             */
/*   Updated: 2022/06/04 16:19:31 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_diu_sign(t_f *f, long long d, int ret)
{
	if (f->plus && d >= 0)
		ret += write(1, "+", 1);
	else if (!f->plus && f->space && d >= 0)
		ret += write(1, " ", 1);
	else if (d < 0)
		ret += write(1, "-", 1);
	return (ret);
}

int	print_diu_nbr(t_f *f, long long d, int ret)
{
	ret = d_len(d, 0);
	if (d < 0)
		ret--;
	while (f->precision > ret && ret++)
		write(1, "0", 1);
	if (f->dot && !f->precision && !d)
		return (0);
	d_print(d);
	return (ret);
}

int	print_diu_zero(t_f *f, long long d, int ret)
{
	int	len;

	len = d_len(d, 0);
	if (f->plus || f->space)
		len++;
	if (f->dot && !f->precision && !d)
		len = 0;
	if (!(f->minus || f->dot) && f->zero)
		while (f->padding > len + ret)
			ret += write(1, "0", 1);
	return (ret);
}

int	print_diu_space(t_f *f, long long d, int ret)
{
	int	len;

	len = d_len(d, 0);
	if (f->precision >= len)
	{
		len = f->precision;
		if (d < 0)
			len++;
	}
	if (f->dot && !f->precision && !d)
		len = 0;
	if (f->minus || f->dot || !f->zero)
		while (f->padding > len + ret)
			ret += write(1, " ", 1);
	return (ret);
}

int	type_diu(t_f *f, va_list ap)
{
	int			ret;
	long long	d;
	int			len;

	ret = 0;
	if (f->type == 'u')
		d = va_arg(ap, unsigned int);
	else
		d = va_arg(ap, int);
	len = d_len(d, 0);
	if (f->minus)
	{
		ret += print_diu_sign(f, d, 0);
		ret += print_diu_nbr(f, d, 0);
		ret += print_diu_space(f, d, 0);
	}
	else
	{
		ret += print_diu_space(f, d, 0);
		ret += print_diu_sign(f, d, 0);
		ret += print_diu_zero(f, d, 0);
		ret += print_diu_nbr(f, d, 0);
	}
	return (ret);
}
