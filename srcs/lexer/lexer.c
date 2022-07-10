/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:37:09 by younglee          #+#    #+#             */
/*   Updated: 2022/07/03 16:14:18 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_operator_length(char *token_str)
{
	if (!check_char(*token_str, DOUBLE_CHARACTERS))
		return (1);
	if (*token_str == *(token_str + 1))
		return (2);
	return (1);
}

static enum e_token	get_operator_type(char c, int length)
{
	if (c == '|' && length == 1)
		return (TK_PIPE);
	if (c == '&' && length == 2)
		return (TK_AND);
	if (c == '|' && length == 2)
		return (TK_OR);
	if (c == '<' && length == 1)
		return (TK_INPUT_REDIR);
	if (c == '<' && length == 2)
		return (TK_HEREDOC_REDIR);
	if (c == '>' && length == 1)
		return (TK_OUTPUT_REDIR);
	if (c == '>' && length == 2)
		return (TK_APPEND_REDIR);
	if (c == '(' && length == 1)
		return (TK_LEFT_PARENTHESIS);
	if (c == ')' && length == 1)
		return (TK_RIGHT_PARENTHESIS);
	print_minishell_error(TRUE, "syntex error", "invalid token");
	return (TK_INVALID);
}

static int	get_word_length(char *token_str)
{
	char	*token_str_start;
	char	*closing_quote;
	int		quote_check_result;

	token_str_start = token_str;
	while (*token_str != '\0' && !check_char(*token_str, META_CHARACTERS))
	{
		quote_check_result = check_char(*token_str, QUOTE_CHARACTERS);
		if (*token_str != '\0' && quote_check_result)
		{
			closing_quote = ft_strchr(token_str + 1, *token_str);
			if (closing_quote == NULL)
			{
				print_minishell_error(TRUE, "syntex error", "unclosed quote");
				return (FAIL);
			}
			token_str = closing_quote + 1;
		}
		else if (*token_str != '\0' && !quote_check_result)
			token_str++;
	}
	return (token_str - token_str_start);
}

int	get_token_info(char *line, int *length, enum e_token *type)
{
	if (check_char(*line, OPERATOR_CHARACTERS))
	{
		*length = get_operator_length(line);
		*type = get_operator_type(*line, *length);
		if (*type == TK_INVALID)
			return (FAIL);
	}
	else
	{
		*length = get_word_length(line);
		if (*length == FAIL)
			return (FAIL);
		*type = TK_WORD;
	}
	return (SUCCESS);
}

void	lexer(char *line, t_shell *shell)
{
	int				token_length;
	enum e_token	token_type;

	while (*line != '\0')
	{
		while (*line != '\0' && check_char(*line, SPACE_CHARACTERS))
			line++;
		if (*line != '\0')
		{
			if (get_token_info(line, &token_length, &token_type) == FAIL)
			{
				shell->exit_status = EXIT_SYNTEX_ERROR;
				return ;
			}
			if (add_new_token(line, token_length, token_type, shell) == FAIL)
				exit_with_clib_error("lexer.c: malloc", shell);
			line += token_length;
		}
	}
	my_free((void **)&shell->line);
	shell->status = SHELL_PARSER;
}
