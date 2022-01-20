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

int	ft_key_hook(int key, t_all *all)
{
	if (key == 53)
	{
		mlx_clear_window(all->param->mlx_ptr, all->param->win_ptr);
		mlx_destroy_window(all->param->mlx_ptr, all->param->win_ptr);
		ft_free_map(all->map->map);
		exit(0);
	}
	else if (key == 1)
	{
		mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr, all->param->laika_ptr, all->map->width / 2, all->map->height / 2);
	}


ft_putstr_fd("key	: ", 1);
ft_putnbr_fd(key, 1);
ft_putstr_fd("\n", 1);


	return (0);
}

int	ft_destroy_x(t_all *all)
{
	mlx_clear_window(all->param->mlx_ptr, all->param->win_ptr);
	mlx_destroy_window(all->param->mlx_ptr, all->param->win_ptr);
	ft_free_map(all->map->map);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	// int			x[2];
	// int			y[2];
	// int			l[2];
	t_all		all;
	t_params	param;
	t_img		img;
	t_map		map;

	if (ac != 2 || !ft_strnstr(av[1], ".ber", ft_strlen(av[1]))
		|| ft_strncmp(ft_strnstr(av[1], ".ber", ft_strlen(av[1])), ".ber", 5))
		ft_error();
	ft_check_map(&map, av[1]);
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, map.width, map.height, "so_long");
	param.font_ptr = mlx_xpm_file_to_image(param.mlx_ptr, "font.xpm", &img.font_w, &img.font_h);
	param.laika_ptr = mlx_xpm_file_to_image(param.mlx_ptr, "laika.xpm", &img.laika_w, &img.laika_h);
	all.param = &param;
	all.map = &map;
	all.img = &img;
	mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, param.font_ptr, map.width / 2 - img.font_w / 2, map.height / 2 - img.font_h / 2);
	mlx_hook(param.win_ptr, 2, 0, ft_key_hook, &all);
	mlx_hook(param.win_ptr, 17, 0, ft_destroy_x, &all);



// x[0] = 201;
// y[0] = 199;
// l[0] = 2;
// while (x[0] <= 250)
// {
// 	x[1] = x[0];
// 	y[1] = y[0];
// 	l[1] = l[0];
// 	while (l[1]-- >= 0)
// 		mlx_pixel_put(param.mlx_ptr, param.win_ptr, x[1], y[1]++, 0xFFFFFF);
// 	x[0]++;
// 	y[0]--;
// 	l[0] += 2;
// }


	// mlx_mouse_hook(param.win_ptr, ft_mouse_hook, &param);
	mlx_loop(param.mlx_ptr);
	return (0);
}
