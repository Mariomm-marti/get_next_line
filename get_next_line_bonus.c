/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:28:01 by mmartin-          #+#    #+#             */
/*   Updated: 2020/01/25 15:23:24 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_next_buff(int fd, char **tab)
{
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];
	int		read_bytes;

	read_bytes = 0;
	while (read_bytes < BUFFER_SIZE)
		buffer[read_bytes++] = 0;
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 0)
		return (-1);
	if (read_bytes == 0)
		return (0);
	buffer[read_bytes] = 0;
	tmp = ft_strjoin(tab[fd], buffer);
	if (tab[fd])
		free(tab[fd]);
	tab[fd] = tmp;
	return (read_bytes);
}

static int	update_line(int fd, int read, char **tab, char **line)
{
	char *x;

	if (read < 0)
		return (-1);
	if (!tab[fd] && read == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (ft_strchr(tab[fd], '\n') != -1)
	{
		*line = ft_substr(tab[fd], 0, ft_strchr(tab[fd], '\n'));
		x = ft_substr(tab[fd], ft_strchr(tab[fd], '\n') + 1, ft_strlen(tab[fd]));
		free(tab[fd]);
		tab[fd] = x;
		return (1);
	}
	*line = ft_strdup(tab[fd]);
	free(tab[fd]);
	tab[fd] = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char		*tab[4096];
	int				read_bytes;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (tab[fd] && ft_strchr(tab[fd], '\n') != -1)
		return (update_line(fd, 0, tab, line));
	while ((read_bytes = read_next_buff(fd, tab)) > 0 &&
			ft_strchr(tab[fd], '\n') == -1)
		;
	return (update_line(fd, read_bytes, tab, line));
}
