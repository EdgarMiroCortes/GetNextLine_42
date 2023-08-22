/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:01:09 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/31 19:02:17 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/*PRINCIPAL*/
char	*get_next_line(int fd);
void	*ft_free(char **s, int n);
char	*ft_read(int fd, char *tmp);

/*UTILS*/
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str, int variante);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

#endif
