/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:08:38 by jubae             #+#    #+#             */
/*   Updated: 2022/06/01 18:02:07 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*sz_ret;
	static char	*static_temp[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	static_temp[fd] = read_fd_until_10(fd, static_temp[fd], 1);
	if (!static_temp[fd])
		return (NULL);
	sz_ret = get_str_until_10(static_temp[fd], 0);
	static_temp[fd] = del_str_until_10(static_temp[fd], 0, 0);
	return (sz_ret);
}

char	*read_fd_until_10(int fd, char *sz_input, int size)
{
	char	*sz_temp;

	sz_temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!sz_temp)
		return (NULL);
	while (!str_find(sz_input, '\n') && size != 0)
	{
		size = read(fd, sz_temp, BUFFER_SIZE);
		if (size < 0)
		{
			sz_input = NULL;
			break ;
		}
		sz_temp[size] = '\0';
		sz_input = str_join(sz_input, sz_temp);
	}
	free(sz_temp);
	return (sz_input);
}

char	*get_str_until_10(char *sz_input, int i)
{
	char	*sz_ret;

	if (!sz_input[i])
		return (NULL);
	while (sz_input[i] && sz_input[i] != '\n')
		i++;
	sz_ret = (char *)malloc(sizeof(char) * (i + 2));
	if (!sz_ret)
		return (NULL);
	i = 0;
	while (sz_input[i])
	{
		sz_ret[i] = sz_input[i];
		if (sz_input[i++] == '\n')
			break ;
	}
	sz_ret[i] = '\0';
	return (sz_ret);
}

char	*del_str_until_10(char *sz_input, int i, int j)
{
	char	*sz_ret;

	while (sz_input[i] && sz_input[i] != '\n')
		i++;
	if (!sz_input[i])
	{
		free(sz_input);
		return (NULL);
	}
	sz_ret = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!sz_ret)
		return (NULL);
	while (sz_input[++i])
		sz_ret[j++] = sz_input[i];
	sz_ret[j] = '\0';
	free(sz_input);
	return (sz_ret);
}
