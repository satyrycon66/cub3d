/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chekup2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:09:34 by siroulea          #+#    #+#             */
/*   Updated: 2024/03/26 13:00:33 by siroulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chek_path(char type, char *path)
{
	t_data	*data;

	data = get_data();
	if (type != 'N')
	{
		if (ft_strncmp(path, data->NO) == 0)
			return (0);
	}
	if (type != 'S')
	{
		if (ft_strncmp(path, data->SO) == 0)
			return (0);
	}
	if (type != 'W')
	{
		if (ft_strncmp(path, data->WE) == 0)
			return (0);
	}
	if (type != 'E')
	{
		if (ft_strncmp(path, data->EA) == 0)
			return (0);
	}
	return (1);
}

int	chekup_path(void)
{
	t_data	*data;

	data = get_data();
	if (chek_path('N', data->NO) == 0)
		return (0);
	if (chek_path('S', data->SO) == 0)
		return (0);
	if (chek_path('W', data->WE) == 0)
		return (0);
	if (chek_path('E', data->EA) == 0)
		return (0);
	return (1);
}

void	extract_real_map(void)
{
	int		i;
	int		j;
	int		g;
	t_data	*data;

	data = get_data();
	i = 0;
	g = 0;
	data->maxj = ft_strlenj(data->map);
	j = data->start_map;
	data->real_map = (char **)calloc(sizeof(char *), (data->maxj
				- data->start_map) + 1);
	while (data->map[j])
	{
		data->real_map[g] = (char *)calloc(sizeof(char) ,
				ft_strlen(data->map[j]) +1);
		while (data->map[j][i])
		{
			data->real_map[g][i] = data->map[j][i];
			++i;
		}
		++j;
		++g;
		i = 0;
	}
	data->real_map[g] = NULL;
}

int	ft_mapchekup2(void)
{
	t_data	*data;

	data = get_data();
	if (chekup_rgb() == 0)
	{
		write(2, "Error\nrgb\n", 11);
		return (0);
	}
	extract_real_map();
	if (chekup_character(data->real_map) == 0)
	{
		write(1, "Error\ncharacter\n", 16);
		return (0);
	}
	if (contchar(data->real_map, 0) == 0)
	{
		write(1, " Error\ncontchar\n", 16);
		return (0);
	}
	if (flood_fill_main(data->real_map, 0, 0) == 0)
	{
		write(1, "Error\nmap impossible\n", 21);
		return (0);
	}
	return (1);
}

int	ft_mapchekup(char **map)
{
	if (chekup_and_extract_texture(map) == 0)
	{
		write(2, "Error\npath\n", 12);
		return (0);
	}
	if (chekup_path() == 0)
	{
		write(2, "Error\npath texture\n", 20);
		return (0);
	}
	if (chekup_f_and_c() == 0)
	{
		write(2, "Error\nF or C\n", 14);
		return (0);
	}
	if (extract_rgb() == 0)
	{
		write(2, "Error\nextract rgb\n", 19);
		return (0);
	}
	if (ft_mapchekup2() == 0)
		return (0);
	return (1);
}
