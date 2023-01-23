/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b6.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:46:26 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/06 00:54:31 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	*b_ft_memal(size_t dlina, size_t len)
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

char	*b_ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	dlina;

	i = 0;
	if (s == 0)
		return (0);
	dlina = (size_t)b_ft_strlen(s);
	sub = b_ft_memal(dlina, len);
	if ((sub == 0) || (s == 0))
		return (0);
	if ((int)start >= (int)dlina)
	{
		sub[0] = '\0';
		return (sub);
	}
	while ((s[i + start]) && (i < len))
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

size_t	b_ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

char	*b_ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	c = c % 128;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (0);
}
