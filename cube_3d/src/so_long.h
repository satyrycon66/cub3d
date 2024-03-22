/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:25:18 by siroulea          #+#    #+#             */
/*   Updated: 2024/03/22 11:18:29 by siroulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# ifndef BONUS
#  define BONUS 0
# endif
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <limits.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_point
{
	int				y;
	int				x;

}					t_point;

typedef struct s_data
{
	mlx_t			*mlx;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			**map;
	int				playeri;
	int				playerj;
	int				nc;
	int				exit_j;
	int				exit_i;
	char 			*NO;
	char 			*SO;
	char			*WE;
	char			*EA;
	char 			*F;
	char 			*C;
	unsigned		C_R;
	unsigned		C_G;
	unsigned		C_B;
	unsigned		F_R;
	unsigned		F_G;
	unsigned		F_B;
	int				movement;
	int				maxj;
	char			**area;
	char			*line;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	mlx_texture_t	*ground;
	mlx_image_t		*wall_img;
	mlx_image_t		*player_img;
	mlx_image_t		*collectible_img;
	mlx_image_t		*exit_img;
	mlx_image_t		*ground_img;
	mlx_image_t		*print_move;

}					t_data;

// int					chekup_mapsize(char **map);
// int					chekup_contour(char **map);
int					chekup_character(char **map);
int					ft_mapchekup(char **map);
char				**make_area(char **zone, int _x, int _y);
int				flood_fill(char **tab, t_point size, t_point begin);
int					contchar(char **map, int np);
int					flood_fill_main(char **map, int i, int j);
char				*ft_strjoing(char *s1, char *s2);
char				*ft_freestash(char *stash);
char				*ft_get_line(char *stash);
char				*ft_read(int fd, char *stash);
char				*get_next_line(int fd);
int					ft_strlen(char *str);
int					ft_strlenj(char **str);
char				*ft_strchr(char *str, int c);
void				*ft_calloc(size_t nitems, size_t size);
void				*ft_free(char *str);
char				**extract_map(char *mapname, int i, int j);
int					chekup_cub(char *namemap);
int					found_player(char **map, int *npj, int *npi);
t_data				*get_data(void);
// void				found_exit(char **map);
void				hook(mlx_key_data_t keydata, void *param);
void				asset_move_d(void *param);
void				asset_move_s(void *param);
void				asset_move_a(void *param);
void				asset_move_w(void *param);
void				print_map(void);
void				put_image(void);
void				print_image(int j, int i);
void				texture_to_image(void);
void				asing_texture(void);
void				print_background_map(void);
void				print_background_image(int j, int i);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
void				print_mouvement(void);
void				delete_image(void);
void print_maptest(char **map );
int	ft_atoi(const char *str);
int	ft_strncmp(const char *s1, const char *s2);
#endif
