/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:46:31 by younglee          #+#    #+#             */
/*   Updated: 2022/06/29 11:03:29 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_new_token_three(t_token *token, t_shell *shell)
{
	t_list	*new_list;

	new_list = ft_lstnew((void *)token);
	if (new_list == NULL)
		return (FAIL);
	ft_lstadd_back(&shell->token_list, new_list);
	return (SUCCESS);
}

static int	add_new_token_two(t_token *tk, char *line, int length, t_shell *sh)
{
	tk->str = (char *)malloc((length + 1) * sizeof(char));
	if (tk->str == NULL)
		return (FAIL);
	ft_strlcpy(tk->str, line, length + 1);
	if (add_new_token_three(tk, sh) == FAIL)
	{
		my_free((void **)&tk->str);
		return (FAIL);
	}
	return (SUCCESS);
}

int	add_new_token(char *line, int length, enum e_token type, t_shell *shell)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		return (FAIL);
	ft_memset(token, 0, sizeof(t_token));
	token->type = type;
	if (add_new_token_two(token, line, length, shell) == FAIL)
	{
		my_free((void **)&token);
		return (FAIL);
	}
	return (SUCCESS);
}
