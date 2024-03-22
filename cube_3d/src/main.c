/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:51:01 by siroulea          #+#    #+#             */
/*   Updated: 2024/03/22 15:54:55 by siroulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (!data)
	{
		data = ft_calloc(1, sizeof(t_data));
		return (data);
	}
	return (data);
}

void	free_map(char **map)
{
	int	j;

	j = 0;
	while (j != ft_strlenj(map))
	{
		free(map[j]);
		map[j] = NULL;
		j++;
	}
	return ;
}

void	print_background_image(int j, int i)
{
	t_data	*data;

	data = get_data();
	if (data->map[j][i] == '1')
		mlx_image_to_window(data->mlx, data->ground_img, i * 64, j * 64);
	else if (data->map[j][i] == 'N')
		mlx_image_to_window(data->mlx, data->ground_img, i * 64, j * 64);
	// else if (data->map[j][i] == 'C')
	// 	mlx_image_to_window(data->mlx, data->ground_img, i * 64, j * 64);
	// else if (data->map[j][i] == 'E')
	// 	mlx_image_to_window(data->mlx, data->ground_img, i * 64, j * 64);
	else if (data->map[j][i] == '0')
		mlx_image_to_window(data->mlx, data->ground_img, i * 64, j * 64);
}

void	print_background_map(void)
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
			print_background_image(j, i);
			i++;
		}
		j++;
		i = 0;
	}
}

int32_t	main(int argc, char **argv)
{
	t_data	*data;

	data = get_data();
	if (argc != 2)
	{
		write(1, "Error\nwrong argc\n", 17);
		return (0);
	}
	if (chekup_cub(argv[1]) == 0)
		return (0);
	extract_map(argv[1], 0, 0);

	if (ft_mapchekup(data->map) == 0)
		return (0);
		
	// data->mlx = mlx_init((ft_strlen(data->map[0]) -1) * 64,
	// 		ft_strlenj(data->map) * 64, "so_long", false);
	// if (!data->mlx)
	// 	exit(EXIT_FAILURE);
	// put_image();
	// mlx_key_hook(data->mlx, &hook, data);
	// mlx_loop(data->mlx);
	// mlx_terminate(data->mlx);
		 printf("NO =%s\n", data->NO);
	  printf("SO =%s\n", data->SO);
	   printf("WE =%s\n",  data->WE);
	    printf("EA =%s\n",  data->EA);
	 printf("F =%s\n",  data->F);
	printf("C =%s\n",  data->C);
	printf("%d\n",data->F_R);
	printf("%d\n",data->F_G);
	printf("%d\n",data->F_B);
	printf("%d\n",data->C_R);
	printf("%d\n",data->C_G);
	printf("%d\n",data->C_B);
	write(1,"succes",6);
	return (EXIT_SUCCESS);
}
