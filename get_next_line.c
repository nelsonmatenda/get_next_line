/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 08:51:54 by nfigueir          #+#    #+#             */
/*   Updated: 2024/06/13 13:34:43 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd);

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = read_file(fd);
	if (buffer == NULL)
	{
		printf("Error");
		return (NULL);
	}// while(*buffer)
	// {
	// 	if(ft_strchr(buffer, '\n'))
	// 		printf("Encontrou nova linha");
	// 	buffer++;	
	// }
	
	return (buffer);
}

char	*read_file(int fd)
{
	ssize_t	nbr_chr_read;
	char	*buffer;
	
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	nbr_chr_read = read(fd, buffer, BUFFER_SIZE);
	if (nbr_chr_read == -1)
		return (NULL);
	return (buffer);
}
