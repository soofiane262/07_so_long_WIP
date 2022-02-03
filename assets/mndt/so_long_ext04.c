/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext04.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:36:36 by sel-mars          #+#    #+#             */
/*   Updated: 2022/01/16 23:36:38 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win_ext(t_all *all)
{
	char	*moves;

	moves = ft_itoa(all->map->moves);
	if (!moves)
		ft_map_error(&all->map->map, -2, "Allocation error in ft_itoa");
	if (all->map->moves < 10)
		mlx_string_put(all->param->mlx_ptr, all->param->win_ptr,
			all->map->width / 2 + 60, all->map->height / 2 + 7,
			0xFFFFFF, moves);
	else if (all->map->moves >= 10 && all->map->moves < 100)
		mlx_string_put(all->param->mlx_ptr, all->param->win_ptr,
			all->map->width / 2 + 55, all->map->height / 2 + 7,
			0xFFFFFF, moves);
	else if (all->map->moves >= 100)
		mlx_string_put(all->param->mlx_ptr, all->param->win_ptr,
			all->map->width / 2 + 52, all->map->height / 2 + 7,
			0xFFFFFF, moves);
	free(moves);
	moves = NULL;
}

void	ft_win(t_all *all)
{
	mlx_clear_window(all->param->mlx_ptr, all->param->win_ptr);
	mlx_string_put(all->param->mlx_ptr, all->param->win_ptr,
		all->map->width / 2 - 30, all->map->height / 2 - 7,
		0xFFFFFF, "You Won !");
	mlx_string_put(all->param->mlx_ptr, all->param->win_ptr,
		all->map->width / 2 - 130, all->map->height / 2 + 7,
		0xFFFFFF, "You completed the game in");
	ft_win_ext(all);
	mlx_string_put(all->param->mlx_ptr, all->param->win_ptr,
		all->map->width / 2 + 80, all->map->height / 2 + 7, 0xFFFFFF, "moves.");
	mlx_hook(all->param->win_ptr, 2, 0, ft_destroy_key_hook, all);
}

void	ft_lose(t_all *all)
{
	mlx_clear_window(all->param->mlx_ptr, all->param->win_ptr);
	mlx_string_put(all->param->mlx_ptr, all->param->win_ptr,
		all->map->width / 2 - 35, all->map->height / 2 - 15,
		0xFFFFFF, "Game Over !");
	mlx_hook(all->param->win_ptr, 2, 0, ft_destroy_key_hook, all);
}

int	ft_destroy_key_hook(int key, t_all *all)
{
	(void)key;
	mlx_clear_window(all->param->mlx_ptr, all->param->win_ptr);
	mlx_destroy_window(all->param->mlx_ptr, all->param->win_ptr);
	ft_free_map(all->map->map);
	exit(0);
	return (0);
}

int	ft_destroy_x(t_all *all)
{
	mlx_clear_window(all->param->mlx_ptr, all->param->win_ptr);
	mlx_destroy_window(all->param->mlx_ptr, all->param->win_ptr);
	ft_free_map(all->map->map);
	exit(0);
	return (0);
}
