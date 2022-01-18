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

int	ft_key_hook(int key, t_params *param)
{
	if (key == 53)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		ft_free_map(param->map);
		exit(0);
	}
	// else if (key == )
	return (0);
}

int	ft_destroy_x(t_params *param)
{
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	ft_free_map(param->map);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	// int			x[2];
	// int			y[2];
	// int			l[2];
	t_params	param;

	if (ac != 2 || !ft_strnstr(av[1], ".ber", ft_strlen(av[1]))
		|| ft_strncmp(ft_strnstr(av[1], ".ber", ft_strlen(av[1])), ".ber", 5))
		ft_error();
	ft_check_map(&param, av[1]);
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, 500, 500, "so_long");
	// param.font_ptr = mlx_xpm_file_to_image(param.mlx_ptr, "font.xpm", );
	mlx_hook(param.win_ptr, 2, 0, ft_key_hook, &param);
	mlx_hook(param.win_ptr, 17, 0, ft_destroy_x, &param);



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
