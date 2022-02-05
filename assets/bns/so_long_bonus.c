/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:33:07 by sel-mars          #+#    #+#             */
/*   Updated: 2022/01/16 23:33:09 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_make_ptrs(t_all *all)
{
	all->param->mlx_ptr = mlx_init();
	all->param->win_ptr = mlx_new_window(all->param->mlx_ptr, all->map->width,
			all->map->height, "so_long_bonus");
	all->param->font_ptr = mlx_xpm_file_to_image(all->param->mlx_ptr,
			"img/font.xpm", &all->img->font_w, &all->img->font_h);
	ft_make_walls(all);
	ft_make_exits(all);
	ft_make_player_ur(all);
	ft_make_player_ul(all);
	ft_make_player_dr(all);
	ft_make_player_dl(all);
	ft_make_player_r(all);
	ft_make_player_l(all);
}

void	ft_put_everything(t_all *all)
{
	mlx_clear_window(all->param->mlx_ptr, all->param->win_ptr);
	ft_put_outer_walls(all);
	ft_put_font_walls(all);
	ft_put_ennemy(all);
	ft_put_collec(all);
	ft_put_exit(all);
	ft_putmoves(all);
}

int	ft_put_all(t_all *all)
{
	if (!all->param->hook)
		return (0);
	ft_put_everything(all);
	ft_put_player(all);
	if (!all->map->collec
		&& all->map->map[all->map->pos[1]][all->map->pos[0]] == 'E')
		ft_win(all);
	else if (all->map->lose)
		ft_lose(all);
	return (0);
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
	return (0);
}

int	main(int ac, char **av)
{
	t_all			all;
	t_params		param;
	t_img			img;
	t_map			map;
	t_sprite		sprite;

	if (ac != 2)
		ft_error("Invalid arguments number");
	else if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1]))
		|| ft_strncmp(ft_strnstr(av[1], ".ber", ft_strlen(av[1])), ".ber", 5))
		ft_error("Invalid map extension");
	all.param = &param;
	all.map = &map;
	all.img = &img;
	all.sprite = &sprite;
	ft_check_map(&map, av[1]);
	ft_make_ptrs(&all);
	ft_init(&all);
	ft_put_everything(&all);
	ft_put_player(&all);
	mlx_loop_hook(param.mlx_ptr, ft_put_all, &all);
	mlx_hook(param.win_ptr, 2, 0, ft_key_hook, &all);
	mlx_hook(param.win_ptr, 17, 0, ft_destroy_x, &all);
	mlx_loop(param.mlx_ptr);
	return (0);
}
