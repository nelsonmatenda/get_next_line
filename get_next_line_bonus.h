/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:49:57 by nfigueir          #+#    #+#             */
/*   Updated: 2024/06/21 16:40:42 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

typedef struct s_data
{
	int		buf_size;
	int		buf_position;
	char	chr[BUFFER_SIZE];
	int		is_init;
}		t_data;

char	*get_next_line(int fd);
void	ft_init_stash(t_data *stash);
int		ft_read_buf(int fd, t_data *stash);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
#endif
