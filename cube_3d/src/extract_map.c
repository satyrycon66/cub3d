/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:25:11 by siroulea          #+#    #+#             */
/*   Updated: 2024/03/26 11:51:26 by siroulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chekup_cub(char *namemap)
{
	int	len;

	len = ft_strlen(namemap);
	if (namemap[len - 4] != '.' || namemap[len - 3] != 'c' || namemap[len
			- 2] != 'u' || namemap[len - 1] != 'b')
	{
		write(2, "Error\nnot .cub\n", 15);
		return (0);
	}
	return (1);
}

int	how_many_line(char *mapname)
{
	int		fd;
	int		i;
	t_data	*data;

	data = get_data();
	i = 0;
	fd = open(mapname, 0);
	while (get_next_line(fd))
	{
		i++;
		free(data->line);
	}
	close(fd);
	return (i);
}

char	**extract_map(char *mapname, int i, int j)
{
	int		fd;
	t_data	*data;
	int		f;

	f = 0;
	data = get_data();
	fd = open(mapname, 0);
	i = how_many_line(mapname);
	fd = open(mapname, 0);
	data->map = ft_calloc(sizeof(char *), i + 1);
	if (fd < 3 && fd != 0)
	{
		write(2, "no fd\n", 6);
		return (0);
	}
	while (fd)
	{
		data->map[j] = get_next_line(fd);
		if (data->map[j] == NULL)
			break ;
		j++;
	}
	close(fd);
	return (data->map);
}
