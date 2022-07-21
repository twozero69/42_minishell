/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wilcard_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 01:35:38 by jubae             #+#    #+#             */
/*   Updated: 2022/07/19 05:34:59 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "minishell.h"

static int	_match_continuable(const char **pattern, const char **name,
	const char **pattern_backup, const char **name_backup)
{
	if (**pattern == '/' && ((*pattern)[1] == '\0' || (*pattern)[1] == '/'))
	{
		(*pattern)++;
		return (1);
	}
	if (**pattern == '\001')
	{
		*pattern_backup = (*pattern)++;
		*name_backup = *name + 1;
		return (1);
	}
	else if (**pattern != '\0' && **name == **pattern)
	{
		(*pattern)++;
		(*name)++;
		return (1);
	}
	if (*name_backup && (*name)[0] != '\0')
	{
		*pattern = *pattern_backup;
		*name = *name_backup;
		return (1);
	}
	return (0);
}

static int	_match(const char *pattern, const char *name)
{
	const char	*pattern_backup;
	const char	*name_backup;

	pattern_backup = NULL;
	name_backup = NULL;
	while (*pattern != '\0' || *name != '\0')
	{
		if (!_match_continuable(&pattern, &name, &pattern_backup, &name_backup))
			return (0);
	}
	return (1);
}

void	_set_match(t_list *lst, char *s, char **sort)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (sort && sort[i])
	{
		while (sort && sort[i])
		{
			if (_match(s, sort[i]))
			{
				ft_lstadd_back(&lst, ft_lstnew(ft_strdup(sort[i])));
				cnt++;
			}
			i++;
		}
	}
	if (cnt == 0)
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(subst_util(s, '\001', '*'))));
}

void	_check(t_list *lst, char *s)
{
	char	*temp1;
	int		cnt;
	char	**sort;

	temp1 = getcwd(NULL, 0);
	cnt = get_wilcard_lst_cnt(temp1);
	sort = (char **)ft_calloc(cnt + 1, sizeof(char *));
	get_wilcard_char(sort, temp1);
	free(temp1);
	wilcard_sort_util(sort, cnt, my_strcmp);
	_set_match(lst, s, sort);
	tda_free(sort);
}

t_list	*wilcard_match(t_list *lst)
{
	t_list	*ret;
	t_list	*temp;

	temp = lst;
	ret = ft_lstnew((char *)ft_calloc(1, sizeof(char)));
	while (lst)
	{
		if (ft_strchr(lst->content, '\001'))
		{
			_check(ret, lst->content);
		}
		else
		{
			ft_lstadd_back(&ret, ft_lstnew(ft_strdup(lst->content)));
		}
		lst = lst->next;
	}
	ft_lstclear(&temp, free);
	return (ret);
}
