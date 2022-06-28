/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:49:09 by younglee          #+#    #+#             */
/*   Updated: 2022/06/28 02:00:18 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	return_false_with_parenthesis_error(void)
{
	print_minishell_error(TRUE, "syntax error", "unclosed parenthesis");
	return (FALSE);
}

static int	check_parenthesis(t_list *curr)
{
	t_token	*token;
	int		left_parenthesis_num;

	left_parenthesis_num = 0;
	while (curr != NULL)
	{
		token = (t_token *)curr->content;
		if (token->type == TK_LEFT_PARENTHESIS)
			left_parenthesis_num++;
		else if (token->type == TK_RIGHT_PARENTHESIS)
		{
			if (left_parenthesis_num == 0)
				return (return_false_with_parenthesis_error());
			left_parenthesis_num--;
		}
		curr = curr->next;
	}
	if (left_parenthesis_num != 0)
		return (return_false_with_parenthesis_error());
	return (TRUE);
}

static int	check_first_token(t_list *token_list)
{
	t_token			*token;
	enum e_token	type;

	token = (t_token *)token_list->content;
	type = token->type;
	if (type == TK_WORD)
		return (TRUE);
	if (type == TK_INPUT_REDIR)
		return (TRUE);
	if (type == TK_HEREDOC_REDIR)
		return (TRUE);
	if (type == TK_OUTPUT_REDIR)
		return (TRUE);
	if (type == TK_APPEND_REDIR)
		return (TRUE);
	if (type == TK_LEFT_PARENTHESIS)
		return (TRUE);
	print_syntax_error(token->str);
	return (FALSE);
}

static int	check_last_token(t_list *token_list)
{
	t_list			*last_list;
	t_token			*token;
	enum e_token	type;

	last_list = ft_lstlast(token_list);
	token = (t_token *)last_list->content;
	type = token->type;
	if (type == TK_WORD)
		return (TRUE);
	if (type == TK_RIGHT_PARENTHESIS)
		return (TRUE);
	print_syntax_error("newline");
	return (FALSE);
}

int	check_syntax(t_list *token_list)
{
	if (check_parenthesis(token_list) == FALSE)
		return (FALSE);
	if (check_first_token(token_list) == FALSE)
		return (FALSE);
	if (check_front_and_back_tokens(token_list) == FALSE)
		return (FALSE);
	if (check_last_token(token_list) == FALSE)
		return (FALSE);
	return (TRUE);
}
