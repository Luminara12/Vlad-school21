/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:41:57 by ptarrago          #+#    #+#             */
/*   Updated: 2021/11/11 21:30:03 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdlib.h>

static char	*ft_memal(size_t dlina, size_t len)
{
	char	*sub;

	if (dlina > len)
		sub = malloc(sizeof(char) * len + 1);
	else
		sub = malloc(sizeof(char) * (dlina) + 1);
	if (sub == 0)
		return (0);
	return (sub);
}

static char	*ft_bigstart(char *sub)
{
	sub[0] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*src;
	size_t	i;
	size_t	st;
	size_t	dlina;

	i = 0;
	if (s == 0)
		return (0);
	st = (size_t)start;
	src = (char *)s;
	dlina = (size_t)ft_strlen(src);
	sub = ft_memal(dlina, len);
	if ((sub == 0) || (s == 0))
		return (0);
	if ((int)st >= (int)dlina)
		return (ft_bigstart(sub));
	while ((src[i + st]) && (i < len))
	{
		sub[i] = src[i + st];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
