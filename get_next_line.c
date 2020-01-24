/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:28:01 by mmartin-          #+#    #+#             */
/*   Updated: 2020/01/24 18:47:39 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_next_buff(int fd, char **tab)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;
	int		read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 0)
		return (-1);
	if (read_bytes == 0)
		return (0);
	buffer[read_bytes] = 0;
	aux = ft_strjoin(tab[fd], buffer);
	if (tab[fd])
		free(tab[fd]);
	tab[fd] = aux;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char		*tab[4096];
	char			*aux;
	int				r_bytes;

	if (fd < 0 || !line || BUFFER_SIZE < 0)
		return (-1);
	r_bytes = 1;
	if (!tab[fd] && (r_bytes = read_next_buff(fd, tab)) != 1)
		return (r_bytes);
	if (!*tab[fd])
	{
		free(tab[fd]);
		return (0);
	}
	while (ft_strchr(tab[fd], '\n') == -1 && r_bytes > 0)
	{
		r_bytes = read_next_buff(fd, tab);
	}
	if (ft_strchr(tab[fd], '\n') != -1)
	{
		read_next_buff(fd, tab);
		*line = ft_substr(tab[fd], 0, ft_strchr(tab[fd], '\n'));
		aux = ft_substr(tab[fd],
				ft_strchr(tab[fd], '\n') + 1, ft_strlen(tab[fd]));
		free(tab[fd]);
		tab[fd] = aux;
		return (1);
	}
	*line = tab[fd];
	tab[fd] = ft_strdup("");
	return (1);
}
