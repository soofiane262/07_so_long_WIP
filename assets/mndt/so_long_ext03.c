/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:36:36 by sel-mars          #+#    #+#             */
/*   Updated: 2022/01/16 23:36:38 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putmoves(t_all *all)
{
	ft_putstr_fd("Moves count	:	", 1);
	ft_putnbr_fd(all->map->moves, 1);
	ft_putstr_fd("\n", 1);
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
	ft_put_all(all);
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
	ft_put_all(all);
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
	ft_put_all(all);
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
	ft_put_all(all);
}
