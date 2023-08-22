/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 01:03:18 by emiro-co          #+#    #+#             */
/*   Updated: 2023/06/02 09:41:22 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_free(char **s, int n)
{
	if (n == 1)
	{
		free(*s);
		*s = NULL;
		return (NULL);
	}
	if (n == 2)
	{
		free(*s);
		*s = NULL;
	}
	if (n == 3)
	{
		free(*s);
		return (NULL);
	}
	return (0);
}

char	*ft_read(int fd, char *tmp)
{
	ssize_t	nr_byt;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(&tmp, 3));
	buf[0] = '\0';
	nr_byt = 1;
	while (nr_byt > 0 && ft_strlen(buf, 2) == 0)
	{
		nr_byt = read(fd, buf, BUFFER_SIZE);
		if (nr_byt < 0)
		{
			ft_free(&buf, 2);
			return (ft_free (&tmp, 1));
		}
		buf[nr_byt] = '\0';
		tmp = ft_strjoin(tmp, buf);
		if (!tmp)
			return (ft_free(&buf, 3));
	}
	free(buf);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*tmp[1024];
	ssize_t			i;
	char			*line;
	char			*tmp2;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_free (&tmp[fd], 1));
	tmp[fd] = ft_read(fd, tmp[fd]);
	if (!tmp[fd])
		return (NULL);
	if (tmp[fd][0] == '\0')
		return (ft_free (&tmp[fd], 1));
	i = ft_strlen(tmp[fd], 3) + ft_strlen(tmp[fd], 2);
	line = ft_substr(tmp[fd], 0, i);
	if (!line)
		return (ft_free (&tmp[fd], 1));
	if (ft_strlen(line, 2) == 1)
	{
		tmp2 = tmp[fd];
		tmp[fd] = ft_substr(tmp[fd], i, ft_strlen(tmp[fd], 1));
		free(tmp2);
	}
	else
		ft_free(&tmp[fd], 2);
	return (line);
}
