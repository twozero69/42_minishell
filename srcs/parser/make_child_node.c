/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_child_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:20:59 by younglee          #+#    #+#             */
/*   Updated: 2022/06/30 01:57:17 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_child_node(t_ast *node)
{
	node->left_child = (t_ast *)malloc(sizeof(t_ast));
	if (node->left_child == NULL)
		return (FAIL);
	ft_memset(node->left_child, 0, sizeof(t_ast));
	node->right_child = (t_ast *)malloc(sizeof(t_ast));
	if (node->right_child == NULL)
		return (FAIL);
	ft_memset(node->right_child, 0, sizeof(t_ast));
	return (SUCCESS);
}
