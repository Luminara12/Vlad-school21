/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:59:11 by ptarrago          #+#    #+#             */
/*   Updated: 2022/01/09 19:11:36 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *arg1, ...)
{
	va_list	args;
	int		a;

	a = 0;
	va_start(args, arg1);
	while (*arg1)
	{
		if (arg1[0] != '%')
		{
			a += ft_putchar(arg1[0]);
			arg1++;
		}
		else
		{
			arg1++;
			a += ft_print_var(args, arg1);
			arg1++;
		}
	}
	va_end(args);
	return (a);
}

int	ft_print_var(va_list args, const char *arg1)
{
	int	a;

	a = 0;
	if (arg1[0] == 'c')
		a += ft_putchar(va_arg(args, int));
	else if (arg1[0] == 's')
		a += ft_s(va_arg(args, char *));
	else if (arg1[0] == 'p')
		a += ft_p(va_arg(args, void *));
	else if (arg1[0] == 'd' || arg1[0] == 'i')
		a += ft_di(va_arg(args, int));
	else if (arg1[0] == 'u')
		a += ft_u(va_arg(args, unsigned int));
	else if (arg1[0] == 'x')
		a += ft_x(va_arg(args, unsigned int));
	else if (arg1[0] == 'X')
		a += ft_xuc(va_arg(args, unsigned int));
	else
		a += ft_putchar('%');
	return (a);
}
