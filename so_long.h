/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:33:03 by sel-mars          #+#    #+#             */
/*   Updated: 2022/01/16 23:33:04 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <time.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct s_params
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*font_ptr;
	void	*walls_ptr[21];
	void	*exit_ptr[6];
	void	*collec_ptr;
	void	*ennemy_ptr;
	void	*player_l_ptr;
	void	*player_r_ptr;
	int		player_d;
}			t_params;
typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		pos[2];
	int		collec;
	int		moves;
}			t_map;
typedef struct s_img
{
	int		font_w;
	int		font_h;
	int		player_w;
	int		player_h;
	int		walls_w;
	int		walls_h;
	int		exit_w;
	int		exit_h;
	int		collec_w;
	int		collec_h;
	int		ennemy_w;
	int		ennemy_h;
}			t_img;
typedef struct s_exit_sprite
{
	t_map		*map;
	t_params	*param;
	int			i;
	int			j;
	int			exit_counter;
}			t_exit_sprite;
typedef struct s_all
{
	t_params			*param;
	t_img				*img;
	t_map				*map;
	t_exit_sprite		*exit_sprite;
}			t_all;
void	ft_make_ptrs(t_all *all);
void	ft_make_walls(t_all *all);
void	ft_make_exits(t_all *all);
void	ft_put_all(t_all *all);
int		ft_destroy_key_hook(int key, t_all *all);
void	ft_win(t_all *all);
void	ft_win_ext(t_all *all);
void	ft_lose(t_all *all);
void	ft_putmoves(t_all *all);
void	ft_put_outer_walls(t_all *all);
void	ft_put_font_walls(t_all *all);
void	ft_put_exit_closed(t_all *all);
void	ft_put_exit_open(t_all *all);
// void	ft_put_exit_sprite(t_all *all);
int		ft_put_exit_sprite_1(t_exit_sprite *exit_sprite);
void	ft_put_exit_sprite_2(t_params *param, int i, int j, int exit_counter);
void	ft_put_collec(t_all *all);
void	ft_put_ennemy(t_all *all);
int		ft_destroy_x(t_all *all);
int		ft_key_hook(int key, t_all *all);
void	ft_move_up(t_all *all);
void	ft_move_down(t_all *all);
void	ft_move_left(t_all *all);
void	ft_move_right(t_all *all);
void	ft_delay(int t);
void	ft_error(char *str);
void	ft_check_map(t_map *map, char *map_file);
void	ft_check_walls(char **map, int *len);
void	ft_check_chars(char **map, int *len);
char	**ft_make_map(char *map_file);
char	**ft_alloc_to_map(char **map, int map_fd, int size);
char	*ft_map_line_dup(char *temp);
void	ft_free_map(char **map);
void	ft_map_error(char **map, int map_fd, char *error);
void	ft_init_integers(int *i, int *j, int *k, int *l);
#endif
