/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:34:20 by mmartin-          #+#    #+#             */
/*   Updated: 2020/01/22 15:14:52 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int		ft_strlen(const char *s)
{
	int		count;

	count = 0;
	while (*(s + count))
		count++;
	return (count);
}

int		ft_strchr(const char *s, char c)
{
	int		count;

	count = -1;
	while (*(s + count++))
		if (*(s + count) == c)
			return (count);
	return (-1);
}

char	*ft_strdup(const char *s)
{
	char	*alloc;
	size_t	count;

	count = 0;
	while (*(s + count))
		count++;
	if (!(alloc = (char *)malloc(count + 1)))
		return (NULL);
	*(alloc + count) = 0;
	while (count-- > 0)
		*(alloc + count) = *(s + count);
	return (alloc);
}

char	*ft_substr(const char *s, size_t start, size_t len)
{
	char	*allocated;
	size_t	count;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	len = ((ft_strlen(s + start) < len) ? ft_strlen(s + start) : len);
	if ((allocated = (char *)malloc(len + 1)) == NULL)
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	count;
	size_t	count_s2;
	char	*alloc;

	if (!s1 || !s2)
		return (NULL);
	if ((alloc = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	count = 0;
	while (*(s1 + count))
	{
		*(alloc + count) = *(s1 + count);
		count++;
	}
	count_s2 = 0;
	while (*(s2 + count_s2))
	{
		*(alloc + count) = *(s2 + count_s2);
		count++;
		count_s2++;
	}
	*(alloc + count) = 0;
	return (alloc);
}
