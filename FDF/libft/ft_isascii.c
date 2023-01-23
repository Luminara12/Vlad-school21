/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:18:56 by ptarrago          #+#    #+#             */
/*   Updated: 2021/10/16 19:12:49 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int a)
{
	if ((a >= 0 && a <= 127))
		return (1);
	else
		return (0);
}
