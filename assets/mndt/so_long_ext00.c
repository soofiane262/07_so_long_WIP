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
			"img/collec.xpm", &all->img->collec_w, &all->img->collec_h);
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
		temp = ft_strjoin("./img/wall/wall_", itoa);
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
	all->param->exit_ptr[0] = mlx_xpm_file_to_image(all->param->mlx_ptr,
			"./img/exit/exit_0.xpm", &all->img->exit_w, &all->img->exit_h);
	all->param->exit_ptr[1] = mlx_xpm_file_to_image(all->param->mlx_ptr,
			"./img/exit/exit_49.xpm", &all->img->exit_w, &all->img->exit_h);
}
