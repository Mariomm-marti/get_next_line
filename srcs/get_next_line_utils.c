/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:34:20 by mmartin-          #+#    #+#             */
/*   Updated: 2021/03/14 18:50:52 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <stddef.h>
#include <stdlib.h>

int	gnl_strlen(const char *s)
{
	int		count;

	count = 0;
	if (!s)
		return (count);
	while (*(s + count))
		count++;
	return (count);
}

int	gnl_strchr(const char *s, char c)
{
	int		count;

	count = -1;
	while (*(s + ++count))
		if (*(s + count) == c)
			return (count);
	return (-1);
}

char	*gnl_strdup(const char *s)
{
	char	*alloc;
	size_t	count;

	count = 0;
	while (*(s + count))
		count++;
	alloc = malloc(count + 1);
	if (!alloc)
		return (NULL);
	*(alloc + count) = 0;
	while (count-- > 0)
		*(alloc + count) = *(s + count);
	return (alloc);
}

char	*gnl_substr(const char *s, int start, int len)
{
	char	*allocated;
	int		count;

	if (!s)
		return (NULL);
	if (gnl_strlen(s) < start)
		return (gnl_strdup(""));
	if (gnl_strlen(s + start) < len)
		len = gnl_strlen(s + start);
	allocated = malloc(len + 1);
	if (!allocated)
		return (NULL);
	count = 0;
	while (count < len)
	{
		*(allocated + count) = *(s + count + start);
		count++;
	}
	*(allocated + count) = 0;
	return (allocated);
}

char	*gnl_strjoin(const char *s1, const char *s2)
{
	int		count;
	int		count_s2;
	char	*alloc;

	if (!s2)
		return (NULL);
	if (!s1)
		return (gnl_strdup(s2));
	alloc = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!alloc)
		return (NULL);
	count = -1;
	while (*(s1 + ++count))
		*(alloc + count) = *(s1 + count);
	count_s2 = -1;
	while (*(s2 + ++count_s2))
	{
		*(alloc + count) = *(s2 + count_s2);
		count++;
	}
	*(alloc + count) = 0;
	return (alloc);
}
