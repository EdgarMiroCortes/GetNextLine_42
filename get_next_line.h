/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:56:08 by emiro-co          #+#    #+#             */
/*   Updated: 2023/06/05 19:03:21 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/*PRINCIPAL*/
char	*get_next_line(int fd);
char	*ft_fill(char *temp, int fd);
char	*ft_get_line(char *temp);
char	*ft_clean(char *temp, char *line);
char	*ft_free(char **str);

/*UTILS*/
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlen(const char *str, int variante);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);

#endif