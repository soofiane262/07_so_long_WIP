/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext00_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:36:36 by sel-mars          #+#    #+#             */
/*   Updated: 2022/01/16 23:36:38 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_make_map_ext(char ***map, int *i, char **temp, int map_fd)
{
	(*map)[(*i)++] = ft_map_line_dup((*temp));
	(*map)[(*i)] = NULL;
	free((*temp));
	(*temp) = get_next_line(map_fd);
}

void	ft_put_collec(t_all *all)
{
	int	i[2];

	if (all->map->map[all->map->pos[1]][all->map->pos[0]] == 'C')
		all->map->map[all->map->pos[1]][all->map->pos[0]] = '0';
	all->map->collec = 0;
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
	ft_put_outer_walls_ext00(all);
	ft_put_outer_walls_ext01(all);
	ft_put_outer_walls_ext02(all);
	ft_put_outer_walls_ext03(all);
	mlx_put_image_to_window(all->param->mlx_ptr,
		all->param->win_ptr, all->param->walls_ptr[16],
		0, 0);
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
			mlx_put_image_to_window(all->param->mlx_ptr,
				all->param->win_ptr, all->param->font_ptr,
				75 * i[0], 75 * i[1]);
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
