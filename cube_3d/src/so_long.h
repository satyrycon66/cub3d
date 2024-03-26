/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:25:18 by siroulea          #+#    #+#             */
/*   Updated: 2024/03/26 12:44:57 by siroulea         ###   ########.fr       */
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
	int			y;
	int			x;

}				t_point;

typedef struct s_data
{
	char		**map;
	char		**real_map;
	int			playeri;
	int			playerj;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*F;
	char		*C;
	unsigned	C_R;
	unsigned	C_G;
	unsigned	C_B;
	unsigned	F_R;
	unsigned	F_G;
	unsigned	F_B;
	int			maxj;
	char		**area;
	char		*line;

	int			start_map;

}				t_data;

void			free_map(char **map);
int				chekup_character(char **map);
int				ft_mapchekup(char **map);
char			**make_area(char **zone, int _x);
int				flood_fill(char **tab, t_point size, t_point begin);
int				contchar(char **map, int np);
int				flood_fill_main(char **map, int i, int j);
char			*ft_strjoing(char *s1, char *s2);
char			*ft_freestash(char *stash);
char			*ft_get_line(char *stash);
char			*ft_read(int fd, char *stash);
char			*get_next_line(int fd);
int				ft_strlen(char *str);
int				ft_strlenj(char **str);
char			*ft_strchr(char *str, int c);
void			*ft_calloc(size_t nitems, size_t size);
void			*ft_free(char *str);
char			**extract_map(char *mapname, int i, int j);
int				chekup_cub(char *namemap);
int				found_player(char **map, int *npj, int *npi);
t_data			*get_data(void);
char			*ft_itoa(int n);
char			*ft_strjoin(char const *s1, char const *s2);
void			print_maptest(char **map);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2);
int				extract_rgb(void);
int				chekup_f_and_c(void);
int				chekup_rgb(void);
int				chekup_and_extract_texture(char **map);

#endif
