/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:18:49 by emiro-co          #+#    #+#             */
/*   Updated: 2023/06/01 11:27:16 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	n;
	char	*s;

	s = src;
	i = 0;
	n = ft_strlen(s, 1);
	if (size != 0)
	{
		while (--size && s[i] != '\0')
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (n);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*buf;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1, 1) + ft_strlen(s2, 1);
	buf = malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		buf[i] = s1[i];
	j = -1;
	while (s2[++j])
		buf[j + i] = s2[j];
	buf[i + j] = '\0';
	free(s1);
	return (buf);
}

/* VARIANTE 1 : UN STRLEN NORMAL*/
/* VARIANTE 2 : NOS DEVUELVE SI HAY UN \n O NO */
/* VARIANTE 3 : CUANTO FALTA HASTA \n O \0 */
size_t	ft_strlen(const char *str, int variante)
{
	size_t	i;

	i = 0;
	if (variante == 1 && str)
	{
		while (str[i] != '\0')
			i++;
		return (i);
	}
	else if (variante == 2 && str)
	{
		while (*str)
		{
			if (*str == '\n')
				return (1);
			str++;
		}
	}
	else if (variante == 3 && str)
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*subs;

	if (!s)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
		i++;
	j = 0;
	subs = malloc((i + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	while (j < i && start < ft_strlen(s, 1))
	{
		subs[j] = s[start + j];
		j++;
	}
	subs[i] = '\0';
	return (subs);
}

char	*ft_strdup(const char *s)
{
	char	*k;

	k = (char *)malloc(sizeof(char) * (ft_strlen(s, 1) + 1));
	if (!k)
		return (NULL);
	ft_strlcpy(k, (char *)s, ft_strlen(s, 1) + 1);
	return (k);
}
