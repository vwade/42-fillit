/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:34:21 by viwade            #+#    #+#             */
/*   Updated: 2019/01/28 19:52:06 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void
	print_map(char *map, int size)
{
	int i;

	i = 0;
	while (&map[i] < &map[size * size])
	{
		write(1, &map[i], size);
		write(1, "\n", 1);
		i += size;
	}
}

size_t
	root_int(int n)
{
	size_t	i;

	i = 0;
	while (i * i < (size_t)n)
		++i;
	return (i);
}
