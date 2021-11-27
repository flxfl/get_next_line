/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlkshk <smlkshk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:54:26 by smlkshk           #+#    #+#             */
/*   Updated: 2021/11/27 18:09:46 by smlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (*(s + i) == c)
		return ((char *)s + i);
	return ((void *)0);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*subs;
	int		i;

	if (!s)
		return ((void *)0);
	if (start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	i = (int)start;
	while (*(s + i) && i - start + 1 < len)
		i++;
	subs = (char *)malloc(sizeof(char) * (i - start + 2));
	if (!subs)
		return ((void *)0);
	*(subs + (i - start + 1)) = '\0';
	while (i > start)
	{
		*(subs + i - start) = *(s + i);
		i--;
	}
	*(subs + i - start) = *(s + i);
	return (subs);
}

void	ft_strrem(char **string)
{
	if (string)
	{
		free(*string);
		*string = (void *)0;
	}
}

char	*string_creator(int fd, char **string)
{
	int		i;
	char	*line;
	char	*saver;

	i = 0;
	line = (void *)0;
	while (string[fd][i] && string[fd][i] != '\n')
		i++;
	if (!string[fd][i])
	{
		line = ft_strdup(string[fd]);
		ft_strrem(&string[fd]);
	}
	else if (string[fd][i] == '\n')
	{
		line = ft_substr(string[fd], 0, i + 1);
		saver = ft_strdup(string[fd] + i + 1);
		ft_strrem(&string[fd]);
		string[fd] = saver;
		if (string[fd][0] == '\0')
			ft_strrem(&string[fd]);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	int			bytes;
	char		*saver;
	char		buf[BUFFER_SIZE + 1];
	static char	*string[10200];

	if (fd < 0 || fd > 10199 || BUFFER_SIZE <= 0)
		return ((void *)0);
	bytes = read(fd, buf, BUFFER_SIZE);
	while (bytes > 0)
	{
		*(buf + bytes) = '\0';
		if (!*(string + fd))
			*(string + fd) = ft_strdup("");
		saver = ft_strjoin(*(string + fd), buf);
		ft_strrem(string + fd);
		*(string + fd) = saver;
		if (ft_strchr(*(string + fd), '\n'))
			break ;
		bytes = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes < 0 || (bytes == 0 && !*(string + fd)))
		return ((void *)0);
	return (string_creator(fd, string));
}
