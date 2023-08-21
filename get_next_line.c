/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:55:55 by emiro-co          #+#    #+#             */
/*   Updated: 2023/06/05 19:04:40 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	int			nr_byt;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(&temp));
	nr_byt = 1;
	while (nr_byt > 0 && !ft_strlen(temp, 2))
	{
		nr_byt = read(fd, buf, BUFFER_SIZE);
		if (nr_byt == -1)
		{
			ft_free(&buf);
			return (ft_free(&temp));
		}
		if (nr_byt > 0)
		{
			buf[nr_byt] = '\0';
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
	char	*temp2;

	if (ft_strlen(s, 2) && s[ft_strlen(s, 3) + 1])
	{
		temp2 = s;
		s = ft_substr(s, ft_strlen(line, 1), ft_strlen(s, 1));
		if (temp2 != NULL)
			free(temp2);
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
	static char	*temp = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_fill(temp, fd);
	if (!temp)
		return (NULL);
	line = ft_get_line(temp);
	if (line == NULL)
		return (ft_free(&temp));
	temp = ft_clean(temp, line);
	return (line);
}
