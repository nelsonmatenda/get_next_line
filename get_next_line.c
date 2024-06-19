/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 08:51:54 by nfigueir          #+#    #+#             */
/*   Updated: 2024/06/19 17:57:14 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_has_new_line(char *line);
char	*ft_save_rest(char *line, char **rest);

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*buffer;
	char	*line;
	ssize_t	nbr_chr_read;
	
	if (!stash)
		stash = ft_strdup("");
	line = ft_strdup(stash);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!(ft_has_new_line(line) >= 0))
	{
		nbr_chr_read = read(fd, buffer, BUFFER_SIZE);
		if (nbr_chr_read == -1 || nbr_chr_read == 0)
		{
			free(buffer);
			free(stash);
			free(line);
			return (NULL);
		}
		buffer[nbr_chr_read] = '\0';
		line = ft_strjoin(line,  buffer);
	}
	line = ft_save_rest(line, &stash);
	return (line);
}

int	ft_has_new_line(char *line)
{
	int	i;
	if(!line)
		return (-1);
	i = 0;
	while(line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
char	*ft_save_rest(char *line, char **stash)
{
	int	new_line_position;
	int i;
	char	*final_line;

	i = 0;
	new_line_position = ft_has_new_line(line);
	final_line = malloc((new_line_position + 1) * sizeof(char));
	if (!final_line)
		return (NULL);
	while (line[i] && i <= new_line_position)
	{
		final_line[i] = line[i];
		i++;
	}
	*stash = ft_strjoin(*stash, (line + i));
	return (final_line);
}
