/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:40:23 by younglee          #+#    #+#             */
/*   Updated: 2022/03/18 16:40:23 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	put_nbr(int n, int fd)
{
	if (n == 0)
		return ;
	put_nbr(n / 10, fd);
	ft_putchar_fd(my_abs(n % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
		ft_putchar_fd('-', fd);
	put_nbr(n, fd);
}
