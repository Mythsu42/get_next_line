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


