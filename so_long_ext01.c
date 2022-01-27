/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:36:36 by sel-mars          #+#    #+#             */
/*   Updated: 2022/01/16 23:36:38 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(t_map *map, char *map_file)
{
	int	i[2];
	int	len[2];

	map->map = ft_make_map(map_file);
	len[0] = (int)ft_strlen(map->map[0]);
	len[1] = 0;
	ft_check_walls(map->map, len);
	ft_check_chars(map->map, len);
	while (map->map[len[1]])
		len[1]++;
	map->width = len[0] * 75;
	map->height = len[1] * 75;
	i[1] = 0;
	while (++i[1] < len[1] - 1)
	{
		i[0] = 0;
		while (++i[0] < len[0] - 1)
		{
			if (map->map[i[1]][i[0]] == 'P')
			{
				map->pos[0] = i[0];
				map->pos[1] = i[1];
			}
		}
	}
}

void	ft_check_chars(char **map, int *len)
{
	int		i;
	int		j;
	int		p;
	char	*ref;
	char	*trimmed;

	ref = "01EPNC";
	i = 0;
	p = 0;
	while (++i < len[1] - 1)
	{
		j = 0;
		while (++j < len[0] - 1)
			if (map[i][j] == 'P')
				p++;
		trimmed = ft_strtrim(map[i], ref);
		if (trimmed[0])
		{
			free(trimmed);
			ft_map_error(map, -2, "Invalid character detected in map");
		}
		free(trimmed);
	}
	if (p != 1)
		ft_map_error(map, -2, "Map contains more than one starting position");
}

void	ft_check_walls(char **map, int *len)
{
	int	i;

	while (map[++len[1]])
		if (ft_strlen(map[len[1]]) != ft_strlen(map[len[1] - 1]))
			ft_map_error(map, -2, "Map isn't rectangular");
	i = -1;
	while (++i < len[0])
		if (map[0][i] != '1')
			ft_map_error(map, -2, "Map isn't surrounded by walls");
	i = -1;
	while (++i < len[0])
		if (map[len[1] - 1][i] != '1')
			ft_map_error(map, -2, "Map isn't surrounded by walls");
	i = -1;
	while (++i < len[1])
		if (map[i][0] != '1')
			ft_map_error(map, -2, "Map isn't surrounded by walls");
	i = -1;
	while (++i < len[1])
		if (map[i][len[0] - 1] != '1')
			ft_map_error(map, -2, "Map isn't surrounded by walls");
}

char	**ft_make_map(char *map_file)
{
	int		i;
	int		map_fd;
	char	*temp;
	char	**map;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd < 0)
		ft_map_error(NULL, map_fd, "Couldn't open map file");
	temp = get_next_line(map_fd);
	i = 0;
	while (temp)
	{
		if (i == 0)
			map = (char **)malloc(sizeof(char *) * 2);
		else
			map = ft_alloc_to_map(map, map_fd, i);
		if (!map)
			ft_map_error(map, map_fd, "Allocation error for map");
		map[i++] = ft_map_line_dup(temp);
		map[i] = NULL;
		free(temp);
		temp = get_next_line(map_fd);
	}
	close(map_fd);
	return (map);
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
