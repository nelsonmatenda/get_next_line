/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:32:49 by nfigueir          #+#    #+#             */
/*   Updated: 2024/06/13 13:16:03 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*filepath;
	char *retorno_gnl;

	filepath = "file.txt";
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Erro: Abrir Arquivo\n", sizeof("Erro: Abrir Arquivo\n"));
		return (-1);
	}
	
	while ((retorno_gnl = get_next_line(fd)) != NULL)
	{
		printf("%s\n", retorno_gnl);
		free(retorno_gnl);
	}
}
