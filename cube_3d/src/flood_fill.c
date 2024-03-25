/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:25:57 by siroulea          #+#    #+#             */
/*   Updated: 2024/03/25 17:30:52 by siroulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char	**make_area(char **zone, int _y)
{
	int		i;
	int		j;
	t_data	*data;

	data = get_data();
	i = 0;
	j = 0;
	data->area = (char **)calloc(sizeof(char *), _y+1);
	while (zone[j])
	{
		data->area[j] = (char *)calloc(sizeof(char), ft_strlen(zone[j]));
		while (zone[j][i])
		{
			data->area[j][i] = zone[j][i];
			++i;
		}
		++j;
		i = 0;
	}
	return (data->area);
}


int	flood_fill(char **tab, t_point size, t_point begin)
{
	char	c;

	c = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	
	// if(tab[begin.y][begin.x+1 ] != '1' &&  tab[begin.y][begin.x+1 ] != '0' && tab[begin.y][begin.x+1 ] != 'F')
	// return 0;
	// if(tab[begin.y+1][begin.x] != '1' &&  tab[begin.y+1][begin.x ] != '0' && tab[begin.y+1][begin.x ] != 'F')
	// return 0;
	begin.y++;
	
	if ((begin.y < size.y && tab[begin.y][begin.x] == c)
		|| tab[begin.y][begin.x] == '0' )
		{
	// 			if(tab[begin.y][begin.x ] != '1' ||  tab[begin.y][begin.x ] != '0' ||  tab[begin.y][begin.x ] != 'F')
	// return 0;
			flood_fill(tab, size, begin);
		}
		
	begin.y -= 2;
	if ((begin.y >= 0 && tab[begin.y][begin.x] == c)
		|| tab[begin.y][begin.x] == '0' )
		{
			// if (tab[begin.y-1][begin.x] != '0' && tab[begin.y-1][begin.x] != '1' && tab[begin.y-1][begin.x] != 'F')
			// return 0;
			flood_fill(tab, size, begin);
		}
	begin.y++;
	begin.x++;
	if ((begin.x < ft_strlen(tab[begin.y]) && tab[begin.y][begin.x] == c)
		|| tab[begin.y][begin.x] == '0')
		{
			// if (tab[begin.y][begin.x+1] != '0' && tab[begin.y][begin.x+1] != '1' && tab[begin.y][begin.x+1] != 'F')
			// return 0;
			flood_fill(tab, size, begin);
		}
	begin.x -= 2;
	if ((begin.x >= 0 && tab[begin.y][begin.x] == c)
		|| tab[begin.y][begin.x] == '0')
		{
			// if (tab[begin.y][begin.x-1] != '0' && tab[begin.y][begin.x-1] != '1' && tab[begin.y][begin.x-1] != 'F')
			// return 0;
			flood_fill(tab, size, begin);
		}
	
		
	return (1);
}


int	contchar(char **map,int np)
{
	int		i;
	int		j;
	t_data	*data;
	data = get_data();
	j = 0;
	i = 0;
	np = 0;

	while (map[++j])
	{
		while (map[j][i++])
		{
			if (map[j][i] == 'N')
				np++;
			else if (map[j][i] == 'S')
				np++;
			else if (map[j][i] == 'W')
				np++;
			else if (map[j][i] == 'E')
				np++;
		}
		i = 0;
	}
	if (np == 1)
		return (1);
	return (0);
}

int	chek_final(char **area)
{
	int		j;
	int		i;
	t_data	*data;

	data = get_data();
	j = 0;
	i = 0;
	while (j < data->maxj)
	{
		while (area[j][i] != '\0')
		{
			if (area[j][i] != 'F'  && area[j][i] != '1' && area[j][i] != ' ' && area[j][i] != '\t' && area[j][i] != '\n' && area[j][i] != '0')
				return (0);
			i++;
		}
		j++;
		i = 0;
	}
	return (1);
}
void print_maptest(char **map )
{

	int		j;
	int		i;
	
	j = 0;
	i = 0;
	while (map[j])
	{
		while (map[j][i] != '\0')
		{
			write(1,&map[j][i],1);
			i++;
		}
		j++;
		i = 0;
	}
	
}



	int	flood_fill_main(char **map, int i, int j)
{
	char	**area;
	t_point	size;
	t_point	begin;
	t_data	*data;

	data = get_data();
	found_player(data->real_map, &j, &i);
	size.y = ft_strlenj(map);
	begin.y = data->playerj;
	begin.x = data->playeri;
	area = make_area(map, size.y);
	
	
	if(flood_fill(area, size, begin) == 0)
	return 0;
	print_maptest(area);
	// if (chek_final(area) == 0)
	// 	return (0);
	return (1);
}



	
	// char	**area;
	// t_point	size;
	// t_point	begin;
	// t_data	*data;

	// data = get_data();
	// found_player(map, &j, &i);
	// size.x = ft_strlen(map[0]);
	
	// begin.y = j;
	// begin.x = i;
	// area = make_area(map, size.x);
	// // print_maptest(area );
	// flood_fill(area, size, begin);
	
	// // if (chek_final(area) == 0)
	// // 	return (0);
	// print_maptest(area );
	// return (1);



