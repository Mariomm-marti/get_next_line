/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:28:01 by mmartin-          #+#    #+#             */
/*   Updated: 2020/01/22 20:00:07 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_next_buff(int fd)
{
	char	*strread;
	int		read_bytes;

	if (!(strread = (char *)malloc(BUFFER_SIZE + 1)))
		return (NULL);
	read_bytes = read(fd, strread, BUFFER_SIZE);
	if (read_bytes < 0)
	{
		free(strread);
		return (NULL);
	}
	strread[read_bytes] = 0;
	return (strread);
}

static int	update_status(int fd, char *current, char **tab, char **line)
{
	char *aux;

	if (ft_strchr(tab[fd], '\n') != -1)
	{
		*line = ft_substr(tab[fd], 0, ft_strchr(tab[fd], '\n'));
		aux = ft_substr(tab[fd],
				ft_strchr(tab[fd], '\n') + 1, ft_strlen(tab[fd]));
		free(tab[fd]);
		free(current);
		tab[fd] = aux;
		return (1);
	}
	if (ft_strlen(current) == 0)
	{
		*line = ft_strdup(tab[fd]);
		free(tab[fd]);
		free(current);
		return (0);
	}
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	static char	*tab[4096];
	char		*aux;
	char		*current;

	if (fd < 0 || (!tab[fd] && !(tab[fd] = read_next_buff(fd))))
		return (-1);
	while (ft_strlen(current = read_next_buff(fd)) != 0 &&
			ft_strchr(tab[fd], '\n') == -1)
	{
		aux = ft_strjoin(tab[fd], current);
		free(current);
		free(tab[fd]);
		tab[fd] = aux;
	}
	return (update_status(fd, current, tab, line));
}
