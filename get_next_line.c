/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 08:51:54 by nfigueir          #+#    #+#             */
/*   Updated: 2024/06/17 10:12:39 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd);

char	*get_next_line(int fd)
{
	static char	*to_print = NULL;
	char	*buffer;
	char	*tmp;
	
	to_print = ft_strdup("");
	buffer = read_file(fd);
	if (buffer == NULL)
		return (NULL);
	int i = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		tmp = to_print;
		printf("%d - %s Antes\n", i, to_print);
		to_print = ft_strjoin(to_print, buffer);
		printf("depois - %d - %s\n", i, to_print);
		free(tmp);
		free(buffer);
		buffer = read_file(fd);
		if (!buffer)
			return (NULL);
		i++;
	}
	//printf("%s", to_print);
	return (to_print);
}

char	*read_file(int fd)
{
	ssize_t	nbr_chr_read;
	char	*buffer;
	
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	nbr_chr_read = read(fd, buffer, BUFFER_SIZE);
	if (nbr_chr_read == -1 || nbr_chr_read == 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[nbr_chr_read] = '\0';
	return (buffer);
}
