/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:56:23 by ptarrago          #+#    #+#             */
/*   Updated: 2021/10/24 15:45:40 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_copy(char *str1, char *str2, char *res)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i])
	{
		res[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		res[i + j] = str2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if ((str1 == 0) && (str2 == 0))
		return (0);
	else if (str1 == 0)
		return (str2);
	else if (str2 == 0)
		return (str1);
	res = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2)) + 1);
	if (res == 0)
		return (0);
	return (ft_copy(str1, str2, res));
}
