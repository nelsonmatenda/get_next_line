/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:32:49 by nfigueir          #+#    #+#             */
/*   Updated: 2024/06/21 14:44:00 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*filepath;
	//char *retorno_gnl;

	filepath = "file.txt";
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Erro: Abrir Arquivo\n", sizeof("Erro: Abrir Arquivo\n"));
		return (-1);
	}
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));


	int fd2 = open("file2.txt", O_RDONLY);
	if (fd2 == -1)
	{
		write(1, "Erro: Abrir Arquivo\n", sizeof("Erro: Abrir Arquivo\n"));
		return (-1);
	}
	printf("%s", get_next_line(fd2));
	return (0);
}
