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

void	ft_check_map(t_params *param, char *map_file)
{
	int		len[2];

	param->map = ft_make_map(map_file);
	len[0] = (int)ft_strlen(param->map[0]);
	len[1] = 0;
	ft_check_walls(param->map, len);
	ft_check_chars(param->map, len);
	while (param->map[len[1]])
		len[1]++;
	param->map_width = len[0];
	param->map_height = len[1];
}

void	ft_check_chars(char **map, int *len)
{
	int		i;
	int		j;
	int		p;
	char	*ref;
	char	*trimmed;

	ref = "01CEP";
	i = 1;
	p = 0;
	while (i < len[1] - 1)
	{
		j = 0;
		while (++j < len[0] - 1)
			if (map[i][j] == 'P')
				p++;
		trimmed = ft_strtrim(map[i], ref);
		if (trimmed[0])
		{
			free(trimmed);
			ft_map_error(map, 0);
		}
		free(trimmed);
		i++;
	}
	if (p != 1)
		ft_map_error(map, 0);
}

void	ft_check_walls(char **map, int *len)
{
	int	i;

	while (map[++len[1]])
		if (ft_strlen(map[len[1]]) != ft_strlen(map[len[1] - 1]))
			ft_map_error(map, 0);
	i = -1;
	while (++i < len[0])
		if (map[0][i] != '1')
			ft_map_error(map, 0);
	i = -1;
	while (++i < len[0])
		if (map[len[1] - 1][i] != '1')
			ft_map_error(map, 0);
	i = -1;
	while (++i < len[1])
		if (map[i][0] != '1')
			ft_map_error(map, 0);
	i = -1;
	while (++i < len[1])
		if (map[i][len[0] - 1] != '1')
			ft_map_error(map, 0);
}

char	**ft_make_map(char *map_file)
{
	int		i;
	int		map_fd;
	char	*temp;
	char	**map;

	map_fd = open(map_file, O_RDONLY);
	temp = get_next_line(map_fd);
	if (!temp)
		ft_map_error(NULL, map_fd);
	i = 0;
	while (temp)
	{
		if (i == 0)
			map = (char **)malloc(sizeof(char *) * 2);
		else
			map = ft_alloc_to_map(map, i);
		if (!map)
			ft_map_error(map, map_fd);
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

void	ft_map_error(char **map, int map_fd)
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
	if (map_fd)
		close(map_fd);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Your map is invalid\nPlease refer to the map configuration and try again :)", 2);
	exit(0);
}
