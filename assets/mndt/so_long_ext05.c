/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext05.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:32:37 by sel-mars          #+#    #+#             */
/*   Updated: 2022/02/03 16:32:39 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_make_player(t_all *all)
{
	all->param->player_r_ptr = mlx_xpm_file_to_image(all->param->mlx_ptr,
			"./img/player/r/player_r_0.xpm",
			&all->img->player_w, &all->img->player_h);
	all->param->player_l_ptr = mlx_xpm_file_to_image(all->param->mlx_ptr,
			"./img/player/l/player_l_0.xpm",
			&all->img->player_w, &all->img->player_h);
}

void	ft_init_integers(int *i0, int *i1, int *i2, int *i3)
{
	*i0 = 0;
	*i1 = 0;
	*i2 = 0;
	*i3 = 0;
}

int	ft_put_player(t_all *all)
{
	if (all->param->player_d == 1)
		mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
			all->param->player_r_ptr,
			all->map->pos[0] * 75, all->map->pos[1] * 75);
	if (all->param->player_d == -1)
		mlx_put_image_to_window(all->param->mlx_ptr, all->param->win_ptr,
			all->param->player_l_ptr,
			all->map->pos[0] * 75, all->map->pos[1] * 75);
	return (0);
}

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
