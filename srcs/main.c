/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:25:16 by jubae             #+#    #+#             */
/*   Updated: 2022/06/24 01:50:58 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"

static void	readline_sigint_handler(int signo)
{
	if (signo != SIGINT)
		return ;
	ft_putchar_fd('\n', STDERR_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	wait_exec_sigint_handler(int signo)
{
	if (signo != SIGINT)
		return ;
	ft_putchar_fd('\n', STDERR_FILENO);
}

static int	my_readline(char **line, const char *prompt)
{
	signal(SIGINT, readline_sigint_handler);
	*line = readline(prompt);
	if (*line == NULL)
	{
		ft_putendl_fd("exit", STDERR_FILENO);
		return (FALSE);
	}
	signal(SIGINT, wait_exec_sigint_handler);
	return (TRUE);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	minishell;
	char		*line;

	init(argc, argv, envp, &minishell);
	while (my_readline(&line, "$> "))
	{
		// lexer();
		// parser();
		// expander();
		// executor();
		add_history(line);
		free(line);
	}
	free_resources(&minishell);
	return (EXIT_SUCCESS);
}
