/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:08:44 by jubae             #+#    #+#             */
/*   Updated: 2022/06/09 01:40:02 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*read_fd_until_10(int fd, char *str, int size);
char	*get_str_until_10(char *str, int i);
char	*del_str_until_10(char *str, int i, int j);
int		str_len(char *s, int ret);
int		str_find(char *s, int c);
char	*str_join(char *s1, char *s2);

#endif
