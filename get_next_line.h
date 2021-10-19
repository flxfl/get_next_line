/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlkshk <smlkshk@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:54:32 by smlkshk           #+#    #+#             */
/*   Updated: 2021/10/19 15:31:23 by smlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

void	*ft_memmove(void *dst, const void *src, int n);
int		ft_strlcat(char *dst, const char *src, int dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, int start, int end);
void	ft_strdel(char **as);

char	*ft_strchr(const char *s, int c);

char	*get_next_line(int fd);
char	*string_creator(int fd, char **string);

#endif