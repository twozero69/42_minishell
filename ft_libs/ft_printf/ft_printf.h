/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:18:58 by jubae             #+#    #+#             */
/*   Updated: 2022/06/04 16:18:58 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_f
{
	int	minus;
	int	zero;
	int	sharp;
	int	space;
	int	plus;
	int	dot;
	int	padding;
	int	precision;
	int	type;
}	t_f;

typedef int	(*t_fp)(t_f *f, va_list ap);

int		ft_printf(const char *s, ...);
int		type_c(t_f *f, va_list ap);
int		type_s(t_f *f, va_list ap);
int		type_diu(t_f *f, va_list ap);
int		type_px(t_f *f, va_list ap);
int		type_percent(t_f *f, va_list ap);
int		d_len(long long d, int len);
void	d_print(long long d);
int		h_len(unsigned long long h, int len);
void	h_print(t_f *f, unsigned long long h);

#endif
