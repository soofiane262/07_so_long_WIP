/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext06_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:57:51 by sel-mars          #+#    #+#             */
/*   Updated: 2022/02/03 18:57:58 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_mlx_imgs_ext(t_all *all)
{
	int	i;

	i = -1;
	while (++i <= 20)
	{
		if (!all->param->walls_ptr[i])
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("The mlx failed to make an image pointer", 2);
			ft_destroy_x(all);
		}
	}
	i = -1;
	while (++i <= 49)
	{
		if (!all->param->exit_ptr[i])
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("The mlx failed to make an image pointer", 2);
			ft_destroy_x(all);
		}
	}
}

void	ft_make_player_ur(t_all *all)
{
	int		i;
	char	*itoa;
	char	*temp;
	char	*path;

	i = 0;
	while (i <= 7)
	{
		itoa = ft_itoa(i);
		temp = ft_strjoin("./img/player/ur/player_ur_", itoa);
		path = ft_strjoin(temp, ".xpm");
		all->param->player_ur_ptr[i] = mlx_xpm_file_to_image(
				all->param->mlx_ptr, path, &all->img->player_w,
				&all->img->player_h);
		free(itoa);
		itoa = NULL;
		free(temp);
		temp = NULL;
		free(path);
		path = NULL;
		i++;
	}
}

void	ft_make_player_ul(t_all *all)
{
	int		i;
	char	*itoa;
	char	*temp;
	char	*path;

	i = 0;
	while (i <= 7)
	{
		itoa = ft_itoa(i);
		temp = ft_strjoin("./img/player/ul/player_ul_", itoa);
		path = ft_strjoin(temp, ".xpm");
		all->param->player_ul_ptr[i] = mlx_xpm_file_to_image(
				all->param->mlx_ptr, path, &all->img->player_w,
				&all->img->player_h);
		free(itoa);
		itoa = NULL;
		free(temp);
		temp = NULL;
		free(path);
		path = NULL;
		i++;
	}
}

void	ft_make_player_dr(t_all *all)
{
	int		i;
	char	*itoa;
	char	*temp;
	char	*path;

	i = 0;
	while (i <= 7)
	{
		itoa = ft_itoa(7 - i);
		temp = ft_strjoin("./img/player/ur/player_ur_", itoa);
		path = ft_strjoin(temp, ".xpm");
		all->param->player_dr_ptr[i] = mlx_xpm_file_to_image(
				all->param->mlx_ptr, path, &all->img->player_w,
				&all->img->player_h);
		free(itoa);
		itoa = NULL;
		free(temp);
		temp = NULL;
		free(path);
		path = NULL;
		i++;
	}
}

void	ft_make_player_dl(t_all *all)
{
	int		i;
	char	*itoa;
	char	*temp;
	char	*path;

	i = 0;
	while (i <= 7)
	{
		itoa = ft_itoa(7 - i);
		temp = ft_strjoin("./img/player/ul/player_ul_", itoa);
		path = ft_strjoin(temp, ".xpm");
		all->param->player_dl_ptr[i] = mlx_xpm_file_to_image(
				all->param->mlx_ptr, path, &all->img->player_w,
				&all->img->player_h);
		free(itoa);
		itoa = NULL;
		free(temp);
		temp = NULL;
		free(path);
		path = NULL;
		i++;
	}
}
