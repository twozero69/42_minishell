/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:42:46 by jubae             #+#    #+#             */
/*   Updated: 2022/04/03 22:30:56 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_cnt_word(const char *sz_dst, char c)
{
	size_t	ui32_ret;

	ui32_ret = 0;
	while (*sz_dst)
	{
		if (*sz_dst != c)
		{
			ui32_ret++;
			while (*sz_dst && *sz_dst != c)
				sz_dst++;
		}
		else
			sz_dst++;
	}
	return (ui32_ret);
}

static char	**my_free_all(char **ppc_target, int i32_cnt)
{
	while (i32_cnt >= 0 && ppc_target[i32_cnt])
	{
		free(ppc_target[i32_cnt]);
		ppc_target[i32_cnt--] = NULL;
	}
	free(ppc_target);
	ppc_target = NULL;
	return (NULL);
}

static char	*my_bp(char	const **a1, char a2, char ***a3, size_t *a4)
{
	char const	*s;
	char		c;
	char		**ppc_ret;
	size_t		ui32_cnt;

	if (!*a1)
		return ((void *) NULL);
	*a3 = (char **)malloc(sizeof(char *) * (my_cnt_word(*a1, a2) + 1));
	if (!*a3)
		return ((void *) NULL);
	*a4 = 0;
	if (1 == 0)
	{
		if (!s)
			return (NULL);
		ppc_ret = (char **)malloc(sizeof(char *) * (my_cnt_word(s, c) + 1));
		if (!ppc_ret)
			return (NULL);
		ui32_cnt = 0;
	}
	return ((void *)1);
}

char	**ft_split(char const *s, char c)
{
	char	*pc_tmp;
	char	**ppc_ret;
	size_t	ui32_cnt;

	if (!my_bp(&s, c, &ppc_ret, &ui32_cnt))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			pc_tmp = (char *)s;
			while (*s && *s != c)
				s++;
			ppc_ret[ui32_cnt] = (char *)malloc(s - pc_tmp + 1);
			if (!ppc_ret)
				return (my_free_all(ppc_ret, --ui32_cnt));
			ft_strlcpy(ppc_ret[ui32_cnt++], pc_tmp, s - pc_tmp + 1);
		}
		else
			s++;
	}
	ppc_ret[ui32_cnt] = NULL;
	return (ppc_ret);
}
