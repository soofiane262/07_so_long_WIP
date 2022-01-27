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

void	ft_exit_position(t_all *all)
{
	int	i[2];

	i[1] = 0;
	while (all->map->map[++i[1]])
	{
		i[0] = 0;
		while (all->map->map[i[1]][++i[0]])
		{
			if (all->map->map[i[1]][i[0]] == 'E')
			{
				all->map->exit[0] = i[0];
				all->map->exit[1] = i[1];
				return ;
			}
		}
	}
}

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
					75 * i[0] + 2, 75 * i[1] + 2);
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
					75 * i[0] + 2, 75 * i[1] + 2);
			}
		}
	}
}

void	ft_put_font_walls(t_all *all)
{
	int	i[2];

	mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
		all->param->font_ptr, all->map->width / 2 - all->img->font_w / 2,
		all->map->height / 2 - all->img->font_h / 2);
	i[1] = -1;
	while (all->map->map[++i[1]])
	{
		i[0] = -1;
		while (all->map->map[i[1]][++i[0]])
			if (all->map->map[i[1]][i[0]] == '1')
				mlx_put_image_to_window(all->param->mlx_ptr,
					all->param->win_ptr, all->param->walls_ptr,
					75 * i[0] + 2, 75 * i[1] + 2);
	}
}

void	ft_put_exit(t_all *all)
{
	int	i[2];

	i[1] = 0;
	while (all->map->map[++i[1]])
	{
		i[0] = 0;
		while (all->map->map[i[1]][++i[0]])
		{
			if (all->map->map[i[1]][i[0]] == 'E')
			{
				mlx_put_image_to_window(all->param->mlx_ptr,
					all->param->win_ptr, all->param->exit_ptr,
					75 * i[0] + 2, 75 * i[1] + 2);
				return ;
			}
		}
	}
}
