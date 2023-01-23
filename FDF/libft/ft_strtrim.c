/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:46:12 by ptarrago          #+#    #+#             */
/*   Updated: 2021/10/26 22:05:40 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_st(char s, char *st)
{
	int	i;

	i = 0;
	while (st[i])
	{
		if (st[i] == s)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_begtrim(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_st(str[i], set) == 0)
		{
			str = &str[i];
			return (str);
		}
		i++;
	}
	str = &str[i];
	return (str);
}

static int	ft_endtrim(char *str, char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	i--;
	while (i > 0)
	{
		if (ft_st(str[i], set) == 0)
			return (i);
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set1)
{
	char	*str;
	char	*set;
	int		i;

	if (!s1 || !set1)
		return (0);
	str = (char *)s1;
	set = (char *)set1;
	if (str == 0)
		return (0);
	str = ft_begtrim(str, set);
	i = ft_endtrim(str, set);
	return (ft_substr(str, 0, i + 1));
}
