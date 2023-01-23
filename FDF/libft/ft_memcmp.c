/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:39:28 by ptarrago          #+#    #+#             */
/*   Updated: 2022/06/09 21:45:54 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *c1, const void *c2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)c1;
	s2 = (unsigned char *)c2;
	i = 0;
	while (n-- > 0)
	{
		if ((s1[i] != s2[i]))
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
