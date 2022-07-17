/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 04:39:47 by younglee          #+#    #+#             */
/*   Updated: 2022/07/17 10:29:13 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_split_arr(char **split_arr)
{
	int	idx;

	if (split_arr == NULL)
		return ;
	idx = 0;
	while (split_arr[idx] != NULL)
	{
		free(split_arr[idx]);
		idx++;
	}
	free(split_arr);
}

static int	check_execute_posibility(char *path)
{
	struct stat	stat_buf;

	stat(path, &stat_buf);
	if ((stat_buf.st_mode & S_IXUSR) == 0)
		return (FALSE);
	return (TRUE);
}

static char	*find_cmd_from_path(char *cmd, t_list *env_list)
{
	t_env	*path_env;
	char	**path_split;
	int		idx;
	char	*term;
	char	*path;

	path_env = get_env_from_key("PATH", env_list);
	if (path_env == NULL)
		return (NULL);
	path_split = ft_split(path_env->value, ':');
	idx = 0;
	while (path_split[idx] != NULL)
	{
		term = ft_strjoin(path_split[idx], "/");
		path = ft_strjoin(term, cmd);
		free(term);
		if (check_execute_posibility(path) == TRUE)
			return (path);
		free(path);
		idx++;
	}
	free_split_arr(path_split);
	return (NULL);
}

static void	exit_with_cmd_error(char *cmd, t_shell *shell)
{
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	free_resources(shell);
	exit(EXIT_CMD_COMMAND_NOT_FOUND);
}

char	*find_cmd(char *cmd, t_shell *shell)
{
	char	*path;

	if (ft_strchr(cmd, '/') == NULL)
	{
		path = find_cmd_from_path(cmd, shell->env_list);
		if (path == NULL)
			exit_with_cmd_error(cmd, shell);
		return (path);
	}
	else
	{
		if (check_execute_posibility(cmd) == FALSE)
			exit_with_clib_error(cmd, shell);
		return (cmd);
	}
}
