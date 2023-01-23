/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:02:02 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 18:02:04 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while ((*s1 || *s2) && n != 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1 ++;
		s2 ++;
		n --;
	}
	return (0);
}