/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_front_and_back_tokens.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:11:05 by younglee          #+#    #+#             */
/*   Updated: 2022/06/28 01:57:06 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_word(enum e_token type)
{
	if (type == TK_WORD)
		return (TRUE);
	if (type == TK_PIPE)
		return (TRUE);
	if (type == TK_AND)
		return (TRUE);
	if (type == TK_OR)
		return (TRUE);
	if (type == TK_INPUT_REDIR)
		return (TRUE);
	if (type == TK_HEREDOC_REDIR)
		return (TRUE);
	if (type == TK_OUTPUT_REDIR)
		return (TRUE);
	if (type == TK_APPEND_REDIR)
		return (TRUE);
	if (type == TK_RIGHT_PARENTHESIS)
		return (TRUE);
	return (FALSE);
}

static int	check_lp(enum e_token type)
{
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
	return (FALSE);
}

static int	check_rp(enum e_token type)
{
	if (type == TK_PIPE)
		return (TRUE);
	if (type == TK_AND)
		return (TRUE);
	if (type == TK_OR)
		return (TRUE);
	if (type == TK_INPUT_REDIR)
		return (TRUE);
	if (type == TK_HEREDOC_REDIR)
		return (TRUE);
	if (type == TK_OUTPUT_REDIR)
		return (TRUE);
	if (type == TK_APPEND_REDIR)
		return (TRUE);
	if (type == TK_RIGHT_PARENTHESIS)
		return (TRUE);
	return (FALSE);
}

static int	check_front_and_back_token(t_token *front_tk, t_token *back_tk)
{
	enum e_token	front_type;

	front_type = front_tk->type;
	if (front_type == TK_WORD && check_word(back_tk->type) == TRUE)
		return (TRUE);
	if (front_type == TK_PIPE && check_operator(back_tk->type) == TRUE)
		return (TRUE);
	if (front_type == TK_AND && check_operator(back_tk->type) == TRUE)
		return (TRUE);
	if (front_type == TK_OR && check_operator(back_tk->type) == TRUE)
		return (TRUE);
	if (front_type == TK_INPUT_REDIR && check_redir(back_tk->type) == TRUE)
		return (TRUE);
	if (front_type == TK_HEREDOC_REDIR && check_redir(back_tk->type) == TRUE)
		return (TRUE);
	if (front_type == TK_OUTPUT_REDIR && check_redir(back_tk->type) == TRUE)
		return (TRUE);
	if (front_type == TK_APPEND_REDIR && check_redir(back_tk->type) == TRUE)
		return (TRUE);
	if (front_type == TK_LEFT_PARENTHESIS && check_lp(back_tk->type) == TRUE)
		return (TRUE);
	if (front_type == TK_RIGHT_PARENTHESIS && check_rp(back_tk->type) == TRUE)
		return (TRUE);
	print_syntax_error(back_tk->str);
	return (FALSE);
}

int	check_front_and_back_tokens(t_list *curr)
{
	t_token	*front_token;
	t_token	*back_token;
	t_list	*next;

	next = curr->next;
	while (next != NULL)
	{
		front_token = (t_token *)curr->content;
		back_token = (t_token *)next->content;
		if (check_front_and_back_token(front_token, back_token) == FALSE)
			return (FALSE);
		curr = next;
		next = next->next;
	}
	return (TRUE);
}
