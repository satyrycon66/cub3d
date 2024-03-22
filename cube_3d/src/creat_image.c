/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:41:10 by siroulea          #+#    #+#             */
/*   Updated: 2024/03/14 14:47:11 by siroulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	asing_texture(void)
{
	t_data	*data;

	data = get_data();
	data->wall = mlx_load_png("image/wall.png");
	data->player = mlx_load_png("image/player_swim_left_1.png");
	data->collectible = mlx_load_png("image/collectible.png");
	data->exit = mlx_load_png("image/exit.png");
	data->ground = mlx_load_png("image/ground.png");
}

void	texture_to_image(void)
{
	t_data	*data;

	data = get_data();
	data->wall_img = mlx_texture_to_image(data->mlx, data->wall);
	data->player_img = mlx_texture_to_image(data->mlx, data->player);
	data->collectible_img = mlx_texture_to_image(data->mlx, data->collectible);
	data->exit_img = mlx_texture_to_image(data->mlx, data->exit);
	data->ground_img = mlx_texture_to_image(data->mlx, data->ground);
}

void	print_image(int j, int i)
{
	t_data	*data;

	data = get_data();
	if (data->map[j][i] == '1')
		mlx_image_to_window(data->mlx, data->wall_img, i * 64, j * 64);
	else if (data->map[j][i] == 'W' || data->map[j][i] == 'S' || data->map[j][i] == 'E' || data->map[j][i] == 'W'  )
		mlx_image_to_window(data->mlx, data->player_img, i * 64, j * 64);
	// else if (data->map[j][i] == 'C')
	// 	mlx_image_to_window(data->mlx, data->collectible_img, i * 64, j * 64);
	// else if (data->map[j][i] == 'E')
	// 	mlx_image_to_window(data->mlx, data->exit_img, i * 64, j * 64);
}

void	print_map(void)
{
	t_data	*data;
	int		i;
	int		j;

	data = get_data();
	j = 0;
	i = 0;
	while (j < ft_strlenj(data->map))
	{
		while (i < ft_strlen(data->map[j]) - 1)
		{
			print_image(j, i);
			i++;
		}
		j++;
		i = 0;
	}
}

void	print_mouvement(void)
{
	t_data	*data;
	char	*str;
	char	*num;
	char	*res;

	data = get_data();
	if (!BONUS)
		printf("movement;%d\n", data->movement);
	else
	{
		str = "mouvement; ";
		num = ft_itoa(data->movement);
		res = ft_strjoin(str, num);
		mlx_delete_image(data->mlx, data->print_move);
		data->print_move = mlx_put_string(data->mlx, res, 70, 70);
		free(res);
		free(num);
		
	}
}
