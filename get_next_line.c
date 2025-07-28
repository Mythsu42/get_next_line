/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktolba <tolbakevin@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:15:51 by ktolba            #+#    #+#             */
/*   Updated: 2025/07/09 01:15:54 by ktolba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char **buffer, char **stash)
{
	char	*line;
	int	i;
	int	j;
	int	stash_len;

	i = 0;
	j = 0;
	stash_len = ft_strlen(*stash);
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	line = (char *)malloc(stash_len + i + 1);
	ft_strlcpy(line, *stash, (stash_len + i));
	i = 0;
	while ((*buffer)[i] != '\n')
		line[stash_len++] = *buffer[i++];
	line[stash_len] = '\n';
	while ((*buffer)[i])
	{
		i++;
		j++;
	}
	*stash = ft_substr(*buffer, ft_strlen(*buffer) - j, j);
	i -= j;
	j = 0;
	while ((*buffer)[i] && (*stash)[j])
		(*stash)[j++] = (*buffer)[i++];
	return (line);
}

char	*get_next_line(int fd)
{	
	char	*buffer;
	static char	*stash;
	ssize_t		rd;

	stash = ft_calloc(1,1);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while ((rd = read(fd, buffer, BUFFER_SIZE)) > 0)
	{	
		buffer[rd] = '\0';
		if (ft_strchr(buffer, '\n'))
			return (ft_line(&buffer, &stash));
		stash = ft_strjoin(stash,buffer);
	}
	free(buffer);
	return (NULL);
}

int	main(void)
{
	int	fd;
	char	*string;

	fd = open("./test.txt", O_RDONLY);
	string = get_next_line(fd);
	while (string != NULL)
	{
		printf("%s",string);
		string = get_next_line(fd);
	}
	return(0);
}
