/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:32:49 by nfigueir          #+#    #+#             */
/*   Updated: 2024/06/12 14:01:30 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line"
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*filepath;

	filepath = "file.txt"
	fd = open(filepath, O_RDONLY);

	get_next_line();
}
