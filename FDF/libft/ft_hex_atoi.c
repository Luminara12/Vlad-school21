/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:59:46 by ptarrago          #+#    #+#             */
/*   Updated: 2022/06/11 12:11:40 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	degree(int i)
{
	int	number;

	number = 1;
	if (i == 0)
		return (1);
	while (i-- > 0)
		number = 16 * number;
	return (number);
}

static int	count(char *s, int i)
{
	int	sum;

	sum = 0;
	while (i)
	{
		if ((s[i + 1] == 'a') || (s[i + 1] == 'A'))
			sum = sum + 10 * degree(6 - i);
		else if ((s[i + 1] == 'b') || (s[i + 1] == 'B'))
			sum = sum + 11 * degree(6 - i);
		else if ((s[i + 1] == 'c') || (s[i + 1] == 'C'))
			sum = sum + 12 * degree(6 - i);
		else if ((s[i + 1] == 'd') || (s[i + 1] == 'D'))
			sum = sum + 13 * degree(6 - i);
		else if ((s[i + 1] == 'e') || (s[i + 1] == 'E'))
			sum = sum + 14 * degree(6 - i);
		else if ((s[i + 1] == 'f') || (s[i + 1] == 'F'))
			sum = sum + 15 * degree(6 - i);
		else
			sum = sum + (s[i + 1] - '0') * degree(6 - i);
		i--;
	}
	return (sum);
}

int	ft_hex_atoi(char *s)
{
	int	sum;
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i + 2])
		i++;
	sum = count(s, i);
	return (sum);
}
