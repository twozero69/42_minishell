/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:20:14 by jubae             #+#    #+#             */
/*   Updated: 2022/06/04 16:20:14 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(t_f *f, char *s, int ret)
{
	int	len;

	len = ft_strlen(s);
	if (f->precision < len && f->dot)
		len = f->precision;
	while (len > ret)
		ret += write(1, (s++), 1);
	return (ret);
}

int	print_s_space(t_f *f, char *s, int ret)
{
	int	len;

	len = ft_strlen(s);
	if (f->precision < len && f->dot)
		len = f->precision;
	while (f->padding - len > ret)
		if (!f->minus && f->zero)
			ret += write(1, "0", 1);
	else
			ret += write(1, " ", 1);
	return (ret);
}

int	type_s(t_f *f, va_list ap)
{
	int		ret;
	char	*s;

	ret = 0;
	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	if (f->minus)
	{
		ret += print_s(f, s, 0);
		ret += print_s_space(f, s, 0);
	}
	else
	{
		ret += print_s_space(f, s, 0);
		ret += print_s(f, s, 0);
	}
	return (ret);
}
