/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:25:37 by quakk             #+#    #+#             */
/*   Updated: 2023/12/14 19:16:31 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read_buffer(int fd, char *savedstr)
{
	int		bytesread;
	char	*buffer;

	bytesread = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!gnl_ft_strchr(savedstr, '\n') && bytesread != 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(buffer);
			free(savedstr);
			return (NULL);
		}
		buffer[bytesread] = '\0';
		savedstr = gnl_ft_strjoin(savedstr, buffer);
	}
	free(buffer);
	return (savedstr);
}

char	*get_next_line(int fd)
{
	static char	*savedstr[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	savedstr[fd] = ft_read_buffer(fd, savedstr[fd]);
	if (!savedstr[fd])
		return (NULL);
	line = ft_obtain_line(savedstr[fd]);
	savedstr[fd] = ft_delete_line(savedstr[fd]);
	if (!line || !*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
