/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:38:01 by ptarrago          #+#    #+#             */
/*   Updated: 2022/06/09 21:46:30 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	i = 0;
	s = (char *)src;
	d = (char *)dst;
	if (dst || src)
	{
		if (dst < src)
		{
			while (i < n)
			{
				d[i] = s[i];
				i++;
			}
			return (dst);
		}
		while (n--)
			d[n] = s[n];
		return (dst);
	}
	return (0);
}
