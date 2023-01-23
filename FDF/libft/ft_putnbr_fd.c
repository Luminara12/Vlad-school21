/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:46:55 by ptarrago          #+#    #+#             */
/*   Updated: 2022/06/09 21:49:01 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static unsigned int	sign(int nb, int fd)
{
	unsigned int	nbu;

	if (nb < 0)
	{
		write(fd, "-", 1);
		nbu = nb * (-1);
	}
	else
		nbu = nb;
	return (nbu);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int				i;
	char			*b;
	char			q[11];
	unsigned int	nbi;

	i = 0;
	nbi = sign(nb, fd);
	if (nbi == 0)
		write(fd, "0", 1);
	while (nbi > 0)
	{
		q[i] = '0' + nbi % 10;
		nbi = nbi / 10;
		i++;
	}
	while (i-- > 0)
	{
		b = &q[i];
		write(fd, b, 1);
	}
}
