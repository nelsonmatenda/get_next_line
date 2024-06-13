/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 08:51:54 by nfigueir          #+#    #+#             */
/*   Updated: 2024/06/13 11:03:53 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	nbr_chr_read;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	nbr_chr_read = read(fd, buffer, BUFFER_SIZE);
	if (nbr_chr_read == -1)
	{
		write(1, "Erro em ler o fd\n", sizeof("Erro em ler o fd\n"));
		return (NULL);
	}
	else
		write(1, "Sucesso ler fd\n", sizeof("Sucesso ler fd\n"));
	return (buffer);
}
