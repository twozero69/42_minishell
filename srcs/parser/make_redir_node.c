/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redir_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:55:20 by younglee          #+#    #+#             */
/*   Updated: 2022/07/19 17:12:48 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*get_last_list(t_list *curr_list)
{
	t_token	*next_token;
	t_list	*next_list;

	while (curr_list != NULL)
	{
		next_list = curr_list->next;
		if (next_list == NULL)
			return (curr_list);
		next_token = (t_token *)next_list->content;
		if (next_token->type == TK_PARSER_VISIT)
			return (curr_list);
		curr_list = next_list;
	}
	print_minishell_error(TRUE, "make_redir_node.c", "return NULL");
	return (NULL);
}

static int	set_right_child(t_list *token_list, t_ast *right_child)
{
	t_token	*token;

	right_child->argv = (char **)malloc(2 * sizeof(char *));
	if (right_child->argv == NULL)
		return (FAIL);
	token = (t_token *)token_list->content;
	right_child->argv[0] = token->str;
	right_child->argv[1] = NULL;
	right_child->type = NODE_REDIR_FILE;
	token->str = NULL;
	token->type = TK_PARSER_VISIT;
	return (SUCCESS);
}

int	make_redir_node(t_list *l_list, t_list *r_list, t_ast *node)
{
	int		result;
	t_list	*l_list_last;
	t_list	*term;

	if (make_child_node(node) == FAIL)
		return (FAIL);
	if (set_right_child(r_list, node->right_child) == FAIL)
		return (FAIL);
	if (l_list->next == r_list)
		return (make_ast_node(r_list->next, node->left_child));
	l_list_last = get_last_list(l_list);
	term = l_list_last->next;
	l_list_last->next = r_list->next;
	result = make_ast_node(l_list, node->left_child);
	l_list_last->next = term;
	return (result);
}
