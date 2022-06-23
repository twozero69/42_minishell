/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:30:32 by younglee          #+#    #+#             */
/*   Updated: 2022/03/21 20:06:01 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_space(int c)
{
	char	*space_str;

	space_str = "\t\n\v\f\r ";
	while (*space_str != '\0')
	{
		if (*space_str == c)
			return (1);
		space_str++;
	}
	return (0);
}

static int	check_sign(int c, int *sign_flag_pt)
{
	if (c == '+')
		return (1);
	if (c == '-')
	{
		*sign_flag_pt *= -1;
		return (1);
	}
	return (0);
}

static int	check_num(int c, int *number_pt)
{
	if ('0' <= c && c <= '9')
	{
		*number_pt = *number_pt * 10 + c - '0';
		return (1);
	}
	return (0);
}

static int	check_range(const char *str, int sign_flag)
{
	int	length;

	while (*str != '\0' && *str == '0')
		str++;
	length = 0;
	while (str[length] != '\0' && '0' <= str[length] && str[length] <= '9')
		length++;
	if (length < 19)
		return (1);
	if (length == 19)
	{
		if (sign_flag == 1 && ft_strncmp(str, "9223372036854775807", 19) < 0)
			return (1);
		if (sign_flag == -1 && ft_strncmp(str, "9223372036854775808", 19) < 0)
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign_flag;
	int		number;

	sign_flag = 1;
	number = 0;
	while (*str != '\0' && check_space(*str))
		str++;
	if (*str != '\0' && check_sign(*str, &sign_flag))
		str++;
	if (*str != '\0' && !check_range(str, sign_flag))
	{
		if (sign_flag == 1)
			return (-1);
		if (sign_flag == -1)
			return (0);
	}
	while (*str != '\0' && check_num(*str, &number))
		str++;
	return (sign_flag * number);
}
