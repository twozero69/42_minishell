/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_right_parenthesis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:47:59 by younglee          #+#    #+#             */
/*   Updated: 2022/06/30 04:03:30 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*return_null_with_error(void)
{
	print_minishell_error(TRUE, "get_right_parenthesis.c", "return NULL");
	return (NULL);
}

t_list	*get_right_parenthesis(t_list *token_list)
{
	t_token	*token;
	int		left_parenthesis_num;

	left_parenthesis_num = 0;
	while (token_list != NULL)
	{
		token = (t_token *)token_list->content;
		if (token->type == TK_LEFT_PARENTHESIS)
			left_parenthesis_num++;
		else if (token->type == TK_RIGHT_PARENTHESIS)
		{
			if (left_parenthesis_num == 0)
				return (return_null_with_error());
			left_parenthesis_num--;
			if (left_parenthesis_num == 0)
				return (token_list);
		}
		token_list = token_list->next;
	}
	return (return_null_with_error());
}
