/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:45:26 by nfigueir          #+#    #+#             */
/*   Updated: 2024/06/21 15:09:14 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	ft_read_buf(int fd, t_data *stash)
{
	stash->buf_position = 0;
	stash->buf_size = read(fd, stash->chr, BUFFER_SIZE);
	return (stash->buf_size);
}

void	ft_init_stash(t_data *stash)
{
	stash->buf_position = 0;
	stash->buf_size = 0;
	stash->is_init = 1;
}
