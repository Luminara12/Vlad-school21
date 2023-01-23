/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:02:45 by ptarrago          #+#    #+#             */
/*   Updated: 2022/06/09 21:46:50 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while ((i < (size - 1)) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		if (size)
			dst[i] = '\0';
	}
	if (src[i])
	{
		while (src[i])
			i++;
	}
	return (i);
}
