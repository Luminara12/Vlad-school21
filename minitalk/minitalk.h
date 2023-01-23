/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42    			+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:06:43 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/03/26 02:36:15 by ptarrago	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

size_t	ft_strlen(const char *a);
void	ft_putnbr_fd(int nb, int fd);
int		ft_atoi(const char *str);

#endif