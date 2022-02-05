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

void	ft_check_mlx_imgs(t_all *all)
{
	int	i;

	if (!all->param->ennemy_ptr || !all->param->collec_ptr
		|| !all->param->font_ptr)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("The mlx failed to make an image pointer", 2);
		ft_destroy_x(all);
	}
	i = -1;
	while (++i <= 7)
	{
		if (!all->param->player_ur_ptr[i] || !all->param->player_ul_ptr[i]
			|| !all->param->player_dr_ptr[i] || !all->param->player_dl_ptr[i]
			|| !all->param->player_r_ptr[i] || !all->param->player_l_ptr[i])
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("The mlx failed to make an image pointer", 2);
			ft_destroy_x(all);
		}
	}
	ft_check_mlx_imgs_ext(all);
}

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
