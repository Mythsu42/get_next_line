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
	if (!*stash || !**stash)
		return (NULL);
//	line = ft_substr(*stash, 0, (ft_strlen(*stash)
//				- ft_strlen(ft_strchr(*stash, '\n')))+ 1);
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
	char		*line;
	char		*buffer;
	ssize_t		rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd = 1;
	while (rd > 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == 0 && (!stash || !*stash))
		{
			free(buffer);
			return (NULL);
		}
		if (rd < 0)
		{
			free(buffer);
			if (stash)
			{
				free(stash);
				stash = NULL;
			}
			return (NULL);
		}
		buffer[rd] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = NULL;
		free(buffer);
		stash = tmp;
		if (ft_strchr(stash, '\n'))
			return (ft_line(&stash));
	}
	if (stash && *stash)
	{
		line = ft_strdup(stash);
		free(stash);
		stash = NULL;
		return (line);
	}
	return (NULL);
}
