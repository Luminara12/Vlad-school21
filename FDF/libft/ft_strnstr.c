/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:21:57 by ptarrago          #+#    #+#             */
/*   Updated: 2021/10/24 14:10:19 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack1, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*haystack;

	i = 0;
	haystack = (char *)haystack1;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && (len > i))
	{
		j = 0;
		while (haystack[i + j] == needle[j] || needle[j] == '\0')
		{
			if (needle[j] == '\0')
				return (&haystack[i]);
			if (len <= (i + j))
				return (0);
			j++;
		}
		i++;
	}
	return (0);
}
