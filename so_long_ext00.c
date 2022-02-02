/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:36:36 by sel-mars          #+#    #+#             */
/*   Updated: 2022/01/16 23:36:38 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_collec(t_all *all)
{
	int	i[2];

	if (all->map->map[all->map->pos[1]][all->map->pos[0]] == 'C')
		all->map->map[all->map->pos[1]][all->map->pos[0]] = '0';
	all->map->collec = 0;
	all->param->collec_ptr = mlx_xpm_file_to_image(all->param->mlx_ptr,
			"collec.xpm", &all->img->collec_w, &all->img->collec_h);
	i[1] = 0;
	while (all->map->map[++i[1]])
	{
		i[0] = 0;
		while (all->map->map[i[1]][++i[0]])
		{
			if (all->map->map[i[1]][i[0]] == 'C')
			{
				mlx_put_image_to_window(all->param->mlx_ptr,
					all->param->win_ptr, all->param->collec_ptr,
					75 * i[0], 75 * i[1]);
				all->map->collec++;
			}
		}
	}
}

void	ft_put_ennemy(t_all *all)
{
	int	i[2];

	all->param->ennemy_ptr = mlx_xpm_file_to_image(all->param->mlx_ptr,
			"ennemy.xpm", &all->img->ennemy_w, &all->img->ennemy_h);
	i[1] = 0;
	while (all->map->map[++i[1]])
	{
		i[0] = 0;
		while (all->map->map[i[1]][++i[0]])
		{
			if (all->map->map[i[1]][i[0]] == 'N')
			{
				mlx_put_image_to_window(all->param->mlx_ptr,
					all->param->win_ptr, all->param->ennemy_ptr,
					75 * i[0], 75 * i[1]);
			}
		}
	}
}

void	ft_put_outer_walls(t_all *all)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	while (++i[0] < all->map->width / 75 - 1)
	{
		mlx_put_image_to_window(all->param->mlx_ptr,
			all->param->win_ptr, all->param->walls_ptr[i[1]++],
			75 * i[0], 0);
		if (i[1] == 4)
			i[1] = 0;
	}
	i[0] = 0;
	i[1] = 4;
	while (++i[0] < all->map->height / 75 - 1)
	{
		mlx_put_image_to_window(all->param->mlx_ptr,
			all->param->win_ptr, all->param->walls_ptr[i[1]++],
			all->map->width - 75, 75 * i[0]);
		if (i[1] == 8)
			i[1] = 4;
	}
	i[0] = 0;
	i[1] = 8;
	while (++i[0] < all->map->width / 75 - 1)
	{
		mlx_put_image_to_window(all->param->mlx_ptr,
			all->param->win_ptr, all->param->walls_ptr[i[1]++],
			75 * i[0], all->map->height - 75);
		if (i[1] == 12)
			i[1] = 8;
	}
	i[0] = 0;
	i[1] = 12;
	while (++i[0] < all->map->height / 75 - 1)
	{
		mlx_put_image_to_window(all->param->mlx_ptr,
			all->param->win_ptr, all->param->walls_ptr[i[1]++],
			0, 75 * i[0]);
		if (i[1] == 16)
			i[1] = 12;
	}
	// mlx_put_image_to_window(all->param->mlx_ptr,
	// 	all->param->win_ptr, all->param->walls_ptr[16],
	// 	0, 0);
	mlx_put_image_to_window(all->param->mlx_ptr,
		all->param->win_ptr, all->param->walls_ptr[17],
		all->map->width - 75, 0);
	mlx_put_image_to_window(all->param->mlx_ptr,
		all->param->win_ptr, all->param->walls_ptr[18],
		all->map->width - 75, all->map->height - 75);
	mlx_put_image_to_window(all->param->mlx_ptr,
		all->param->win_ptr, all->param->walls_ptr[19],
		0, all->map->height - 75);
}

void	ft_put_font_walls(t_all *all)
{
	int	i[2];

	i[1] = 0;
	while (++i[1] < all->map->height / 75 - 1)
	{
		i[0] = 0;
		while (++i[0] < all->map->width / 75 - 1)
				mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
					all->param->font_ptr, 75 * i[0], 75 * i[1]);
	}
	i[1] = 0;
	while (++i[1] < all->map->height / 75 - 1)
	{
		i[0] = 0;
		while (++i[0] < all->map->width / 75 - 1)
			if (all->map->map[i[1]][i[0]] == '1')
				mlx_put_image_to_window(all->param->mlx_ptr,
					all->param->win_ptr, all->param->walls_ptr[20],
					75 * i[0], 75 * i[1]);
	}
}

void	ft_put_exit_closed(t_all *all)
{
	int	i[2];

	i[1] = 0;
	while (all->map->map[++i[1]])
	{
		i[0] = 0;
		while (all->map->map[i[1]][++i[0]])
		{
			if (all->map->map[i[1]][i[0]] == 'E')
				mlx_put_image_to_window(all->param->mlx_ptr,
					all->param->win_ptr, all->param->exit_ptr[0],
					75 * i[0], 75 * i[1]);
		}
	}
}

void	ft_put_exit_open(t_all *all)
{
	int	i[2];

	i[1] = 0;
	while (all->map->map[++i[1]])
	{
		i[0] = 0;
		while (all->map->map[i[1]][++i[0]])
		{
			if (all->map->map[i[1]][i[0]] == 'E')
				mlx_put_image_to_window(all->param->mlx_ptr,
					all->param->win_ptr, all->param->exit_ptr[5],
					75 * i[0], 75 * i[1]);
		}
	}
}

int	ft_put_exit_sprite_1(t_exit_sprite *exit_sprite)
{
	if (exit_sprite->map->collec > 0)
	{
		mlx_put_image_to_window(exit_sprite->param->mlx_ptr,
			exit_sprite->param->win_ptr, exit_sprite->param->exit_ptr[0],
			0, 0);
		return (0);
	}
	exit_sprite->exit_counter++;
	if (exit_sprite->exit_counter <= 50)
		ft_put_exit_sprite_2(exit_sprite->param, exit_sprite->i, exit_sprite->j, exit_sprite->exit_counter);
	return (0);
}

void	ft_put_exit_sprite_2(t_params *param, int i, int j, int exit_counter)
{
	if (exit_counter >= 0)
		mlx_put_image_to_window(param->mlx_ptr,
			param->win_ptr, param->exit_ptr[1],
			75 * i, 75 * j);
	if (exit_counter >= 10)
		mlx_put_image_to_window(param->mlx_ptr,
			param->win_ptr, param->exit_ptr[2],
			75 * i, 75 * j);
	if (exit_counter >= 20)		
		mlx_put_image_to_window(param->mlx_ptr,
			param->win_ptr, param->exit_ptr[3],
			75 * i, 75 * j);
	if (exit_counter >= 30)
		mlx_put_image_to_window(param->mlx_ptr,
			param->win_ptr, param->exit_ptr[4],
			75 * i, 75 * j);
	if (exit_counter >= 40)
		mlx_put_image_to_window(param->mlx_ptr,
			param->win_ptr, param->exit_ptr[5],
			75 * i, 75 * j);
}

// void	ft_put_exit_sprite(t_all *all)
// {
// 	// int				i[2];
// 	t_exit_sprite	exit_sprite;

// 	// i[1] = 0;
// 	exit_sprite.all = all;
// 	exit_sprite.exit_counter = 0;
// 	// while (all->map->map[++i[1]])
// 	// {
// 	// 	i[0] = 0;
// 	// 	while (all->map->map[i[1]][++i[0]])
// 	// 	{
// 	// 		if (all->map->map[i[1]][i[0]] == 'E')
// 	// 		{
// 				exit_sprite.i = 0;
// 				exit_sprite.j = 0;
// 				mlx_loop_hook(all->param->mlx_ptr, &ft_put_exit_sprite_1, &exit_sprite);
// 	// 		}
// 	// 	}
// 	// }
// 	all->map->collec = -1;
// }
