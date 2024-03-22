/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chekup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:25:44 by siroulea          #+#    #+#             */
/*   Updated: 2024/03/22 11:20:12 by siroulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	chekup_mapsize(char **map)
// {
// 	int	i;
// 	int	j;
// 	int	maxj;
// 	int	maxi;

// 	maxi = ft_strlen(map[0]);
// 	maxj = ft_strlenj(map);
// 	j = 0;
// 	i = ft_strlen(map[0]);
// 	if (!(maxi - 1 >= maxj) || maxi > 41 || maxj > 21)
// 	{
// 		write(1, "Error\nmapsize\n", 14);
// 		return (0);
// 	}
// 	while (j < maxj - 1)
// 	{
// 		if (ft_strlen(map[j]) != i)
// 		{
// 			write(1, "Error\nmaplen\n", 13);
// 			return (0);
// 		}
// 		j++;
// 	}
// 	return (1);
// }

// int	chekup_contour(char **map)
// {
// 	int		i;
// 	int		j;
// 	int		maxi;
// 	t_data	*data;

// 	data = get_data();
// 	j = 0;
// 	i = 0;
// 	maxi = ft_strlen(map[0]);
// 	data->maxj = ft_strlenj(map);
// 	while (map[j])
// 	{
// 		if (map[0][i] != '1' || map[j][0] != '1' || map[j][maxi - 2] != '1'
// 			|| map[data->maxj - 1][i] != '1')
// 			return (0);
// 		i++;
// 		if (map[j][i] == '\n' || map[j][i] == 0)
// 		{
// 			j++;
// 			i = 0;
// 		}
// 	}
// 	return (1);
// }

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
		data->NO = ft_calloc(len+1, sizeof(char));
	if (type[0] == 'S' && type[1] == 'O')
		data->SO = ft_calloc(len +1, sizeof(char));
	if (type[0] == 'W' && type[1] == 'E')
		data->WE = ft_calloc(len +1, sizeof(char));
	if (type[0] == 'E' && type[1] == 'A')
		data->EA = ft_calloc(len +1, sizeof(char));
	if (type[0] == 'F')
		data->F = ft_calloc(len +1, sizeof(char));
	if (type[0] == 'C')
		data->C = ft_calloc(len +1, sizeof(char));
}

void	type_path(char *type, int len)
{
	if (type[0] == 'N' && type[1] == 'O')
		calloc_path("NO", len);
	if (type[0] == 'S' && type[1] == 'O')
		calloc_path("SO", len);
	if (type[0] == 'W' && type[1] == 'E')
		calloc_path("WE", len);
	if (type[0] == 'E' && type[1] == 'A')
		calloc_path("EA", len);
	if (type[0] == 'F' )
		calloc_path("F", len);
	if (type[0] == 'C' )
		calloc_path("C", len);
}

void	extract_texture(char **map, int j, int i, char *type)
{
	t_data	*data;
	int		temp;
	int		len;

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
	type_path(type, len);
	i = temp;
	len = 0;

	// dequoi a regler ici
	
	
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

	else if (type[0] == 'F' )
	{
		while (map[j][i] != ' ' && map[j][i] != '\t' && map[j][i] != '\0'
		&& map[j][i] != '\n')
	{
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
		data->C[len] = map[j][i];
		len++;
		i++;
	}
	data->C[len] = '\0';
	}
	

	
	//
	// data->NO[len] = '\0';
	// printf("%s =%s\n", type, data->O);
}

void	chekup_and_extract_texture(char **map)
{
		t_data	*data;
	data = get_data();
	
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while ((map[j][i] == ' ' || map[j][i] == '\t') && map[j][i] != '\n'
			&& map[j][i] != '\0')
		{
			i++;
		}
		if (map[j][i] == 'N' && map[j][i + 1] == 'O' && map[j][i + 2] == ' ')
			extract_texture(map, j, i, "NO");
		else if (map[j][i] == 'S' && map[j][i + 1] == 'O' && map[j][i + 2] == ' ')
			extract_texture(map, j, i, "SO");
		else if (map[j][i] == 'W' && map[j][i + 1] == 'E' && map[j][i + 2] == ' ')
			extract_texture(map, j, i, "WE");
		else if (map[j][i] == 'E' && map[j][i + 1] == 'A' && map[j][i + 2] == ' ')
			extract_texture(map, j, i, "EA");
		else if (map[j][i] == 'F' && map[j][i + 1] == ' ')
			extract_texture(map, j, i, "F");
		else if (map[j][i] == 'C' && map[j][i + 1] == ' ')
			extract_texture(map, j, i, "C");
		i = 0;
		j++;
	}
	 

}
void extract_rgb(void)
{
	t_data	*data;
	data = get_data();
	int i;
	i = 0;
	int j;
	j = 0;
	int rgb;
	rgb = 0;
	char *temp;
	
	temp = malloc(sizeof(char)*4);
	while(data->F[i])
	{	
		while(data->F[i] != ',' && data->F[i])
		{
			temp[j] = data->F[i]; 
			i++;
			j++;
		}
		rgb++;
		if(rgb == 1 )
		{
			temp[j] = '\0';
			
			data->F_R = ft_atoi(temp);
		}
		if(rgb == 2 )
		{
			temp[j] = '\0';
			data->F_G = ft_atoi(temp);
		}
		if(rgb == 3)
		{
			temp[j] = '\0';
			data->F_B = ft_atoi(temp);
		}
		j = 0;
		i++;
	}
	
	i = 0;
	j = 0;
	rgb = 0;
	
	while(data->C[i])
	{	
		while(data->C[i] != ',' && data->C[i])
		{
			temp[j] = data->C[i]; 
			i++;
			j++;
		}
		rgb++;
		if(rgb == 1 )
		{
			temp[j] = '\0';
			
			data->C_R = ft_atoi(temp);
		}
		if(rgb == 2 )
		{
			temp[j] = '\0';
			data->C_G = ft_atoi(temp);
		}
		if(rgb == 3)
		{
			temp[j] = '\0';
			data->C_B = ft_atoi(temp);
		}
		j = 0;
		i++;
	}
	free(temp);
	
}

int chekup_F_and_C(void)
{
	t_data *data;
	data = get_data();
	if(!data->F || !data->C)
	return 0;
	if(ft_strncmp(data->F, data->C) == 0)
	return (0);

	return(1);
}

int	ft_mapchekup(char **map)
{
	chekup_and_extract_texture(map);
	if(chekup_F_and_C() == 0)
	{
		write(2, "Error\nF or C\n", 14);
		return 0;
	}
	
	extract_rgb();
	
	// if (chekup_mapsize(map) == 0)
	// 	return (0);
	// if (chekup_contour(map) == 0)
	// {
	// 	write(1, "Error\ncontour\n", 14);
	// 	return (0);
	// // }
	// if (chekup_character(map) == 0)
	// {
	// 	write(1, "Error\ncharacter\n", 16);
	// 	return (0);
	// }
	// if (contchar(map, 0) == 0)
	// {
	// 	write(1, " Error\ncontchar\n", 16);
	// 	return (0);
	// }
	// if (flood_fill_main(map, 0, 0) == 0)
	// {
	// 	write(1, "Error\nmap impossible\n", 21);
	// 	return (0);
	// }
	// found_exit(map);
	return (1);
}
