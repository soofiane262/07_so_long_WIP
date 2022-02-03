/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext07_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:07:50 by sel-mars          #+#    #+#             */
/*   Updated: 2022/02/03 19:07:52 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_integers(int *i0, int *i1, int *i2, int *i3)
{
	*i0 = 0;
	*i1 = 0;
	*i2 = 0;
	*i3 = 0;
}

int	ft_put_player(t_all *all)
{
	if (!all->sprite->player_move[0] && !all->sprite->player_move[1]
		&& !all->sprite->player_move[2] && !all->sprite->player_move[3])
		ft_put_player_static(all);
	else if (all->sprite->player_move[0])
		ft_put_player_up(all);
	else if (all->sprite->player_move[1])
		ft_put_player_right(all);
	else if (all->sprite->player_move[2])
		ft_put_player_down(all);
	else if (all->sprite->player_move[3])
		ft_put_player_left(all);
	if (!all->map->collec
		&& all->map->map[all->map->pos[1]][all->map->pos[0]] == 'E')
		ft_win(all);
	else if (all->map->lose)
		ft_lose(all);
	return (0);
}

void	ft_put_player_static(t_all *all)
{
	if (all->param->player_d == 1)
		mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
			all->param->player_ur_ptr[0],
			all->map->pos[0] * 75, all->map->pos[1] * 75);
	if (all->param->player_d == -1)
		mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
			all->param->player_ul_ptr[0],
			all->map->pos[0] * 75, all->map->pos[1] * 75);
}

void	ft_put_player_sprite_ext(t_all *all, int i, int j)
{
	ft_put_everything(all);
	if (all->sprite->player_move[0] && all->param->player_d == 1)
		mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
			all->param->player_ur_ptr[i],
			all->map->pos[0] * 75, all->map->pos[1] * 75 + j);
	else if (all->sprite->player_move[0] && all->param->player_d == -1)
		mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
			all->param->player_ul_ptr[i],
			all->map->pos[0] * 75, all->map->pos[1] * 75 + j);
	else if (all->sprite->player_move[1])
		mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
			all->param->player_r_ptr[i],
			all->map->pos[0] * 75 - j, all->map->pos[1] * 75);
	else if (all->sprite->player_move[2] && all->param->player_d == 1)
		mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
			all->param->player_dr_ptr[i],
			all->map->pos[0] * 75, all->map->pos[1] * 75 - j);
	else if (all->sprite->player_move[2] && all->param->player_d == -1)
		mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
			all->param->player_dl_ptr[i],
			all->map->pos[0] * 75, all->map->pos[1] * 75 - j);
	else if (all->sprite->player_move[3])
		mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
			all->param->player_l_ptr[i],
			all->map->pos[0] * 75 + j, all->map->pos[1] * 75);
}

void	ft_put_player_sprite(t_all *all)
{
	if (all->sprite->player_counter >= 0)
		ft_put_player_sprite_ext(all, 0, 72);
	if (all->sprite->player_counter >= 2)
		ft_put_player_sprite_ext(all, 1, 63);
	if (all->sprite->player_counter >= 4)
		ft_put_player_sprite_ext(all, 2, 54);
	if (all->sprite->player_counter >= 6)
		ft_put_player_sprite_ext(all, 3, 45);
	if (all->sprite->player_counter >= 8)
		ft_put_player_sprite_ext(all, 4, 36);
	if (all->sprite->player_counter >= 10)
		ft_put_player_sprite_ext(all, 5, 27);
	if (all->sprite->player_counter >= 12)
		ft_put_player_sprite_ext(all, 6, 18);
	if (all->sprite->player_counter >= 14)
		ft_put_player_sprite_ext(all, 7, 9);
	if (all->sprite->player_counter >= 16)
		ft_put_player_sprite_ext(all, 0, 9);
}
