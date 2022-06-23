/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:40:32 by younglee          #+#    #+#             */
/*   Updated: 2022/03/18 16:40:32 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	get_split_num(const char *s, char c)
{
	size_t	split_num;

	split_num = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
			split_num++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (split_num);
}

static char	*make_split(const char *s, char c)
{
	size_t	length;
	char	*split;
	char	*split_head;

	length = 0;
	while (s[length] != '\0' && s[length] != c)
		length++;
	split = (char *)malloc((length + 1) * sizeof(char));
	if (split == 0)
		return (0);
	split_head = split;
	while (*s != '\0' && *s != c)
	{
		*split = *s;
		s++;
		split++;
	}
	*split = '\0';
	return (split_head);
}

static void	clear_split_arr(char **head, char **last)
{
	char	**curr;

	curr = head;
	while (curr < last)
	{
		free(*curr);
		curr++;
	}
	free(head);
}

static char	**make_split_arr(char **split_arr, const char *s, char c)
{
	char	**split_arr_head;

	split_arr_head = split_arr;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			*split_arr = make_split(s, c);
			if (*split_arr == 0)
			{
				clear_split_arr(split_arr_head, split_arr);
				return (0);
			}
			split_arr++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	*split_arr = 0;
	return (split_arr_head);
}

char	**ft_split(char const *s, char c)
{
	size_t	split_num;
	char	**split_arr;

	if (s == 0)
		return (0);
	split_num = get_split_num(s, c);
	split_arr = (char **)malloc((split_num + 1) * sizeof(char *));
	if (split_arr == 0)
		return (0);
	split_arr = make_split_arr(split_arr, s, c);
	return (split_arr);
}
