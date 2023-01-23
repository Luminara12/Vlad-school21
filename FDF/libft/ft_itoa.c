/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:15:05 by ptarrago          #+#    #+#             */
/*   Updated: 2022/06/09 21:49:14 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

static char	*ft_strprep(int n, int power)
{
	char	*str;

	str = malloc(sizeof(char) * power + 1);
	if (str == 0)
		return (0);
	str[power] = '\0';
	power--;
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[power] = '0';
	while (n != 0)
	{
		if (n > 0)
			str[power] = '0' + (n % 10);
		else
			str[power] = '0' - (n % 10);
		n = n / 10;
		power--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int	i;
	int	power;
	int	n2;

	n2 = n;
	i = 0;
	power = 0;
	if (n <= 0)
		power++;
	while (n2 != 0)
	{
		n2 = n2 / 10;
		power++;
	}
	return (ft_strprep(n, power));
}
