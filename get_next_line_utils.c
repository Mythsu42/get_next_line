/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktolba <tolbakevin@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:16:02 by ktolba            #+#    #+#             */
/*   Updated: 2025/07/09 01:18:47 by ktolba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
        int     i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

void    *ft_calloc(size_t nmemb, size_t size)
{
        void    *ptr;
        size_t  size_max;
	size_t	i;

        size_max = -1;
	i = 0;
        if (nmemb != 0 && size > size_max / nmemb)
                return (NULL);
        ptr = malloc(nmemb * size);
        if (!ptr)
                return (NULL);
	while (i < nmemb * size)
		((unsigned char *)ptr)[i++] = '\0';
        return (ptr);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *result;
        size_t  s_len;
        size_t  i;

        s_len = ft_strlen(s);
        i = 0;
        if (!s)
                return (NULL);
        if (len > s_len - start)
                len = s_len - start;
        if (start >= s_len)
                return (ft_calloc(1, 1));
        result = malloc(sizeof(char) * (len + 1));
        if (!result)
                return (NULL);
        while (i < len && s[start])
                result[i++] = s[start++];
        result[i] = '\0';
        return (result);
}

char    *ft_strchr(const char *str, int c)
{
        size_t  i;

        i = 0;
        while (str[i])
	{
                if (str[i] == (char)c)
                        return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
                return ((char *)&str[i]);
        return (NULL);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
        size_t  i;
        size_t  j;

        i = 0;
        j = 0;
        while (src[i])
                i++;
        if (dstsize == 0)
                return (i);
        while (src[j] && j < dstsize - 1)
        {
                dst[j] = src[j];
                j++;
        }
        dst[j] = '\0';
        return (i);
}

char    *ft_strjoin(const char *s1, const char *s2)
{
        char    *dest;
        size_t  len;

        if (!s1 || !s2)
                return (NULL);
        len = ft_strlen(s1) + ft_strlen(s2);
        dest = malloc(sizeof(char) * (len + 1));
        if (!dest)
                return (NULL);
        ft_strlcpy(dest, s1, ft_strlen(s1) + 1);
        ft_strlcpy(dest + ft_strlen(s1), s2, ft_strlen(s2) + 1);
        return (dest);
}
