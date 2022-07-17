/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wilcard_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:59:29 by jubae             #+#    #+#             */
/*   Updated: 2022/07/18 03:15:03 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "minishell.h"

int	is_wilcard_lst(char *argv, int i)
{
	if (i == 0)
	{
		if ((argv[i] == '*' && (argv[i + 1] == 0 || argv[i + 1] == ' ')))
			return (1);
	}
	else
	{
		if ((argv[i - 1] == ' ' && argv[i] == '*' && \
		(argv[i + 1] == 0 || argv[i + 1] == ' ')))
			return (1);
	}
	return (0);
}

int	get_wilcard_lst(int init, int cnt, char *path, t_list *ret)
{
	DIR *const		dir = opendir(path);
	struct dirent	*ent;
	char			*temp;

	if (!dir)
		return (cnt);
	ent = readdir(dir);
	while (ent)
	{
		if (ent->d_name[0] != '.')
		{
			if (init && init-- && ++cnt)
			{
				temp = (char *)ft_lstlast(ret)->content;
				(ft_lstlast(ret)->content) = ft_strjoin(temp, ent->d_name);
				free(temp);
			}
			else
				ft_lstadd_back(&ret, ft_lstnew(ft_strdup((char *)ent->d_name)));
		}
		ent = readdir(dir);
	}
	closedir(dir);
	return (cnt);
}

void	find_wilcard_lst(char *argv, t_list *ret, int i)
{	
	char	*temp1;
	int		is;

	if (is_wilcard_lst(argv, i))
	{
		temp1 = getcwd(NULL, 0);
		is = get_wilcard_lst(1, 0, temp1, ret);
		free(temp1);
		if (is == 0)
			my_append_char_lst(ret, '*');
	}
	else
		my_append_char_lst(ret, argv[i]);
}
