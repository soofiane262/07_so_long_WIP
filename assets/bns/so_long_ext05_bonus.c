/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext05_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:32:37 by sel-mars          #+#    #+#             */
/*   Updated: 2022/02/03 16:32:39 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	int		i;
	char	*itoa;
	char	*temp;
	char	*path;

	i = 0;
	while (i < 50)
	{
		itoa = ft_itoa(i);
		temp = ft_strjoin("./img/exit/exit_", itoa);
		path = ft_strjoin(temp, ".xpm");
		all->param->exit_ptr[i] = mlx_xpm_file_to_image(all->param->mlx_ptr,
				path, &all->img->exit_w, &all->img->exit_h);
		free(itoa);
		itoa = NULL;
		free(temp);
		temp = NULL;
		free(path);
		path = NULL;
		i++;
	}
}

void	ft_make_player_r(t_all *all)
{
	int		i;
	char	*itoa;
	char	*temp;
	char	*path;

	i = 0;
	while (i <= 7)
	{
		itoa = ft_itoa(i);
		temp = ft_strjoin("./img/player/r/player_r_", itoa);
		path = ft_strjoin(temp, ".xpm");
		all->param->player_r_ptr[i] = mlx_xpm_file_to_image(all->param->mlx_ptr,
				path, &all->img->player_w, &all->img->player_h);
		free(itoa);
		itoa = NULL;
		free(temp);
		temp = NULL;
		free(path);
		path = NULL;
		i++;
	}
}

void	ft_make_player_l(t_all *all)
{
	int		i;
	char	*itoa;
	char	*temp;
	char	*path;

	i = 0;
	while (i <= 7)
	{
		itoa = ft_itoa(i);
		temp = ft_strjoin("./img/player/l/player_l_", itoa);
		path = ft_strjoin(temp, ".xpm");
		all->param->player_l_ptr[i] = mlx_xpm_file_to_image(all->param->mlx_ptr,
				path, &all->img->player_w, &all->img->player_h);
		free(itoa);
		itoa = NULL;
		free(temp);
		temp = NULL;
		free(path);
		path = NULL;
		i++;
	}
}
