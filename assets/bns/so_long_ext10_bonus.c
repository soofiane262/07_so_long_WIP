/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext10_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:45:05 by sel-mars          #+#    #+#             */
/*   Updated: 2022/02/03 19:45:07 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_char_ext00(char c, int *i2, int *i3, int *i4)
{
	if (c == 'P')
		*i2 += 1;
	if (c == 'C')
		*i3 += 1;
	if (c == 'E')
		*i4 += 1;
}

void	ft_put_outer_walls_ext00(t_all *all)
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
}

void	ft_put_outer_walls_ext01(t_all *all)
{
	int	i[2];

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
}

void	ft_put_outer_walls_ext02(t_all *all)
{
	int	i[2];

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
}

void	ft_put_outer_walls_ext03(t_all *all)
{
	int	i[2];

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
}
