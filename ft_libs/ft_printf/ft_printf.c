/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:18:53 by jubae             #+#    #+#             */
/*   Updated: 2022/06/04 16:18:53 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sw_fp(t_f *f, va_list ap, int ret)
{
	t_fp	*fp;
	void	*pte;

	fp = malloc(sizeof(fp) * 121);
	if (!fp)
		return (0);
	fp['c'] = type_c;
	fp['s'] = type_s;
	fp['p'] = type_px;
	fp['d'] = type_diu;
	fp['i'] = type_diu;
	fp['u'] = type_diu;
	fp['x'] = type_px;
	fp['X'] = type_px;
	fp['%'] = type_percent;
	pte = &type_c;
	ft_memcpy(fp, &pte, sizeof(void *));
	ret = fp[f->type](f, ap);
	free(fp);
	return (ret);
}

int	start(const char *s, int *i, t_f *f, va_list ap)
{
	while (ft_strchr("-0# +", s[*i]))
		ft_memset((int *)f + (ft_strchr("-0# +", s[(*i)++]) - "-0# +"), 1, 1);
	while (ft_strchr("0123456789", s[*i]))
		f->padding = f->padding * 10 + (s[(*i)++] - '0');
	if (ft_memset(&f->dot, !ft_strncmp(s + *i, ".", 1), 1) && f->dot && (*i)++)
		while (ft_strchr("0123456789", s[*i]))
			f->precision = f->precision * 10 + (s[(*i)++] - '0');
	if (ft_strchr("cspdiuxX%", s[*i]))
		f->type = s[*i];
	return (sw_fp(f, ap, 0));
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		ret;
	va_list	ap;
	t_f		f;

	va_start(ap, s);
	ft_memcpy(&f,
		"\x0\x1\x2\x3\x4\x5\x6\x7\x8\x9\xa\xb\xc\xd\xe\xf"
		"\x0\x1\x2\x3\x4\x5\x6\x7\x8\x9\xa\xb\xc\xd\xe\xf"
		"\x00\x01\x02\x03", sizeof(f));
	i = -1;
	ret = 0;
	while (s[++i])
		if (!ft_strncmp(s + i, "%", 1) && ft_memset(&f, 0, sizeof(f)) && ++i)
			ret += start(s, &i, &f, ap);
	else
			ret += write(1, &s[i], 1);
	va_end(ap);
	return (ret);
}
