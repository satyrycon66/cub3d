/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:51:01 by siroulea          #+#    #+#             */
/*   Updated: 2024/03/26 12:47:59 by siroulea         ###   ########.fr       */
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
	// mlx_terminate(data->mlx);
	printf("NO =%s\n", data->NO);
	printf("SO =%s\n", data->SO);
	printf("WE =%s\n", data->WE);
	printf("EA =%s\n", data->EA);
	printf("F =%s\n", data->F);
	printf("C =%s\n", data->C);
	printf("%d\n", data->F_R);
	printf("%d\n", data->F_G);
	printf("%d\n", data->F_B);
	printf("%d\n", data->C_R);
	printf("%d\n", data->C_G);
	printf("%d\n", data->C_B);
	print_maptest(data->real_map);
	ft_free(data->NO);
	ft_free(data->SO);
	ft_free(data->WE);
	ft_free(data->EA);
	ft_free(data->C);
	ft_free(data->F);
	// free_map(data->map);
	// free_map(data->area);
	// free_map(data->real_map);
	// free(data);
	write(1, "succes", 6);
	return (EXIT_SUCCESS);
}
