/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:33:30 by jubae             #+#    #+#             */
/*   Updated: 2022/07/18 03:40:03 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	realloc_argv(char ***argv, t_list *ret)
{
	int		i;
	t_list	*temp;
	char	**a;

	temp = ret;
	tda_free(*argv);
	i = get_lst_num(ret);
	*argv = (char **)calloc(i + 1, sizeof(char *));
	a = *argv;
	while (ret)
	{
		**argv = ft_strdup(ret->content);
		(void)*(*argv)++;
		ret = ret->next;
	}
	ft_lstclear(&temp, free);
	*argv = a;
}

void	expander_start_lst(t_ast *node, t_list *env_list, int depth)
{
	int		i;
	t_list	*ret;
	t_list	*all;

	i = 0;
	printf("depth: %d | type: %d\n", depth, node->type);
	while (node->argv != NULL && node->argv[i] != NULL)
	{
		printf("before expander : [%s]\n", node->argv[i]);
		ret = ft_lstnew((char *)ft_calloc(1, sizeof(char)));
		set_expander_lst(node->argv[i], env_list, ret);
		if (i == 0)
			all = ret;
		else
			ft_lstadd_back(&all, ret);
		i++;
	}
	i = 0;
	if (node->argv != NULL && node->argv[i] != NULL)
		realloc_argv(&node->argv, all);
	while (node->argv != NULL && node->argv[i] != NULL)
		printf("after  expander : [%s]\n", node->argv[i++]);
	if (node->left_child != NULL)
		expander_start_lst(node->left_child, env_list, depth + 1);
	if (node->right_child != NULL)
		expander_start_lst(node->right_child, env_list, depth + 1);
}

void	expander_start(t_ast *node, t_list *env_list, int depth)
{
	int	i;

	i = 0;
	// printf("depth: %d | type: %d\n", depth, node->type);
	while (node->argv != NULL && node->argv[i] != NULL)
	{
		// printf("before expander : [%s]\n", node->argv[i]);
		node->argv[i] = set_expander(node->argv[i], env_list);
		// printf("after  expander : [%s]\n", node->argv[i]);
		i++;
	}
	if (node->left_child != NULL)
		expander_start(node->left_child, env_list, depth + 1);
	if (node->right_child != NULL)
		expander_start(node->right_child, env_list, depth + 1);
}

void	expander(t_shell *shell)
{
	expander_start_lst(shell->ast, shell->env_list, 0);
	// expander_start(shell->ast, shell->env_list, 0);
	// system("leaks minishell");
	shell->status = SHELL_EXECUTOR;
}
