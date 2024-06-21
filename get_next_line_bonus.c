/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 08:51:54 by nfigueir          #+#    #+#             */
/*   Updated: 2024/06/21 16:31:12 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_data	stash[MAX_FD];
	char			line[7000000];
	int				i;
	
	if (stash[fd].is_init == 0)
		ft_init_stash(&stash[fd]);
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0 || BUFFER_SIZE > 7000000)
		return (NULL);
	i = 0;
	while (1)
	{
		if (stash[fd].buf_position >= stash[fd].buf_size)
			if (ft_read_buf(fd, &stash[fd]) <= 0)
				break ;
		line[i++] = stash[fd].chr[stash[fd].buf_position++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
