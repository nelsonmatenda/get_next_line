/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:45:26 by nfigueir          #+#    #+#             */
/*   Updated: 2024/06/17 09:26:35 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		chr;

	i = 0;
	chr = (char)c;
	while (s[i])
	{
		if (s[i] == chr)
			return ((char *)(s + i));
		i++;
	}
	if (chr == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	new = malloc((len + 1) * sizeof(char));
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		join[i] = *(s1 + j);
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		join[i] = *(s2 + j);
		i++;
		j++;
	}
	join[i] = 0;
	return (join);
}
