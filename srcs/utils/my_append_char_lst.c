/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_append_char_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:05:05 by jubae             #+#    #+#             */
/*   Updated: 2022/07/18 02:48:18 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_append_char_lst(t_list *lst, char c)
{
	ft_lstlast(lst)->content = my_append_char(ft_lstlast(lst)->content, c);
}
