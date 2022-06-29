/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ast_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:58:12 by younglee          #+#    #+#             */
/*   Updated: 2022/06/30 04:36:44 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*get_last_token(t_list *curr_list)
{
	t_token	*next_token;
	t_list	*next_list;

	while (curr_list != NULL)
	{
		next_list = curr_list->next;
		if (next_list == NULL)
			return ((t_token *)curr_list->content);
		next_token = (t_token *)next_list->content;
		if (next_token->type == TK_PARSER_VISIT)
			return ((t_token *)curr_list->content);
		curr_list = next_list;
	}
	print_minishell_error(TRUE, "parser.c", "return NULL");
	return (NULL);
}

static int	check_wrapped(t_list *token_list)
{
	t_token	*first_token;
	t_token	*last_token;
	t_list	*pair_list;
	t_token	*pair_token;

	first_token = (t_token *)token_list->content;
	if (first_token->type != TK_LEFT_PARENTHESIS)
		return (FALSE);
	last_token = get_last_token(token_list);
	pair_list = get_right_parenthesis(token_list);
	pair_token = (t_token *)pair_list->content;
	if (last_token != pair_token)
		return (FALSE);
	first_token->type = TK_PARSER_VISIT;
	last_token->type = TK_PARSER_VISIT;
	return (TRUE);
}

int	make_ast_node(t_list *token_list, t_ast *node)
{
	t_list		*junction;

	if (check_wrapped(token_list) == TRUE)
		return (make_ast_node(token_list->next, node));
	if (find_control_operator(token_list, &junction, &node->type) == TRUE)
		return (make_control_node(token_list, junction->next, node));
	if (find_redir_operator(token_list, &junction, &node->type) == TRUE)
		return (make_redir_node(token_list, junction->next, node));
	return (make_cmd_node(token_list, node));
}
