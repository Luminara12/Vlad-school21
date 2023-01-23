/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b8.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:51:37 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/06 01:20:35 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	b_error_message(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	b_ft_strncmp(const char *c1, const char *c2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)c1;
	s2 = (unsigned char *)c2;
	while (((s1[i]) || (s2[i])) && (n-- > 0))
	{
		if ((s1[i] != s2[i]))
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

static int	b_ft_read(int fd, char **buf)
{
	char	transfer[1024];
	char	*tempmem;
	int		i;

	i = 1;
	while ((b_ft_strchr(*buf, '\n') == 0) && i)
	{
		i = read(fd, transfer, 1024);
		transfer[i] = '\0';
		tempmem = *buf;
		*buf = b_ft_strjoin(tempmem, transfer);
		free(tempmem);
	}
	*transfer = 0;
	return (i);
}

static char	*b_ft_gnlsplit(char **buf)
{
	int		i;
	char	*line;
	char	*final;

	i = 0;
	line = 0;
	while ((*(*buf + i) != '\n') && (*(*buf + i) != '\0'))
		i++;
	if (*(*buf + i) == '\n')
	{
		line = b_ft_substr(*buf, i + 1, b_ft_strlen(*buf) - i - 1);
		final = b_ft_substr(*buf, 0, i + 1);
	}
	else
		final = b_ft_substr(*buf, 0, b_ft_strlen(*buf));
	free (*buf);
	*buf = line;
	return (final);
}

char	*get_next_line(int fd)
{
	int			l;
	static char	*buf;
	char		*final;

	if (fd < 0 || 1024 <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (buf == 0)
	{
		buf = b_ft_substr("", 0, 0);
		if (buf == 0)
			return (0);
	}
	l = b_ft_read(fd, &buf);
	final = b_ft_gnlsplit(&buf);
	if ((l == 0) && (*final == 0))
	{
		free(final);
		return (0);
	}
	return (final);
}
