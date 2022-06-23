/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:38:50 by younglee          #+#    #+#             */
/*   Updated: 2022/03/18 16:38:50 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	get_new_len(int n)
{
	size_t	new_len;

	if (n == 0)
		return (1);
	new_len = 0;
	if (n < 0)
		new_len++;
	while (n != 0)
	{
		new_len++;
		n /= 10;
	}
	return (new_len);
}

static int	my_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	size_t	new_len;
	char	*new_str;
	size_t	idx;

	new_len = get_new_len(n);
	new_str = malloc((new_len + 1) * sizeof(char));
	if (new_str == 0)
		return (0);
	new_str[new_len] = '\0';
	if (n == 0)
	{
		new_str[0] = '0';
		return (new_str);
	}
	if (n < 0)
		new_str[0] = '-';
	idx = new_len - 1;
	while (n != 0)
	{
		new_str[idx] = my_abs(n % 10) + '0';
		idx--;
		n /= 10;
	}
	return (new_str);
}
