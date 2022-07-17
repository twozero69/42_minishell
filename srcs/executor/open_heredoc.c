/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:42:59 by younglee          #+#    #+#             */
/*   Updated: 2022/07/17 11:37:20 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_heredoc_error(char *eof_str, int heredoc_line_count)
{
	ft_putstr_fd("minishell: warning: here-document at line ", STDERR_FILENO);
	ft_putnbr_fd(heredoc_line_count, STDERR_FILENO);
	ft_putstr_fd(" delimited by end-of-file (wanted '", STDERR_FILENO);
	ft_putstr_fd(eof_str, STDERR_FILENO);
	ft_putendl_fd("')", STDERR_FILENO);
}

static void	write_heredoc(int entrance_fd, char *eof_str, t_shell *shell)
{
	char	*line;
	size_t	cmp_len;

	cmp_len = ft_strlen(eof_str) + 1;
	while (TRUE)
	{
		line = readline("> ");
		shell->heredoc_line_count++;
		if (line == NULL)
		{
			print_heredoc_error(eof_str, shell->heredoc_line_count);
			break ;
		}
		if (strncmp(line, eof_str, cmp_len) == 0)
			break ;
		ft_putendl_fd(line, entrance_fd);
	}
}

void	open_heredoc(t_ast *node, t_shell *shell)
{
	pid_t	pid;
	int		status;

	if (node == NULL || shell->status != SHELL_EXECUTOR)
		return ;
	if (node->type == NODE_HEREDOC_REDIR)
	{
		if (pipe(node->pipe) == FAIL)
			exit_with_clib_error("executor.c: pipe", shell);
		pid = fork();
		if (pid == FAIL)
			exit_with_clib_error("executor.c: fork", shell);
		if (pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			write_heredoc(node->pipe[1], node->right_child->argv[0], shell);
			free_resources(shell);
			exit(EXIT_SUCCESS);
		}
		waitpid(pid, &status, 0);
		shell->exit_status = get_child_exit_status(status);
	}
	open_heredoc(node->left_child, shell);
	open_heredoc(node->right_child, shell);
}
