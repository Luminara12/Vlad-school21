/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:02:47 by ptarrago          #+#    #+#             */
/*   Updated: 2021/10/19 22:33:39 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	c = c % 128;
	str = (char *)s;
	while (str[i])
		i++;
	if (c == '\0')
		return (str + i);
	while (i > 0)
	{
		i--;
		if (str[i] == c)
			return (str + i);
	}
	return (0);
}
