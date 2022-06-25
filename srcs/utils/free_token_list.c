/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 02:43:17 by younglee          #+#    #+#             */
/*   Updated: 2022/06/26 04:12:03 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_token_list(t_list **token_list)
{
	t_list	*curr;
	t_list	*next;
	t_token	*token;

	if (*token_list == NULL)
		return ;
	curr = *token_list;
	while (curr != NULL)
	{
		next = curr->next;
		token = (t_token *)curr->content;
		my_free((void **)&token->str);
		my_free((void **)&token);
		my_free((void **)&curr);
		curr = next;
	}
	*token_list = NULL;
}
