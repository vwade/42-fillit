/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:31:53 by viwade            #+#    #+#             */
/*   Updated: 2019/01/28 20:31:50 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

typedef t_tetra	t_tetra_t;
typedef t_list	t_list_t;
typedef t_coord	t_xy_t;

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

int
	validate_tetra(t_tetra_t *tetra)
{
	int	i;
	int	count;

	i = 0;
	while (i < 4)
	{
		++i;
	}
	i = -1;
	count = 0;
	while (i++ < 3)
		if (count != 3)
			count += (tetra->ndx[i].x + 1 == tetra->ndx[i + 1].x)
				+ (tetra->ndx[i].y + 1 == tetra->ndx[i + 1].y);
	return (count == 3);
}

int
	tetra_fits(t_list_t *list, char **map, int n, int depth)
{
	int			*i;
	t_tetra_t	t;
	t_xy_t		dim;
	t_xy_t		x;

	i = (int[5]){0, 0, 0, 0, -1};
	x = (t_xy_t){0, 0};
	dim = (t_xy_t){1, 1};
	t = ((t_tetra_t *)list->content)[0];
	while (++i[4] < 4)
		dim = (t_xy_t){dim.x < t.ndx[i[4]].x + 1 ? t.ndx[i[4]].x + 1 : dim.x,
			dim.y < t.ndx[i[4]].y + 1 ? t.ndx[i[4]].y + 1 : dim.y};
	if (dim.x > n || dim.y > n)
		return (0);
	while (i[1] < n * n - (dim.y - 1) * n && (i[0] = -1))
	{
		x = (t_xy_t){i[1] % n, i[1] / n};
		t.pos = x;
		while (++i[0] < 4)
			i[3] += (map[0][n * (t.pos.y + t.ndx[i[0]].y)
				+ t.pos.x + t.ndx[i[0]].x] == '.');
		if (i[3] == 4 && (i[0] = -1))
		{
			while (++i[0] < 4)
				map[0][n * (t.pos.y + t.ndx[i[0]].y)
					+ t.pos.x + t.ndx[i[0]].x] = 'A' + depth % 26
					+ (depth > 25 ? 32 : 0);
			if ((i[0] = -1) && list->next)
				if (tetra_fits(list->next, map, n, depth + 1))
					return (1);
			if (!list->next)
				return (1);
			while (++i[0] < 4)
				map[0][n * (t.pos.y + t.ndx[i[0]].y)
					+ t.pos.x + t.ndx[i[0]].x] = '.';
		}
		i[1] += !(i[3] = 0) && (n - x.x == dim.x) ? n - x.x : 1;
	}
	return (0);
}
