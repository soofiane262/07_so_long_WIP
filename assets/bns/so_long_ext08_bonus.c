/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext08_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:31:46 by sel-mars          #+#    #+#             */
/*   Updated: 2022/02/03 19:31:47 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
					75 * i[0] + 8, 75 * i[1]);
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
					all->param->win_ptr, all->param->exit_ptr[49],
					75 * i[0] + 8, 75 * i[1]);
		}
	}
}

int	ft_put_exit_1(t_all *all)
{
	if (all->sprite->map->collec > 0)
	{
		ft_put_exit_closed(all);
		return (0);
	}
	all->sprite->exit_counter++;
	if (all->sprite->exit_counter < 50)
		ft_put_exit_2(all->sprite->param, all->sprite->i,
			all->sprite->j, all->sprite->exit_counter);
	else
		ft_put_exit_open(all);
	return (0);
}

void	ft_put_exit_2(t_params *param, int i, int j, int exit_counter)
{
	mlx_put_image_to_window(param->mlx_ptr,
		param->win_ptr, param->exit_ptr[exit_counter],
		75 * i + 8, 75 * j);
}

int	ft_put_exit(t_all *all)
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
				all->sprite->i = i[0];
				all->sprite->j = i[1];
				ft_put_exit_1(all);
			}
		}
	}
	return (0);
}
