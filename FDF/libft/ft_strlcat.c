/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:27:17 by ptarrago          #+#    #+#             */
/*   Updated: 2022/06/09 21:46:47 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static size_t	ft_one(char	*dst, const char *src, size_t dstsize, size_t i)
{
	size_t	j;

	j = 0;
	if (dstsize)
	{
		while ((i < (dstsize - 1)) && src[j])
		{
			dst[i] = src[j];
			i++;
			j++;
		}
	}
	if (dstsize)
		dst[i] = '\0';
	while (src[j])
	{
		i++;
		j++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (i > dstsize)
		return (ft_strlen(src) + dstsize);
	i = ft_one(dst, src, dstsize, i);
	return (i);
}
