/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:35:12 by ptarrago          #+#    #+#             */
/*   Updated: 2021/10/24 14:11:30 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *c1, const char *c2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)c1;
	s2 = (unsigned char *)c2;
	while (((s1[i]) || (s2[i])) && (n-- > 0))
	{
		if ((s1[i] != s2[i]))
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
