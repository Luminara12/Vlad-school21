/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_libth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42   		    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:31:43 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/03/11 21:31:43 by ptarrago	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && dstsize > i + 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize)
		dst[i] = 0;
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substr;
	unsigned int		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		len = 0;
	s += start;
	start = s_len;
	if (start < len)
		len = start;
	substr = malloc(sizeof(*s) * (len + 1));
	if (substr)
		ft_strlcpy(substr, s, len + 1);
	return (substr);
}

static void	ft_bzero(void *b, size_t n)
{
	unsigned char	*buf;

	buf = (unsigned char *) b;
	while (n)
	{
		*buf = 0;
		buf ++;
		n --;
	}
	return ;
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*cal;

	cal = malloc(count * size);
	if (cal)
		ft_bzero(cal, count * size);
	return (cal);
}
