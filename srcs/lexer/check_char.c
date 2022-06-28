/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 03:27:06 by younglee          #+#    #+#             */
/*   Updated: 2022/06/26 04:17:21 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_char(char c, char *search_str)
{
	while (*search_str != '\0')
	{
		if (*search_str == c)
			return (TRUE);
		search_str++;
	}
	return (FALSE);
}
