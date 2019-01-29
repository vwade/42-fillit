/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:31:53 by viwade            #+#    #+#             */
/*   Updated: 2019/01/28 21:59:34 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

typedef t_tetra	t_tetra_t;
typedef t_list	t_list_t;
typedef t_coord	t_xy_t;

char	g_c = '.';

static void
	normalize(t_tetra **tetra)
{
	int i;

	tetra[0]->pos.y = tetra[0]->ndx[0].y;
	tetra[0]->pos.x = tetra[0]->ndx[0].x;
	i = 0;
	while (++i < 4)
		if (tetra[0]->ndx[i].x < tetra[0]->pos.x)
			tetra[0]->pos.x = tetra[0]->ndx[i].x;
	while ((tetra[0]->pos.x > 0 || tetra[0]->pos.y > 0))
	{
		if (tetra[0]->pos.x > 0 && !(i = 0))
		{
			tetra[0]->pos.x -= 1;
			while (i < 4)
				tetra[0]->ndx[i++].x -= 1;
		}
		if (tetra[0]->pos.y > 0 && !(i = 0))
		{
			tetra[0]->pos.y -= 1;
			while (i < 4)
				tetra[0]->ndx[i++].y -= 1;
		}
	}
}

t_tetra_t
	*make_tetra(char *str)
{
	t_tetra	*tetra;
	int		i;
	int		j;

	if (!(tetra = (t_tetra *)malloc(sizeof(*tetra))))
		return (NULL);
	tetra = (t_tetra *)ft_memset(tetra, 0, sizeof(*tetra));
	j = 0;
	i = 0;
	while (str[i])
	{
		if (j > 3)
			break ;
		if (str[i] == '#')
		{
			tetra->ndx[j].x = i % 4;
			tetra->ndx[j].y = i / 4;
			j++;
		}
		++i;
	}
	normalize(&tetra);
	return (tetra);
}

static t_xy_t
	set_dimensions(t_tetra_t t, t_xy_t dim)
{
	int		i;

	i = -1;
	while (++i < 4)
		dim = (t_xy_t){dim.x < t.ndx[i].x + 1 ? t.ndx[i].x + 1 : dim.x,
			dim.y < t.ndx[i].y + 1 ? t.ndx[i].y + 1 : dim.y};
	return (dim);
}

static int
	write_tetra(char **map, t_tetra_t t, int n, char c)
{
	if (c)
	{
		map[0][n * (t.pos.y + t.ndx[0].y) + t.pos.x + t.ndx[0].x] = c;
		map[0][n * (t.pos.y + t.ndx[1].y) + t.pos.x + t.ndx[1].x] = c;
		map[0][n * (t.pos.y + t.ndx[2].y) + t.pos.x + t.ndx[2].x] = c;
		map[0][n * (t.pos.y + t.ndx[3].y) + t.pos.x + t.ndx[3].x] = c;
		return (0);
	}
	return (
		map[0][n * (t.pos.y + t.ndx[0].y) + t.pos.x + t.ndx[0].x] == g_c &&
		map[0][n * (t.pos.y + t.ndx[1].y) + t.pos.x + t.ndx[1].x] == g_c &&
		map[0][n * (t.pos.y + t.ndx[2].y) + t.pos.x + t.ndx[2].x] == g_c &&
		map[0][n * (t.pos.y + t.ndx[3].y) + t.pos.x + t.ndx[3].x] == g_c);
}

int
	tetra_fits(t_list_t *list, char **map, int n, int depth)
{
	int			*i;
	t_tetra_t	t;
	t_xy_t		dim;

	i = (int[5]){0, 0, 0, 0, -1};
	t = ((t_tetra_t *)list->content)[0];
	dim = set_dimensions(t, (t_xy_t){1, 1});
	if (dim.x > n || dim.y > n)
		return (0);
	while (i[1] < n * n - (dim.y - 1) * n)
	{
		t.pos = (t_xy_t){i[1] % n, i[1] / n};
		if (write_tetra(map, t, n, 0))
		{
			write_tetra(map, t, n, 'A' + depth % 26 + (depth > 25) * 32);
			if ((list->next && tetra_fits(list->next, map, n, depth + 1))
					|| (!list->next))
				return (1);
			write_tetra(map, t, n, g_c);
		}
		i[1] += !(i[3] = 0) && (n - t.pos.x == dim.x) ? n - t.pos.x : 1;
	}
	return (0);
}
