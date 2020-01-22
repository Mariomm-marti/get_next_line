/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:41:15 by mmartin-          #+#    #+#             */
/*   Updated: 2020/01/22 15:09:47 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_substr(const char *s, size_t start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strlen(const char *s);
int		ft_strchr(const char *s, char c);
int		get_next_line(int fd, char **line);

#endif
