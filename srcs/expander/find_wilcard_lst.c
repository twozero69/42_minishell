/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wilcard_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:59:29 by jubae             #+#    #+#             */
/*   Updated: 2022/07/19 05:20:57 by jubae            ###   ########.fr       */
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

void	get_wilcard_char(char **sort, char *path)
{
	DIR *const		dir = opendir(path);
	struct dirent	*ent;

	ent = readdir(dir);
	while (ent)
	{
		if (ent->d_name[0] != '.')
		{
			*sort++ = ft_strdup((char *)ent->d_name);
		}
		ent = readdir(dir);
	}
	closedir(dir);
}

int	get_wilcard_lst_cnt(char *path)
{
	DIR *const		dir = opendir(path);
	struct dirent	*ent;
	int				cnt;

	cnt = 0;
	if (!dir)
		return (cnt);
	ent = readdir(dir);
	while (ent)
	{
		if (ent->d_name[0] != '.')
			cnt++;
		ent = readdir(dir);
	}
	closedir(dir);
	return (cnt);
}

void	wilcard_sort(char **s, int c, int (*m)(const char *, char *), t_list *t)
{
	int		i;
	char	*temp;

	while (c > 1)
	{
		i = 0;
		while (i < c - 1)
		{
			if (m(s[i], s[i + 1]) > 0)
				_swap_str(&s[i], &s[i + 1]);
			i++;
		}
		c--;
	}
	while (s[c - 1])
	{
		if (c == 1)
		{
			temp = (char *)ft_lstlast(t)->content;
			(ft_lstlast(t)->content) = ft_strjoin(temp, s[c++ - 1]);
			free(temp);
		}
		else
			ft_lstadd_back(&t, ft_lstnew(ft_strdup(s[c++ - 1])));
	}
}

void	find_wilcard_lst(char *argv, t_list *ret, int i)
{
	if (argv[i] == '*')
		my_append_char_lst(ret, '\001');
	else
		my_append_char_lst(ret, argv[i]);
}
