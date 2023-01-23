/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_FF.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:26:08 by ptarrago     		  #+#    #+#          */
/*   Updated: 2022/03/11 21:26:17 by ptarrago   	      ###   ########.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	ff(t_list *a, t_data data)
{
	int	coucou;

	coucou = 0;
	while (a->content != data.min)
	{
		a = a->next;
		coucou++;
	}
	return (coucou);
}
