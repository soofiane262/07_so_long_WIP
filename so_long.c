/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:33:07 by sel-mars          #+#    #+#             */
/*   Updated: 2022/01/16 23:33:09 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_make_walls(t_all *all)
{
	int		i;
	char	*itoa;
	char	*temp;
	char	*path;

	i = 0;
	while (i <= 20)
	{
		itoa = ft_itoa(i);
		temp = ft_strjoin("wall_", itoa);
		path = ft_strjoin(temp, ".xpm");
		all->param->walls_ptr[i] = mlx_xpm_file_to_image(all->param->mlx_ptr,
				path, &all->img->walls_w, &all->img->walls_h);
		free(itoa);
		itoa = NULL;
		free(temp);
		temp = NULL;
		free(path);
		path = NULL;
		i++;
	}
}

void	ft_make_exits(t_all *all)
{
	int		i;
	char	*itoa;
	char	*temp;
	char	*path;

	i = 0;
	while (i <= 5)
	{
		itoa = ft_itoa(i);
		temp = ft_strjoin("./img/exit_", itoa);
		path = ft_strjoin(temp, ".xpm");
		all->param->exit_ptr[i] = mlx_xpm_file_to_image(all->param->mlx_ptr,
			path, &all->img->exit_w, &all->img->exit_h);
		free(itoa);
		itoa = NULL;
		free(temp);
		temp = NULL;
		free(path);
		path = NULL;
		i++;
	}
}

void	ft_make_ptrs(t_all *all)
{
	all->param->mlx_ptr = mlx_init();
	all->param->win_ptr = mlx_new_window(all->param->mlx_ptr, all->map->width,
			all->map->height, "so_long");
	all->param->font_ptr = mlx_xpm_file_to_image(all->param->mlx_ptr,
			"font.xpm", &all->img->font_w, &all->img->font_h);
	ft_make_walls(all);
	ft_make_exits(all);
	all->param->player_l_ptr = mlx_xpm_file_to_image(all->param->mlx_ptr,
			"player_l.xpm", &all->img->player_w, &all->img->player_h);
	all->param->player_r_ptr = mlx_xpm_file_to_image(all->param->mlx_ptr,
			"player_r.xpm", &all->img->player_w, &all->img->player_h);
}

void	ft_put_all(t_all *all)
{

	ft_put_outer_walls(all);
	ft_put_font_walls(all);
	ft_put_collec(all);
	ft_put_ennemy(all);
	// if (all->map->collec > 0)
	// 	ft_put_exit_closed(all);
	// else if (all->map->collec == 0)
	// 	ft_put_exit_sprite(all);
	// else
	// 	ft_put_exit_open(all);
}

int	ft_key_hook(int key, t_all *all)
{
	if (key == 53)
		ft_destroy_x(all);
	else if (key == 13)
		ft_move_up(all);
	else if (key == 1)
		ft_move_down(all);
	else if (key == 0)
		ft_move_left(all);
	else if (key == 2)
		ft_move_right(all);
	if (!all->map->collec
		&& all->map->map[all->map->pos[1]][all->map->pos[0]] == 'E')
		ft_win(all);
	// mlx_loop_hook(all->param->mlx_ptr, &ft_put_exit_sprite_1, &all->exit_sprite);
	return (0);
}

int	main(int ac, char **av)
{
	t_all			all;
	t_params		param;
	t_img			img;
	t_map			map;
	t_exit_sprite	exit_sprite;






	if (ac != 2)
		ft_error("Invalid arguments number");
	else if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1]))
		|| ft_strncmp(ft_strnstr(av[1], ".ber", ft_strlen(av[1])), ".ber", 5))
		ft_error("Invalid map extension");
	all.param = &param;
	all.map = &map;
	all.img = &img;
	all.exit_sprite = &exit_sprite;
	ft_check_map(&map, av[1]);
	ft_make_ptrs(&all);
	
	
	
	exit_sprite.map = &map;
	exit_sprite.param = &param;
	exit_sprite.i = 0;
	exit_sprite.j = 0;
	exit_sprite.exit_counter = 0;
	
	
	
	ft_put_all(&all);
	map.moves = 0;
	ft_putmoves(&all);
	mlx_put_image_to_window(param.mlx_ptr, param.win_ptr,
		param.player_l_ptr, map.pos[0] * 75, map.pos[1] * 75);

	mlx_loop_hook(param.mlx_ptr, &ft_put_exit_sprite_1, &exit_sprite);


	mlx_hook(param.win_ptr, 2, 0, ft_key_hook, &all);
	mlx_hook(param.win_ptr, 17, 0, ft_destroy_x, &all);
	// if (map.collec)
	// 	mlx_put_image_to_window(param.mlx_ptr,
	// 		param.win_ptr, param.exit_ptr[0],
	// 		0, 0);
	// else
	mlx_loop(param.mlx_ptr);
	return (0);
}
