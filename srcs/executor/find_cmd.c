/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 04:39:47 by younglee          #+#    #+#             */
/*   Updated: 2022/07/18 21:00:06 by younglee         ###   ########seoul.kr  */
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

static int	check_execute_posibility(char *path, int *file_exist_flag)
{
	struct stat	stat_buf;

	if (stat(path, &stat_buf) == FAIL)
		return (FALSE);
	*file_exist_flag = TRUE;
	if ((stat_buf.st_mode & S_IXUSR) == 0)
		return (FALSE);
	return (TRUE);
}

static char	*find_cmd_from_path(char *cmd, t_env *path_env, int *file_flag)
{
	char	**path_split;
	int		idx;
	char	*term;
	char	*path;

	path_split = ft_split(path_env->value, ':');
	idx = 0;
	while (path_split[idx] != NULL)
	{
		term = ft_strjoin(path_split[idx], "/");
		path = ft_strjoin(term, cmd);
		free(term);
		if (check_execute_posibility(path, file_flag) == TRUE)
			return (path);
		free(path);
		idx++;
	}
	free_split_arr(path_split);
	return (NULL);
}

char	*find_cmd(char *cmd, t_shell *shell)
{
	char	*path;
	t_env	*path_env;
	int		file_exist_flag;

	file_exist_flag = FALSE;
	path_env = get_env_from_key("PATH", shell->env_list);
	if (path_env != NULL && path_env->value != NULL && \
	*path_env->value != '\0' && ft_strchr(cmd, '/') == NULL)
	{
		path = find_cmd_from_path(cmd, path_env, &file_exist_flag);
		if (path == NULL)
			exit_with_cmd_error(cmd, shell, file_exist_flag);
		return (path);
	}
	else
	{
		if (check_execute_posibility(cmd, &file_exist_flag) == FALSE)
			exit_with_file_error(cmd, shell, file_exist_flag);
		return (cmd);
	}
}
