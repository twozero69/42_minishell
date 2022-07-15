/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wilcard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:59:29 by jubae             #+#    #+#             */
/*   Updated: 2022/07/15 23:31:59 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "minishell.h"

char	*get_wilcard(int init, char *path)
{
	DIR *const		dir = opendir(path);
	struct dirent	*ent;
	char			*ret;
	char			*temp;

	ret = NULL;
	if (!dir)
		return (NULL);
	ent = readdir(dir);
	while (ent)
	{
		if (ent->d_name[0] != '.')
		{
			if (init && init--)
				ret = (char *)ft_calloc(1, sizeof(char));
			else
				ret = my_append_char(ret, ' ');
			temp = ret;
			ret = ft_strjoin(temp, ent->d_name);
			free(temp);
		}
		ent = readdir(dir);
	}
	closedir(dir);
	return (ret);
}

void	find_wilcard(char *argv, char **result, int i)
{
	char	*temp1;
	char	*temp2;

	if (argv[i] == '*' && (argv[i + 1] == 0 || argv[i + 1] == ' '))
	{
		temp1 = getcwd(NULL, 0);
		temp2 = get_wilcard(1, temp1);
		free(temp1);
		if (temp2 == NULL)
			*result = my_append_char(*result, '*');
		else
		{
			temp1 = *result;
			*result = ft_strjoin(temp1, temp2);
			free(temp1);
			free(temp2);
		}
	}
	else
		*result = my_append_char(*result, argv[i]);
}
