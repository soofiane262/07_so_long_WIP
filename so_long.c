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

void	ft_make_ptrs(t_all *all)
{
	all->param->mlx_ptr = mlx_init();
	all->param->win_ptr = mlx_new_window(all->param->mlx_ptr, all->map->width,
			all->map->height, "so_long");
	all->param->font_ptr = mlx_xpm_file_to_image(all->param->mlx_ptr,
			"font.xpm", &all->img->font_w, &all->img->font_h);
	all->param->walls_ptr = mlx_xpm_file_to_image(all->param->mlx_ptr,
			"wall.xpm", &all->img->walls_w, &all->img->walls_h);
	all->param->exit_ptr = mlx_xpm_file_to_image(all->param->mlx_ptr,
			"exit.xpm", &all->img->exit_w, &all->img->exit_h);
	all->param->player_l_ptr = mlx_xpm_file_to_image(all->param->mlx_ptr,
			"player_l.xpm", &all->img->player_w, &all->img->player_h);
	all->param->player_r_ptr = mlx_xpm_file_to_image(all->param->mlx_ptr,
			"player_r.xpm", &all->img->player_w, &all->img->player_h);
}

void	ft_put_all(t_all *all)
{
	ft_put_font_walls(all);
	ft_put_exit(all);
	ft_put_collec(all);
	ft_put_ennemy(all);
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
	if (!all->map->collec && all->map->pos[0] == all->map->exit[0]
		&& all->map->pos[1] == all->map->exit[1])
		ft_win(all);
	return (0);
}

int	main(int ac, char **av)
{
	t_all		all;
	t_params	param;
	t_img		img;
	t_map		map;

	if (ac != 2)
		ft_error("Invalid arguments number");
	else if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1]))
		|| ft_strncmp(ft_strnstr(av[1], ".ber", ft_strlen(av[1])), ".ber", 5))
		ft_error("Invalid map extension");
	all.param = &param;
	all.map = &map;
	all.img = &img;
	ft_check_map(&map, av[1]);
	ft_make_ptrs(&all);
	ft_put_all(&all);
	ft_exit_position(&all);
	map.moves = 0;
	ft_putmoves(&all);
	mlx_put_image_to_window(param.mlx_ptr, param.win_ptr,
		param.player_l_ptr, map.pos[0] * 75, map.pos[1] * 75);
	mlx_hook(param.win_ptr, 2, 0, ft_key_hook, &all);
	mlx_hook(param.win_ptr, 17, 0, ft_destroy_x, &all);
	mlx_loop(param.mlx_ptr);
	return (0);
}
