/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:55:42 by emiro-co          #+#    #+#             */
/*   Updated: 2023/06/05 19:03:21 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
		str = NULL;
		return (NULL);
	}
	return (NULL);
}

char	*ft_fill(char *temp, int fd)
{
	char		*buf;
	int			bytes;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(&temp));
	bytes = 1;
	while (bytes > 0 && !ft_strlen(temp, 2))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			ft_free(&buf);
			return (ft_free(&temp));
		}
		if (bytes > 0)
		{
			buf[bytes] = '\0';
			temp = ft_strjoin(temp, buf);
			if (!temp)
				return (ft_free(&buf));
		}
	}
	free (buf);
	return (temp);
}

char	*ft_get_line(char *temp)
{
	char		*line;
	ssize_t		i;

	i = ft_strlen(temp, 3);
	if (temp[i] == '\n')
		line = ft_substr(temp, 0, i + 1);
	else
		line = ft_substr(temp, 0, i);
	return (line);
}

char	*ft_clean(char *s, char *line)
{
	char	*scopy;

	if (ft_strlen(s, 2) && s[ft_strlen(s, 3) + 1])
	{
		scopy = s;
		s = ft_substr(s, ft_strlen(line, 1), ft_strlen(s, 1));
		if (scopy != NULL)
			free(scopy);
		if (s == NULL)
			return (ft_free(&s));
	}
	else
	{
		free(s);
		s = NULL;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*temp[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp[fd] = ft_fill(temp[fd], fd);
	if (!temp[fd])
		return (NULL);
	line = ft_get_line(temp[fd]);
	if (line == NULL)
		return (ft_free(&temp[fd]));
	temp[fd] = ft_clean(temp[fd], line);
	return (line);
}
