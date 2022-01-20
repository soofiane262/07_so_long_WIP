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
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct	s_params
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*font_ptr;
	void	*laika_ptr;
}			t_params;
typedef struct	s_map
{
	char	**map;
	int		width;
	int		height;
}			t_map;
typedef struct	s_img
{
	int		font_w;
	int		font_h;
	int		laika_w;
	int		laika_h;
}			t_img;
typedef struct	s_all
{
	t_params	*param;
	t_img		*img;
	t_map		*map;
}			t_all;
int	ft_destroy_x(t_all *all);
int	ft_key_hook(int key, t_all *all);
void	ft_error(void);
void	ft_check_map(t_map *map, char *map_file);
void	ft_check_walls(char **map, int *len);
void	ft_check_chars(char **map, int *len);
char	**ft_make_map(char *map_file);
char	**ft_alloc_to_map(char **map, int size);
char	*ft_map_line_dup(char *temp);
void	ft_free_map(char **map);
void	ft_map_error(char **map, int map_fd);
void	ft_init_integers(int *i, int *j, int *k, int *l);
#endif
