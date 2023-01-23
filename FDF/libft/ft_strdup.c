/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:23:42 by ptarrago          #+#    #+#             */
/*   Updated: 2021/10/23 17:40:06 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str1)
{
	int		length;
	char	*s1;
	char	*s2;

	s1 = (char *)str1;
	length = ft_strlen(s1);
	s2 = malloc (sizeof(char) * length + 1);
	if (s2 == 0)
		return (0);
	ft_strlcpy(s2, s1, length + 1);
	return (s2);
}
