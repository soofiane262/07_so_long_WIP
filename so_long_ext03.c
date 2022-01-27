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
	char	*moves;

	moves = ft_itoa(all->map->moves);
	if (all->map->moves < 10)
		mlx_string_put(all->param->mlx_ptr, all->param->win_ptr, 34, 30,
			0x000000, moves);
	else if (all->map->moves >= 10 && all->map->moves < 100)
		mlx_string_put(all->param->mlx_ptr, all->param->win_ptr, 30, 30,
			0x000000, moves);
	else if (all->map->moves >= 100)
		mlx_string_put(all->param->mlx_ptr, all->param->win_ptr, 27, 30,
			0x000000, moves);
	mlx_string_put(all->param->mlx_ptr, all->param->win_ptr, 20, 48, 0x000000,
		"Moves");
	free(moves);
	moves = NULL;
}

void	ft_move_up(t_all *all)
{
	if (all->map->map[all->map->pos[1] - 1][all->map->pos[0]] == '1')
		return ;
	else if (all->map->map[all->map->pos[1] - 1][all->map->pos[0]] == 'N')
	{
		ft_lose(all);
		return ;
	}
	all->map->pos[1] -= 1;
	all->map->moves++;
	mlx_clear_window(all->param->mlx_ptr, all->param->win_ptr);
	ft_put_font_walls(all);
	ft_put_exit(all);
	ft_put_collec(all);
	ft_put_ennemy(all);
	if (all->param->player_d == 0)
		mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
			all->param->player_l_ptr, all->map->pos[0] * 75,
			all->map->pos[1] * 75);
	else
		mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
			all->param->player_r_ptr, all->map->pos[0] * 75,
			all->map->pos[1] * 75);
	ft_putmoves(all);
}

void	ft_move_down(t_all *all)
{
	if (all->map->map[all->map->pos[1] + 1][all->map->pos[0]] == '1')
		return ;
	else if (all->map->map[all->map->pos[1] + 1][all->map->pos[0]] == 'N')
	{
		ft_lose(all);
		return ;
	}
	all->map->pos[1] += 1;
	all->map->moves++;
	mlx_clear_window(all->param->mlx_ptr, all->param->win_ptr);
	ft_put_all(all);
	if (all->param->player_d == 0)
		mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
			all->param->player_l_ptr, all->map->pos[0] * 75,
			all->map->pos[1] * 75);
	else
		mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
			all->param->player_r_ptr, all->map->pos[0] * 75,
			all->map->pos[1] * 75);
	ft_putmoves(all);
}

void	ft_move_left(t_all *all)
{
	if (all->map->map[all->map->pos[1]][all->map->pos[0] - 1] == '1')
		return ;
	else if (all->map->map[all->map->pos[1]][all->map->pos[0] - 1] == 'N')
	{
		ft_lose(all);
		return ;
	}
	all->map->pos[0] -= 1;
	all->map->moves++;
	all->param->player_d = 0;
	mlx_clear_window(all->param->mlx_ptr, all->param->win_ptr);
	ft_put_all(all);
	mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
		all->param->player_l_ptr, all->map->pos[0] * 75, all->map->pos[1] * 75);
	ft_putmoves(all);
}

void	ft_move_right(t_all *all)
{
	if (all->map->map[all->map->pos[1]][all->map->pos[0] + 1] == '1')
		return ;
	else if (all->map->map[all->map->pos[1]][all->map->pos[0] + 1] == 'N')
	{
		ft_lose(all);
		return ;
	}
	all->map->pos[0] += 1;
	all->map->moves++;
	all->param->player_d = 1;
	mlx_clear_window(all->param->mlx_ptr, all->param->win_ptr);
	ft_put_all(all);
	mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
		all->param->player_r_ptr, all->map->pos[0] * 75, all->map->pos[1] * 75);
	ft_putmoves(all);
}
