/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:06:55 by ptarrago          #+#    #+#             */
/*   Updated: 2022/01/09 19:28:19 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_s(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_hex(unsigned long n)
{
	char	c;
	int		a;

	a = 0;
	if (n >= 16)
	{
		a += ft_putnbr_hex(n / 16);
		if (n % 16 < 10)
			c = '0' + n % 16;
		else
			c = 'a' + n % 16 - 10;
		write(1, &c, 1);
		a++;
	}
	else
	{
		if (n % 16 < 10)
			c = '0' + n % 16;
		else
			c = 'a' + n % 16 - 10;
		write(1, &c, 1);
		a++;
	}
	return (a);
}

int	ft_p(void *d)
{
	unsigned long	adr;
	int				a;

	adr = (unsigned long)d;
	write(1, "0x", 2);
	a = ft_putnbr_hex(adr) + 2;
	return (a);
}
