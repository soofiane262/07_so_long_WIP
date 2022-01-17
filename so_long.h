/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:33:03 by sel-mars          #+#    #+#             */
/*   Updated: 2022/01/16 23:33:04 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

void	ft_error(void);
void	ft_check_map(char *map_file);
char	**ft_make_map(char *map_file);
char	**ft_alloc_to_map(char **map, int size);
void	ft_map_error(char **map);
void	ft_init_integers(int *i, int *j, int *k, int *l);
#endif
