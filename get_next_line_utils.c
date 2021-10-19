/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlkshk <smlkshk@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:54:29 by smlkshk           #+#    #+#             */
/*   Updated: 2021/10/19 13:23:43 by smlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s_c;

	i = -1;
	s_c = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s_c)
		return ((void *)0);
	while (*(s1 + ++i))
		*(s_c + i) = *(s1 + i);
	*(s_c + i) = '\0';
	return (s_c);
}

void	*ft_memmove(void *dst, const void *src, int n)
{
	int		i;
	char	*l1;
	char	*l2;

	if (!dst && !src)
		return ((void *)0);
	l1 = (char *)dst;
	l2 = (char *)src;
	if (l1 > l2)
	{
		i = n;
		while (i--)
			*(l1 + i) = *(l2 + i);
	}
	else
	{
		i = -1;
		while (++i < n)
			*(l1 + i) = *(l2 + i);
	}
	return (l1);
}

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	dst_l;
	int	src_l;
	int	j;

	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	j = -1;
	if (!dstsize)
		return (src_l);
	if (dstsize < dst_l)
		return (src_l + dstsize);
	while (++j < src_l && dst_l + j + 1 < dstsize)
		*(dst + dst_l + j) = *(src + j);
	*(dst + dst_l + j) = '\0';
	return (dst_l + src_l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*res;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	l1 = (int)ft_strlen(s1);
	l2 = (int)ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!res)
		return ((void *)0);
	res = ft_memmove(res, s1, l1 + 1);
	ft_strlcat(res, s2, l1 + l2 + 1);
	return (res);
}
