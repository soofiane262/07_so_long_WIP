/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext07.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:07:50 by sel-mars          #+#    #+#             */
/*   Updated: 2022/02/03 19:07:52 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
					all->param->win_ptr, all->param->exit_ptr[1],
					75 * i[0] + 8, 75 * i[1]);
		}
	}
}

int	ft_put_exit(t_all *all)
{
	if (all->map->collec)
		ft_put_exit_closed(all);
	else
		ft_put_exit_open(all);
	return (0);
}
