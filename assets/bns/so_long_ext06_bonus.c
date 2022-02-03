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
