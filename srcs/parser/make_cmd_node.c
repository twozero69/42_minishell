/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:54:38 by younglee          #+#    #+#             */
/*   Updated: 2022/07/18 20:04:16 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_cmd_token_num(t_list *token_list)
{
	t_token	*token;
	int		cmd_token_num;

	cmd_token_num = 0;
	while (token_list != NULL)
	{
		token = (t_token *)token_list->content;
		if (token->type == TK_PARSER_VISIT)
			break ;
		cmd_token_num++;
		token_list = token_list->next;
	}
	return (cmd_token_num);
}

int	make_cmd_node(t_list *token_list, t_ast *node)
{
	int		cmd_token_num;
	int		idx;
	t_token	*token;

	cmd_token_num = get_cmd_token_num(token_list);
	if (cmd_token_num == 0)
		return (SUCCESS);
	node->argv = (char **)malloc((cmd_token_num + 1) * sizeof(char *));
	if (node->argv == NULL)
		return (FAIL);
	node->type = NODE_CMD;
	idx = 0;
	while (idx < cmd_token_num)
	{
		token = (t_token *)token_list->content;
		node->argv[idx] = token->str;
		token->str = NULL;
		token->type = TK_PARSER_VISIT;
		token_list = token_list->next;
		idx++;
	}
	node->argv[idx] = NULL;
	return (SUCCESS);
}
