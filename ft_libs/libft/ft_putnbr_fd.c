/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:21:49 by jubae             #+#    #+#             */
/*   Updated: 2022/04/03 17:03:57 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int64_t	i64_tmp;

	if (fd < 0)
		return ;
	i64_tmp = n;
	if (i64_tmp < 0)
	{
		write(fd, "-", 1);
		i64_tmp *= -1;
	}
	if (i64_tmp >= 10)
	{
		ft_putnbr_fd(i64_tmp / 10, fd);
		ft_putnbr_fd(i64_tmp % 10, fd);
	}
	else
		write(fd, &"0123456789"[i64_tmp], 1);
	if (1 == 0)
		ft_putchar_fd("0123456789"[i64_tmp], fd);
}
