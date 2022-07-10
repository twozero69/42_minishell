/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_append_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:05:05 by jubae             #+#    #+#             */
/*   Updated: 2022/07/11 00:20:45 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*my_append_char(char *before, char c)
{
	int		len;
	char	*ret;
	int		i;

	if (ft_memset(&i, 0, sizeof(int)) && before != NULL)
		len = ft_strlen(before);
	if (c == '\n')
		return (before);
	else
	{
		ret = (char *)malloc(sizeof(char) * (len + 2));
		i = -1;
		if (before == NULL)
			ret[0] = c;
		else
		{
			while (before[++i])
				ret[i] = before[i];
			ret[i] = c;
			free(before);
		}
		ret[len + 1] = '\0';
	}
	return (ret);
}
