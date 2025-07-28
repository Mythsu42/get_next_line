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

char	*ft_line(char **stash)
{
	char	*line;
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!*stash || !(*stash)[0])
		return (NULL);
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	while ((*stash)[j] && (*stash)[j] != '\n')
	{
		line[j] = (*stash)[j];
		j++;
	}
	if ((*stash)[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	if ((*stash)[j])
	{
		new_stash = ft_strdup(&((*stash)[j]));
		free(*stash);
		*stash = new_stash;
	}
	else
	{
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*tmp;
	char		*buffer;
	char		*line;
	ssize_t		rd;

	rd = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = tmp;
		if (ft_strchr(stash, '\n'))
		{
			free(buffer);
			return (ft_line(&stash));
		}
	}
	if (stash && *stash)
	{
		line = ft_strdup(stash);
		free(stash);
		stash = NULL;
		free(buffer);
		return (line);
	}
	free(buffer);
	return (NULL);
}
