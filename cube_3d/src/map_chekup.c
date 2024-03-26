/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chekup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:25:44 by siroulea          #+#    #+#             */
/*   Updated: 2024/03/26 12:25:03 by siroulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chekup_character(char **map)
{
	int	i;
	int	j;
	int	maxj;
	int	maxi;

	i = 0;
	j = 0;
	maxj = ft_strlenj(map);
	maxi = ft_strlen(map[1]) - 1;
	while (j < maxj)
	{
		if (map[j][i] != '0' && map[j][i] != 'N' && map[j][i] != 'S'
			&& map[j][i] != 'E' && map[j][i] != 'W' && map[j][i] != '1'
			&& map[j][i] != ' ' && map[j][i] != '\t' && map[j][i] != '\n'
			&& map[j][i] != '\0')
			return (0);
		if (map[j])
			i++;
		if (i == maxi)
		{
			j++;
			i = 0;
		}
	}
	return (1);
}

int	found_player(char **map, int *npj, int *npi)
{
	t_data	*data;
	int		i;
	int		j;

	data = get_data();
	i = 0;
	j = 0;
	while (map[++j])
	{
		while (map[j][i++])
		{
			if (map[j][i] == 'N' | map[j][i] == 'S' | map[j][i] == 'W' | map[j][i] == 'E')
			{
				*npj = j;
				*npi = i;
				data->playerj = j;
				data->playeri = i;
				return (0);
			}
		}
		i = 0;
	}
	return (1);
}

void	calloc_path(char *type, int len)
{
	t_data	*data;

	data = get_data();
	if (type[0] == 'N' && type[1] == 'O')
		data->NO = ft_calloc(len + 1, sizeof(char));
	if (type[0] == 'S' && type[1] == 'O')
		data->SO = ft_calloc(len + 1, sizeof(char));
	if (type[0] == 'W' && type[1] == 'E')
		data->WE = ft_calloc(len + 1, sizeof(char));
	if (type[0] == 'E' && type[1] == 'A')
		data->EA = ft_calloc(len + 1, sizeof(char));
	if (type[0] == 'F')
		data->F = ft_calloc(len + 1, sizeof(char));
	if (type[0] == 'C')
		data->C = ft_calloc(len + 1, sizeof(char));
}

int	type_path(char *type, int len)
{
	t_data	*data;

	data = get_data();
	if (type[0] == 'N' && type[1] == 'O')
	{
		if (!data->NO)
			calloc_path("NO", len);
		else
			return (0);
	}
	if (type[0] == 'S' && type[1] == 'O')
	{
		if (!data->SO)
			calloc_path("SO", len);
		else
			return (0);
	}
	if (type[0] == 'W' && type[1] == 'E')
	{
		if (!data->WE)
			calloc_path("WE", len);
		else
			return (0);
	}
	if (type[0] == 'E' && type[1] == 'A')
	{
		if (!data->EA)
			calloc_path("EA", len);
		else
			return (0);
	}
	if (type[0] == 'F')
	{
		if (!data->F)
			calloc_path("F", len);
		else
			return (0);
	}
	if (type[0] == 'C')
	{
		if (!data->C)
			calloc_path("C", len);
		else
			return (0);
	}
	return (1);
}

int	extract_texture(char **map, int j, int i, char *type)
{
	t_data	*data;
	int		temp;
	int		len;
	int		no_path;

	no_path = 0;
	data = get_data();
	i = i + 2;
	len = 0;
	while ((map[j][i] == ' ' || map[j][i] == '\t') && map[j][i] != '\n'
		&& map[j][i] != '\0')
		i++;
	temp = i;
	while (map[j][i] != ' ' && map[j][i] != '\t' && map[j][i] != '\0'
		&& map[j][i] != '\n')
	{
		i++;
		len++;
	}
	if (type_path(type, len) == 0)
		return (0);
	i = temp;
	len = 0;
	if (type[0] == 'S' && type[1] == 'O')
	{
		while (map[j][i] != ' ' && map[j][i] != '\t' && map[j][i] != '\0'
			&& map[j][i] != '\n')
		{
			data->SO[len] = map[j][i];
			len++;
			i++;
		}
		data->SO[len] = '\0';
	}
	else if (type[0] == 'N' && type[1] == 'O')
	{
		while (map[j][i] != ' ' && map[j][i] != '\t' && map[j][i] != '\0'
			&& map[j][i] != '\n')
		{
			data->NO[len] = map[j][i];
			len++;
			i++;
		}
		data->NO[len] = '\0';
	}
	else if (type[0] == 'W' && type[1] == 'E')
	{
		while (map[j][i] != ' ' && map[j][i] != '\t' && map[j][i] != '\0'
			&& map[j][i] != '\n')
		{
			data->WE[len] = map[j][i];
			len++;
			i++;
		}
		data->WE[len] = '\0';
	}
	else if (type[0] == 'E' && type[1] == 'A')
	{
		while (map[j][i] != ' ' && map[j][i] != '\t' && map[j][i] != '\0'
			&& map[j][i] != '\n')
		{
			data->EA[len] = map[j][i];
			len++;
			i++;
		}
		data->EA[len] = '\0';
	}
	else if (type[0] == 'F')
	{
		while (map[j][i] != ' ' && map[j][i] != '\t' && map[j][i] != '\0'
			&& map[j][i] != '\n')
		{
			if (!((map[j][i] >= '0' && map[j][i] <= '9') || map[j][i] == ','))
				return (0);
			data->F[len] = map[j][i];
			len++;
			i++;
		}
		data->F[len] = '\0';
	}
	else if (type[0] == 'C')
	{
		while (map[j][i] != ' ' && map[j][i] != '\t' && map[j][i] != '\0'
			&& map[j][i] != '\n')
		{
			if (!((map[j][i] >= '0' && map[j][i] <= '9') || map[j][i] == ','))
				return (0);
			data->C[len] = map[j][i];
			len++;
			i++;
		}
		data->C[len] = '\0';
	}
	return (1);
}

// int	chekup_and_extract_texture2(char **map)
// {
	
// 	return (1);
// }

int	chekup_and_extract_texture(char **map)
{
	t_data	*data;
	int		i;
	int		j;
	int		no_path;

	data = get_data();
	i = 0;
	j = 0;
	no_path = 0;
	while (map[j])
	{
		while ((map[j][i] == ' ') && map[j][i] != '\n' && map[j][i] != '\0')
		{
			i++;
		}
		if (map[j][i] == 'N' && map[j][i + 1] == 'O' && map[j][i + 2] == ' ')
		{
			no_path++;
			if (extract_texture(map, j, i, "NO") == 0)
				return (0);
		}
		else if (map[j][i] == 'S' && map[j][i + 1] == 'O' && map[j][i
			+ 2] == ' ')
		{
			no_path++;
			if (extract_texture(map, j, i, "SO") == 0)
				return (0);
		}
		else if (map[j][i] == 'W' && map[j][i + 1] == 'E' && map[j][i
			+ 2] == ' ')
		{
			no_path++;
			if (extract_texture(map, j, i, "WE") == 0)
				return (0);
		}
		else if (map[j][i] == 'E' && map[j][i + 1] == 'A' && map[j][i
			+ 2] == ' ')
		{
			no_path++;
			if (extract_texture(map, j, i, "EA") == 0)
				return (0);
		}
		else if (map[j][i] == 'F' && map[j][i + 1] == ' ')
		{
			no_path++;
			if (extract_texture(map, j, i, "F") == 0)
				return (0);
		}
		else if (map[j][i] == 'C' && map[j][i + 1] == ' ')
		{
			no_path++;
			if (extract_texture(map, j, i, "C") == 0)
				return (0);
		}
		if (no_path == 6 && map[j][i] == '1')
		{
			data->start_map = j;
			return (1);
		}
		i = 0;
		j++;
	}
	return (1);
}

int	extract_rgb(void)
{
	t_data	*data;
	int		i;
	int		j;
	int		rgb;
	char	*temp;

	data = get_data();
	i = 0;
	j = 0;
	rgb = 1;
	temp = malloc(sizeof(char) * 4);
	while (data->F[i])
	{
		while (data->F[i] != ',' && data->F[i])
		{
			temp[j] = data->F[i];
			i++;
			j++;
		}
		if (rgb == 1)
		{
			temp[j] = '\0';
			data->F_R = ft_atoi(temp);
		}
		else if (rgb == 2)
		{
			temp[j] = '\0';
			data->F_G = ft_atoi(temp);
		}
		else if (rgb == 3)
		{
			temp[j] = '\0';
			data->F_B = ft_atoi(temp);
		}
		if (data->F[i] == ',')
			rgb++;
		j = 0;
		i++;
	}
	if (rgb != 3)
		return (0);
	i = 0;
	j = 0;
	rgb = 1;
	while (data->C[i])
	{
		while (data->C[i] != ',' && data->C[i])
		{
			temp[j] = data->C[i];
			i++;
			j++;
		}
		if (rgb == 1)
		{
			temp[j] = '\0';
			data->C_R = ft_atoi(temp);
		}
		else if (rgb == 2)
		{
			temp[j] = '\0';
			data->C_G = ft_atoi(temp);
		}
		else if (rgb == 3)
		{
			temp[j] = '\0';
			data->C_B = ft_atoi(temp);
		}
		if (data->C[i] == ',')
			rgb++;
		j = 0;
		i++;
	}
	if (rgb != 3)
		return (0);
	return (1);
}

int	chekup_f_and_c(void)
{
	t_data	*data;

	data = get_data();
	if (!data->F || !data->C)
		return (0);
	if (ft_strncmp(data->F, data->C) == 0)
		return (0);
	return (1);
}

int	chekup_rgb(void)
{
	t_data	*data;

	data = get_data();
	if (data->F_R > 255 || data->F_G > 255 || data->F_B > 255 || data->C_R > 255
		|| data->C_G > 255 || data->C_B > 255)
		return (0);
	return (1);
}
