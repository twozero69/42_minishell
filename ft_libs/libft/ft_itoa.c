/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:01:35 by jubae             #+#    #+#             */
/*   Updated: 2022/04/02 18:09:34 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	my_len(int n, int len)
{
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i32_len;
	int8_t	i8_sign;
	char	*pc_ret;

	i32_len = my_len(n, 0);
	pc_ret = (char *)malloc(sizeof(char) * (i32_len + 1));
	if (!pc_ret)
		return (NULL);
	pc_ret[i32_len] = '\0';
	i8_sign = 0;
	if (n < 0)
		i8_sign++;
	while (--i32_len >= i8_sign)
	{
		pc_ret[i32_len] = '0' + my_abs(n % 10);
		n = my_abs(n / 10);
	}
	if (i8_sign)
		pc_ret[0] = '-';
	return (pc_ret);
}
