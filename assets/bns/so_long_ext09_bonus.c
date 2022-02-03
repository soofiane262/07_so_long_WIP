/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext09_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:38:29 by sel-mars          #+#    #+#             */
/*   Updated: 2022/02/03 19:38:31 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_map_line_dup(char *temp)
{
	int		len;
	char	*ret;

	len = (int)ft_strlen(temp);
	if (temp[len - 1] == '\n')
		ret = ft_substr(temp, 0, len - 1);
	else
		ret = ft_strdup(temp);
	return (ret);
}

void	ft_put_player_up(t_all *all)
{
	all->sprite->player_counter++;
	if (all->sprite->player_counter <= 15)
		ft_put_player_sprite(all);
	else
	{
		all->sprite->player_counter = 0;
		all->sprite->player_move[0] = 0;
	}
}

void	ft_put_player_right(t_all *all)
{
	all->sprite->player_counter++;
	if (all->sprite->player_counter <= 17)
		ft_put_player_sprite(all);
	else
	{
		all->sprite->player_counter = 0;
		all->sprite->player_move[1] = 0;
	}
}

void	ft_put_player_down(t_all *all)
{
	all->sprite->player_counter++;
	if (all->sprite->player_counter <= 15)
		ft_put_player_sprite(all);
	else
	{
		all->sprite->player_counter = 0;
		all->sprite->player_move[2] = 0;
	}
}

void	ft_put_player_left(t_all *all)
{
	all->sprite->player_counter++;
	if (all->sprite->player_counter <= 17)
		ft_put_player_sprite(all);
	else
	{
		all->sprite->player_counter = 0;
		all->sprite->player_move[3] = 0;
	}
}
