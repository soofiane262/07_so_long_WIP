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

void	ft_check_mlx_imgs(t_all *all)
{
	int	i;

	if (!all->param->font_ptr || !all->param->collec_ptr
		|| !all->param->player_r_ptr || !all->param->player_l_ptr
		|| !all->param->exit_ptr[0] || !all->param->exit_ptr[1])
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("The mlx failed to make an image pointer", 2);
		ft_destroy_x(all);
	}
	i = -1;
	while (++i <= 20)
	{
		if (!all->param->walls_ptr[i])
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("The mlx failed to make an image pointer", 2);
			ft_destroy_x(all);
		}
	}
}

void	ft_make_ptrs(t_all *all)
{
	all->param->mlx_ptr = mlx_init();
	if (!all->param->mlx_ptr)
		ft_map_error(&all->map->map, -2,
			"The mlx failed to set up the connection to the graphical system",
			1);
	all->param->win_ptr = mlx_new_window(all->param->mlx_ptr, all->map->width,
			all->map->height, "so_long");
	if (!all->param->win_ptr)
		ft_map_error(&all->map->map, -2,
			"The mlx failed to create a new window", 1);
	all->param->font_ptr = mlx_xpm_file_to_image(all->param->mlx_ptr,
			"img/font.xpm", &all->img->font_w, &all->img->font_h);
	ft_make_walls(all);
	ft_make_exits(all);
	ft_make_player(all);
	ft_check_mlx_imgs(all);
}

int	ft_put_all(t_all *all)
{
	mlx_clear_window(all->param->mlx_ptr, all->param->win_ptr);
	ft_put_outer_walls(all);
	ft_put_font_walls(all);
	ft_put_collec(all);
	ft_put_exit(all);
	ft_put_player(all);
	ft_putmoves(all);
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
	ft_init(&all);
	ft_put_all(&all);
	mlx_hook(param.win_ptr, 2, 0, ft_key_hook, &all);
	mlx_hook(param.win_ptr, 17, 0, ft_destroy_x, &all);
	mlx_loop(param.mlx_ptr);
	return (0);
}
