/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext03_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:36:36 by sel-mars          #+#    #+#             */
/*   Updated: 2022/01/16 23:36:38 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putmoves(t_all *all)
{
	char	*moves;

	moves = ft_itoa(all->map->moves);
	if (all->map->moves < 10)
		mlx_string_put(all->param->mlx_ptr, all->param->win_ptr,
			all->map->width / 2 - 2, 40,
			0xFFFFFF, moves);
	else if (all->map->moves >= 10 && all->map->moves < 100)
		mlx_string_put(all->param->mlx_ptr, all->param->win_ptr,
			all->map->width / 2 - 6, 40,
			0xFFFFFF, moves);
	else if (all->map->moves >= 100)
		mlx_string_put(all->param->mlx_ptr, all->param->win_ptr,
			all->map->width / 2 - 9, 40,
			0xFFFFFF, moves);
	mlx_string_put(all->param->mlx_ptr, all->param->win_ptr,
		all->map->width / 2 - 16, 58, 0xFFFFFF,
		"Moves");
	free(moves);
	moves = NULL;
}

void	ft_move_up(t_all *all)
{
	if (all->map->map[all->map->pos[1] - 1][all->map->pos[0]] == '1'
		|| (all->map->map[all->map->pos[1] - 1][all->map->pos[0]] == 'E'
		&& all->map->collec))
		return ;
	else if (all->map->map[all->map->pos[1] - 1][all->map->pos[0]] == 'N')
	{
		all->map->lose = 1;
		return ;
	}
	all->map->pos[1] -= 1;
	all->map->moves++;
	all->sprite->player_move[0] = 1;
	all->param->hook = 1;
}

void	ft_move_down(t_all *all)
{
	if (all->map->map[all->map->pos[1] + 1][all->map->pos[0]] == '1'
		|| (all->map->map[all->map->pos[1] + 1][all->map->pos[0]] == 'E'
		&& all->map->collec))
		return ;
	else if (all->map->map[all->map->pos[1] + 1][all->map->pos[0]] == 'N')
	{
		all->map->lose = 1;
		return ;
	}
	all->map->pos[1] += 1;
	all->map->moves++;
	all->sprite->player_move[2] = 1;
	all->param->hook = 1;
}

void	ft_move_left(t_all *all)
{
	if (all->map->map[all->map->pos[1]][all->map->pos[0] - 1] == '1'
		|| (all->map->map[all->map->pos[1]][all->map->pos[0] - 1] == 'E'
		&& all->map->collec))
		return ;
	else if (all->map->map[all->map->pos[1]][all->map->pos[0] - 1] == 'N')
	{
		all->map->lose = 1;
		return ;
	}
	all->map->pos[0] -= 1;
	all->map->moves++;
	all->param->player_d = -1;
	all->sprite->player_move[3] = 1;
	all->param->hook = 1;
}

void	ft_move_right(t_all *all)
{
	if (all->map->map[all->map->pos[1]][all->map->pos[0] + 1] == '1'
		|| (all->map->map[all->map->pos[1]][all->map->pos[0] + 1] == 'E'
		&& all->map->collec))
		return ;
	else if (all->map->map[all->map->pos[1]][all->map->pos[0] + 1] == 'N')
	{
		all->map->lose = 1;
		return ;
	}
	all->map->pos[0] += 1;
	all->map->moves++;
	all->param->player_d = 1;
	all->sprite->player_move[1] = 1;
	all->param->hook = 1;
}
