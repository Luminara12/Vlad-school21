/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:21:03 by ptarrago          #+#    #+#             */
/*   Updated: 2021/11/11 18:32:05 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_free(char **split, int j)
{
	while (j >= 0)
	{
		free(split[j]);
		j--;
	}
	free(split);
}

static int	ft_range(char const *s, char c)
{
	int	i;

	i = 0;
	while ((s[i]) && (s[i] != c))
		i++;
	return (i);
}

static int	ft_count(char const *s, char c)
{
	int	count;

	count = 0;
	if (!*s)
		return (0);
	while ((*s == c) && (*(s + 1)))
		s++;
	while (*(s + 1))
	{
		if ((*s == c) && ((*(s + 1)) != c))
			count++;
		s++;
	}
	return (count + 1);
}

static char	**ft_algorithm(char const *s, char **split, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (ft_range(s, c) != 0)
	{
		i = ft_range(s, c);
		split[count] = ft_substr(s, 0, i);
		if (split[count] == 0)
		{
			ft_free(split, count);
			return (0);
		}
		count++;
		s = s + i;
		while ((*s == c) && (*s))
			s++;
	}
	split[count] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**split;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	count = ft_count(s, c);
	while ((*s == c) && (*(s)))
		s++;
	split = malloc(sizeof(char *) * (count + 1));
	if (split == 0)
		return (0);
	count = 0;
	return (ft_algorithm(s, split, c));
}
