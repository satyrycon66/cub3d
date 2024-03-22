/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:26:05 by siroulea          #+#    #+#             */
/*   Updated: 2023/06/14 15:09:38 by siroulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoing(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		i2;

	i = -1;
	i2 = -1;
	if (s1 == NULL)
	{
		s1 = ft_calloc(sizeof(char), 1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = 0;
	}
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++i2])
		dest[i + i2] = s2[i2];
	dest[i + i2] = '\0';
	return (s1 = ft_free(s1), dest);
}

char	*ft_freestash(char *stash)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	rest = ft_calloc(sizeof(char), (ft_strlen(stash) - i) + 1);
	j = 0;
	while (stash[i])
		rest[j++] = stash[i++];
	rest[j] = '\0';
	if (i == 0)
		ft_free(rest);
	stash = ft_free(stash);
	return (rest);
}

char	*ft_get_line(char *stash)
{
	t_data	*data;
	int		i;

	data = get_data();
	i = 0;
	if (!*stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	data->line = ft_calloc(sizeof(char), i + 1);
	if (!data->line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		data->line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n' || stash[i] == '\0')
		data->line[i++] = '\n';
	data->line[i] = '\0';
	return (data->line);
}

char	*ft_read(int fd, char *stash)
{
	char	*buffer;
	int		nbytes;

	nbytes = 1;
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n') && nbytes != 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == 0)
			break ;
		if (nbytes == -1)
			return (free(stash), free(buffer), NULL);
		buffer[nbytes] = '\0';
		stash = ft_strjoing(stash, buffer);
	}
	ft_free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd == 0)
		return (0);
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	line = NULL;
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_freestash(stash);
	return (line);
}
