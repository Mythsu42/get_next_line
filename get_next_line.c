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

int	handle_error_read(ssize_t rd, char **buffer, char **stash)
{
	if (rd == 0 && (!*stash || !**stash))
	{
		free(*buffer);
		return (0);
	}
	if (rd < 0)
	{
		free(*buffer);
		if (*stash)
		{
			free(*stash);
			*stash = NULL;
		}
		return (0);
	}
	(*buffer)[rd] = '\0';
	return (1);
}

char	*stash_and_extract_line(char **stash, char *buffer)
{
	char	*tmp;

	if (!*stash)
		*stash = ft_strdup("");
	tmp = ft_strjoin(*stash, buffer);
	free(*stash);
	*stash = NULL;
	free(buffer);
	*stash = tmp;
	if (ft_strchr(*stash, '\n'))
		return (ft_line(stash));
	return (NULL);
}

char	*ft_line(char **stash)
{
	char	*line;
	char	*new_stash;

	if (!*stash || !**stash)
		return (NULL);
	line = ft_substr(*stash, 0, (ft_strlen(*stash)
				- ft_strlen(ft_strchr(*stash, '\n'))) + 1);
	if (!line)
		return (NULL);
	new_stash = ft_strchr(*stash, '\n');
	if (new_stash && *(new_stash + 1))
	{
		new_stash = ft_strdup(ft_strchr(*stash, '\n') + 1);
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

char	*return_last_line(char **stash)
{
	char	*line;

	if (!*stash || !**stash)
		return (NULL);
	line = ft_strdup(*stash);
	if (!line)
		return (NULL);
	free(*stash);
	*stash = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
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
		if (!handle_error_read(rd, &buffer, &stash))
			return (NULL);
		line = stash_and_extract_line(&stash, buffer);
		if (line)
			return (line);
	}
	if (stash && *stash)
		return (return_last_line(&stash));
	return (NULL);
}
