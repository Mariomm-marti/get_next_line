/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:28:01 by mmartin-          #+#    #+#             */
/*   Updated: 2020/01/22 15:13:13 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

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

static int	check_line(int fd, char **line, char **upper)
{
	char	*tmp;

	if (!*line[fd])
		return (0);
	tmp = ft_strjoin(line[fd], read_next_buff(fd));
	free(line[fd]);
	line[fd] = tmp;
	if (ft_strchr(line[fd], '\n') != -1)
	{
		*upper = ft_substr(line[fd], 0, ft_strchr(line[fd], '\n'));
		tmp = ft_substr(line[fd],
				ft_strchr(line[fd], '\n') + 1, ft_strlen(line[fd]));
		free(line[fd]);
		line[fd] = tmp;
		return (1);
	}
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	static char	*tab[4096];
	int			status;

	if (fd < 0 || (!tab[fd] && !(tab[fd] = read_next_buff(fd))))
		return (-1);
	if ((status = check_line(fd, tab, line)) != -1)
		return (status);
	while ((status = check_line(fd, tab, line)) == -1)
		;
	return (status);
}

int		main(int argc, char *argv[])
{
	int fd;
	char *line;
	int status;

	fd = open(argv[1], O_RDONLY);
	while ((status = get_next_line(fd, &line)) == 1)
	{
		printf("L: %s\n", line);
		free(line);
	}
	close(fd);
}
