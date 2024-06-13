/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:32:49 by nfigueir          #+#    #+#             */
/*   Updated: 2024/06/13 11:05:43 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*filepath;

	filepath = "file.txt";
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Erro: Abrir Arquivo\n", sizeof("Erro: Abrir Arquivo\n"));
		return (-1);
	}
	char *retorno_gnl = get_next_line(fd);
	printf("%s\n", retorno_gnl);
}
