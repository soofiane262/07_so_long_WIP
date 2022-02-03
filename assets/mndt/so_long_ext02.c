/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:36:36 by sel-mars          #+#    #+#             */
/*   Updated: 2022/01/16 23:36:38 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit(0);
}

void	ft_init(t_all *all)
{
	all->map->moves = 0;
	all->map->lose = 0;
	if (all->map->map[all->map->pos[1]][all->map->pos[1]] != '1')
		all->param->player_d = 1;
	else
		all->param->player_d = -1;
}

char	**ft_alloc_to_map(char **map, int map_fd, int size)
{
	int		i;
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (size + 2));
	if (!ret)
		ft_map_error(&map, map_fd, "Allocation error for map", 1);
	i = 0;
	while (i < size)
	{
		ret[i] = ft_strdup(map[i]);
		if (!ret[i++])
			ft_map_error(&map, map_fd, "Allocation error for map", 1);
	}
	while (--i >= 0)
	{
		free(map[i]);
		map[i] = NULL;
	}
	free(map);
	map = NULL;
	return (ret);
}

void	ft_free_map(char **map)
{
	int	i;

	if (map)
	{
		i = 0;
		while (map[i])
		{
			free(map[i]);
			map[i++] = NULL;
		}
		free(map);
		map = NULL;
	}
}

void	ft_map_error(char ***map, int map_fd, char *error, int t)
{
	int	i;

	if (t)
	{
		i = 0;
		while ((*map)[i])
		{
			free((*map)[i]);
			(*map)[i++] = NULL;
		}
		free((*map));
		(*map) = NULL;
	}
	if (map_fd != -2)
		close(map_fd);
	ft_error(error);
}
