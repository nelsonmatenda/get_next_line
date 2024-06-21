/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 08:51:54 by nfigueir          #+#    #+#             */
/*   Updated: 2024/06/21 16:24:39 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_data	stash;
	char			line[7000000];
	int				i;
	
	if (stash.is_init == 0)
		ft_init_stash(&stash);
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	while (1)
	{
		if (stash.buf_position >= stash.buf_size)
			if (ft_read_buf(fd, &stash) <= 0)
				break ;
		line[i++] = stash.chr[stash.buf_position++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
