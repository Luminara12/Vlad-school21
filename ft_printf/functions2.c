/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:07:38 by ptarrago          #+#    #+#             */
/*   Updated: 2022/01/09 17:33:07 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u(unsigned int n)
{
	char	c;
	int		a;

	a = 0;
	if (n >= 10)
	{
		a += ft_di(n / 10);
		c = '0' + n % 10;
		write(1, &c, 1);
		a++;
	}
	else
	{
		c = '0' + n % 10;
		write(1, &c, 1);
		a++;
	}
	return (a);
}

int	ft_x(unsigned int n)
{
	char	c;
	int		a;

	a = 0;
	if (n >= 16)
	{
		a += ft_x(n / 16);
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

int	ft_xuc(unsigned int n)
{
	char	c;
	int		a;

	a = 0;
	if (n >= 16)
	{
		a += ft_xuc(n / 16);
		if (n % 16 < 10)
			c = '0' + n % 16;
		else
			c = 'A' + n % 16 - 10;
		write(1, &c, 1);
		a++;
	}
	else
	{
		if (n % 16 < 10)
			c = '0' + n % 16;
		else
			c = 'A' + n % 16 - 10;
		write(1, &c, 1);
		a++;
	}
	return (a);
}

int	ft_di(int d)
{
	char			c;
	unsigned int	n;
	int				a;

	a = 0;
	n = d;
	if (d < 0)
	{
		a += ft_di_putchar('-');
		n = d * (-1);
	}
	if (n >= 10)
	{
		a += ft_di(n / 10);
		c = '0' + n % 10;
		a += ft_di_putchar(c);
	}
	else
	{
		c = '0' + n % 10;
		a += ft_di_putchar(c);
	}
	return (a);
}

int	ft_di_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
