/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_append_str_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:05:05 by jubae             #+#    #+#             */
/*   Updated: 2022/07/18 21:26:43 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_append_str_lst(t_list *lst, char *str)
{
	char	*temp;

	temp = (char *)ft_lstlast(lst)->content;
	(ft_lstlast(lst)->content) = ft_strjoin(temp, str);
	free(temp);
	free(str);
}
