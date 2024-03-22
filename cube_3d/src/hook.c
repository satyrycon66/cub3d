/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:31:42 by siroulea          #+#    #+#             */
/*   Updated: 2024/03/08 14:55:34 by siroulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	asset_move_w(void *param)
{
	t_data	*data;

	data = param;
	data->movement++;
	print_mouvement();
	if (data->map[data->playerj - 1][data->playeri] == 'C')
	{
		data->nc--;
		mlx_delete_image(data->mlx, data->collectible_img);
		data->collectible_img = mlx_texture_to_image(data->mlx,
				data->collectible);
	}
	if (data->nc == 0 && data->playerj - 1 == data->exit_j
		&& data->playeri == data->exit_i)
	{
		write(1, "finish\n", 7);
		mlx_close_window(data->mlx);
		exit(0);
	}
	data->map[data->playerj - 1][data->playeri] = 'P';
	data->map[data->playerj][data->playeri] = '0';
}

void	asset_move_a(void *param)
{
	t_data	*data;

	data = param;
	data->movement++;
	print_mouvement();
	if (data->map[data->playerj][data->playeri - 1] == 'C')
	{
		data->nc--;
		mlx_delete_image(data->mlx, data->collectible_img);
		data->collectible_img = mlx_texture_to_image(data->mlx,
				data->collectible);
	}
	if (data->nc == 0 && data->playerj == data->exit_j && data->playeri
		- 1 == data->exit_i)
	{
		write(1, "finish\n", 7);
		mlx_close_window(data->mlx);
		exit(0);
	}
	data->map[data->playerj][data->playeri - 1] = 'P';
	data->map[data->playerj][data->playeri] = '0';
}

void	asset_move_s(void *param)
{
	t_data	*data;

	data = param;
	data->movement++;
	print_mouvement();
	if (data->map[data->playerj + 1][data->playeri] == 'C')
	{
		data->nc--;
		mlx_delete_image(data->mlx, data->collectible_img);
		data->collectible_img = mlx_texture_to_image(data->mlx,
				data->collectible);
	}
	if (data->nc == 0 && data->playerj + 1 == data->exit_j
		&& data->playeri == data->exit_i)
	{
		write(1, "finish\n", 7);
		mlx_close_window(data->mlx);
		exit(0);
	}
	data->map[data->playerj + 1][data->playeri] = 'P';
	data->map[data->playerj][data->playeri] = '0';
}

void	asset_move_d(void *param)
{
	t_data	*data;

	data = param;
	data->movement++;
	print_mouvement();
	if (data->map[data->playerj][data->playeri + 1] == 'C')
	{
		data->nc--;
		mlx_delete_image(data->mlx, data->collectible_img);
		data->collectible_img = mlx_texture_to_image(data->mlx,
				data->collectible);
	}
	if (data->nc == 0 && data->playerj == data->exit_j && data->playeri
		+ 1 == data->exit_i)
	{
		write(1, "finish\n", 7);
		mlx_close_window(data->mlx);
		exit(0);
	}
	data->map[data->playerj][data->playeri + 1] = 'P';
	data->map[data->playerj][data->playeri] = '0';
}

void	hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			&& data->map[data->playerj - 1][data->playeri] != '1')
			asset_move_w(param);
		else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			&& data->map[data->playerj][data->playeri - 1] != '1')
			asset_move_a(param);
		else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			&& data->map[data->playerj + 1][data->playeri] != '1')
			asset_move_s(param);
		else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			&& data->map[data->playerj][data->playeri + 1] != '1')
			asset_move_d(param);
		else if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
		// found_p(data->map, &data->playerj, &data->playeri);
		delete_image();
		texture_to_image();
		print_map();
	}
}
