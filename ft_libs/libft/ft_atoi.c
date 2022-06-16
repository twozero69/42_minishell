/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:44:57 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 18:16:32 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_isdummy(unsigned char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	ui32_cnt;
	int8_t	i8_sign;
	int64_t	i64_ret;

	ui32_cnt = 0;
	i8_sign = 1;
	i64_ret = 0;
	while (my_isdummy(str[ui32_cnt]))
		ui32_cnt++;
	if (str[ui32_cnt] == '-' || str[ui32_cnt] == '+')
	{
		if (str[ui32_cnt++] == '-')
			i8_sign *= -1;
	}
	while (str[ui32_cnt] >= '0' && str[ui32_cnt] <= '9')
		i64_ret = i64_ret * 10 + (str[ui32_cnt++] - '0') * i8_sign;
	if (i64_ret > INT32_MAX)
		return (-1);
	if (i64_ret < INT32_MIN)
		return (0);
	return (i64_ret);
}
