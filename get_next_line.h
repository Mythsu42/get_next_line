/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktolba <tolbakevin@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:16:20 by ktolba            #+#    #+#             */
/*   Updated: 2025/07/09 01:16:23 by ktolba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strchr(const char *str, int c);
void    *ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
void    ft_bzero(void *str, size_t n);

char    *get_next_line(int fd);
int	main(void);

#endif
