/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:34:21 by viwade            #+#    #+#             */
/*   Updated: 2019/01/28 19:13:37 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void
	map_print(t_tetra *node, int order, char **map, size_t map_size)
{
	int		i;
	t_coord x;

	i = -1;
	x.x = node->pos.x;
	x.y = node->pos.y;
	while (++i < 4)
		map[0][((node->ndx[i].y + x.y) * map_size)
			+ (node->ndx[i].x + x.x)] = order + 'A';
}
