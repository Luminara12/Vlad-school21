/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:34:52 by ptarrago          #+#    #+#             */
/*   Updated: 2022/01/09 19:08:55 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *arg1, ...);
int		ft_print_var(va_list args, const char *arg1);
int		ft_putchar(int c);
int		ft_s(char *s);
int		ft_putnbr_hex(unsigned long n);
int		ft_p(void *d);
int		ft_di(int d);
int		ft_di_putchar(char c);
int		ft_u(unsigned int n);
int		ft_x(unsigned int n);
int		ft_xuc(unsigned int n);
#endif