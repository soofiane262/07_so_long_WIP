/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:36:36 by sel-mars          #+#    #+#             */
/*   Updated: 2022/01/16 23:36:38 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

void	ft_init_integers(int *i, int *j, int *k, int *l)
{
	*i = 0;
	*j = 0;
	*k = 0;
	*l = 0;
}

void	ft_check_map(char *map_file);
{
	int		i[4];
	int		l[2];
	char	**map;

	map = ft_make_map(map_file);
	
	l[0] = 0;
	l[1] = 0;
	while (map[0][l[0]])
		l[0]++;
	while (map[l[1]])
		l[1]++;
	ft_init_integers(&i[0], &i[1], &i[2], &i[3]);
	while (map[0][i[0]] && map[0][i[0]] == '1')
		i[0]++;
	while (map[i[1]] && map[i[1]][0] == '1')
		i[1]++;
	while (map[l[0]][i[2]])
	if (map[0][i[0]] || map[i[1]])
		ft_map_error(map);
}

char	**ft_make_map(char *map_file)
{
	int		i;
	int		map_fd;
	char	*temp;
	char	**map;

	map_fd = open(map_file, O_RDONLY);
	temp = get_next_line(map_fd);
	i = 0;
	while (temp)
	{
		map = ft_alloc_to_map(map, i);
		if (!map)
			ft_free_map(map);
		map[i++] = ft_strdup(temp);
		map[i] = NULL;
		free(temp);
		temp = get_next_line(map_fd);
	}
	return (map);
}

char	**ft_alloc_to_map(char **map, int size)
{
	int		i;
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (size + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = ft_strdup(map[i]);
		if (!ret[i++])
			return (NULL);
	}
	while (i >= 0)
	{
		free(map[i]);
		map[i--] = NULL;
	}
	if (map)
	{
		free(map);
		map = NULL;
	}
	return (ret);
}

void	ft_map_error(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i++] = NULL;
	}
	free(map);
	map = NULL;
	ft_error();
}
