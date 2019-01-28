/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 04:01:54 by viwade            #+#    #+#             */
/*   Updated: 2019/01/27 17:12:54 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

typedef t_tetra	tetra_t;
typedef t_list	list_t;
typedef t_coord	coord_t;

static void
	normalize(tetra_t **tetra)
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

static tetra_t
	*tetramino(char *str)
{
	tetra_t	*tetra;
	int		i;
	int		j;

	if (!(tetra = (tetra_t *)malloc(sizeof(*tetra))))
		return (NULL);
	tetra = (tetra_t *)ft_memset(tetra, 0, sizeof(*tetra));
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

static int
	validate(tetra_t *tetra)
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
	ft_putstr("TETRA VALIDATION: "); ft_putnbr(count); ft_putendl(0);
	return (count == 3);
}

static int
	str_validate(char *s)
{
	int		i;
	int		count;
	coord_t	x;

	i = 0;
	count = 0;
	if (ft_strlen(s) != 16)
		return (0);
	while (s[i])
	{
		x.x = i % 4;
		x.y = i / 4;
		if (s[i] == '#')
			count += ((x.x + 1 < 4) ? s[i + 1] == '#' : 0)
				+ ((x.y + 1 < 4) ? s[i + 4] == '#' : 0);
		if (count == 3)
			return (1);
		++i;
	}
	return (count == 3);
}

static int
	isvalid(char *s)
{
	int	count;

	count = 0;
	while (*s++)
	{
		if (*(s - 1) != '.' && *(s - 1) != '#' && *(s - 1) != '\n')
			return (0);
		count += (*s == '#');
	}
	return (count == 4);
}

static char
	*process_chunk(char *s)
{
	int		i;
	char	*fill;
	char	*tmp;
	char	**list;

	if (!isvalid(s))
		return (NULL);
	i = 0;
	fill = ft_strnew(0);
	list = ft_strsplit(s, '\n');
	while (list[i])
	{
		if (ft_strlen(list[i]) != 4)
			return (NULL);
		tmp = fill;
		fill = (fill) ? ft_strjoin(fill, list[i]) : ft_strdup(list[i]);
		free(list[i]);
		free(tmp);
		++i;
	}
	free(s);
	free(list);
	return (str_validate(fill) ? fill : NULL);
}

static int
	tetra_fits(list_t *list, char **map, int n, int depth)
{
	int		*i;
	tetra_t	t;
	coord_t	dim;
	coord_t	x;

	i = (int[5]){0, 0, 0, 0, -1};
	x = (coord_t){0, 0};
	dim = (coord_t){1, 1};
	t = ((tetra_t *)list->content)[0];
	while (++i[4] < 4)
		dim = (coord_t){dim.x < t.ndx[i[4]].x + 1 ? t.ndx[i[4]].x + 1 : dim.x,
			dim.y < t.ndx[i[4]].y + 1 ? t.ndx[i[4]].y + 1 : dim.y};
	if (dim.x > n || dim.y > n)
		return (0);
	while (i[1] < n * n - (dim.y - 1) * n && (i[0] = -1))
	{
		x = (coord_t){i[1] % n, i[1] / n};
		t.pos = x;
		while (++i[0] < 4)
			i[3] += (map[0][n * (t.pos.y + t.ndx[i[0]].y)
				+ t.pos.x + t.ndx[i[0]].x] == ' ');
		if (i[3] == 4 && (i[0] = -1))
		{
			while (++i[0] < 4)
				map[0][n * (t.pos.y + t.ndx[i[0]].y)
					+ t.pos.x + t.ndx[i[0]].x] = 'A' + depth;
			if ((i[0] = -1) &&
					list->next && tetra_fits(list->next, map, n, depth + 1))
				return (1);
			while (++i[0] < 4)
				map[0][n * (t.pos.y + t.ndx[i[0]].y)
					+ t.pos.x + t.ndx[i[0]].x] = ' ';
		}
		i[1] += !(i[3] = 0) && (n - x.x == dim.x) ? n - x.x : 1;
	}
	return (0);
}

static void
	solve(list_t *list)
{
	char	*map;
	int		map_size;

	map_size = 2;
	while ((1))
	{
		map = ft_strnew(map_size * map_size);
		map = ft_memset(map, ' ', map_size * map_size);
		if (tetra_fits(list, &map, map_size, 0))
			break ;
		else
			map_size++;
		free(map);
	}
	ft_putendl(map);
}

static void
	error_check(char *file, list_t *list, int *ret)
{
	int		i;
	int		len;
	char	*str;

	str = ft_strnew(0);
	i = 0;
	len = ft_strlen(file);
	while (&file[i] < &file[len])
	{
		str = process_chunk(ft_strsub(&file[i], 0, 20));
		if ((ret[0] = 2 * (!str ||
				(file[i + 20] != '\n' && file[i + 20] != '\0'))))
			return ;
		ft_lstpush(&list, ft_lstnew(tetramino(str), sizeof(tetra_t)));
		free(str);
		i += 20 + (file[i + 20] == '\n');
		if (!file[i])
			break ;
		if ((ret[0] = 2 * (!validate((tetra_t *)list->content)
				|| (&file[i] > &file[len]))))
			return ;
	}
	if ((ret[0] = 3 * (!list->content)))
		return ;
	return solve(list);
}

/*
**	Return Values:
**	0	//	Normal program termination
**	1	//	Problem with reading file
**	2	//	Invalid tetramino piece
**	3	//	Undefined behavior leading into program termination
*/

static int
	ret_function(int ret)
{
	if (ret == -1)
		ft_putendl("usage:\t""fillit tetrimino_file (1-26 pieces max)");
	if (ret == 1)
		ft_error("error: Problem reading file. Possible invalid file format.");
	if (ret == 2)
		ft_error("error: Invalid tetrimino format.");
	if (ret == 3)
		ft_error("error: Function quit unexpectedly.");
	if ((0))
		solve(0);
	return (ret);
}

int
	main(int n, char **v)
{
	int		fd;
	int		ret;
	char	*input;
	list_t	*list;

	ret = 0;
	list = NULL;
	if (n != 2)
		return (ret_function(-1));
	fd = (open(v[1], O_RDONLY));
	if (!(input = readfile(fd)))
		return (ret_function(1));
	ft_putstr("INPUT >>\n"); ft_putendl(input);
	error_check(input, list, &ret);
	close(fd);
	return (ret_function(ret));
}

/*
**	FOOTNOTES
**
**	Will need.
**	Map variable
**	Choice of variable storage
**
**	Read input.
**	4 lines at a time
**
**	Validate.
**	Each line is length of 4
**	Only '.' or '#' characters allowed
**	Total characters counted == 16.
**
**	Partition.
**
**	Solve for coordinates. Where "n" is the size of grid.
**
**	CONVERSION: String Index => Coordinate
**	cd.x = i % n;
**	cd.y = i / n;
**
**	CONVERSION: Coordinate => String Index
**	i = (cd.y * n) + (cd.x);
*/
