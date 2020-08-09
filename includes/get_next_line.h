/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:41:15 by mmartin-          #+#    #+#             */
/*   Updated: 2020/08/09 22:27:04 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*gnl_strdup(const char *s);
char	*gnl_substr(const char *s, int start, int len);
char	*gnl_strjoin(const char *s1, const char *s2);
int		gnl_strlen(const char *s);
int		gnl_strchr(const char *s, char c);
int		get_next_line(int fd, char **line);

#endif
