/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_control_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:55:52 by younglee          #+#    #+#             */
/*   Updated: 2022/06/29 23:23:22 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_control_node(t_list *l_list, t_list *r_list, t_ast *node)
{
	if (make_child_node(node) == FAIL)
		return (FAIL);
	if (make_ast_node(l_list, node->left_child) == FAIL)
		return (FAIL);
	if (make_ast_node(r_list, node->right_child) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
