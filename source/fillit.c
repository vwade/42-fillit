/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 04:01:54 by viwade            #+#    #+#             */
/*   Updated: 2019/02/06 07:19:36 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

typedef struct s_tetra	t_tetra_t;
typedef struct s_list	t_list_t;
typedef struct s_coord	t_xy_t;

static char
	*process_chunk(char *s)
{
	int		i;
	char	*fill;
	char	*tmp;
	char	**list;

	if (!str_isvalid(s))
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
	return (str_verify(fill) ? fill : NULL);
}

static size_t
	get_max_dim(t_list_t *list)
{
	size_t		i;
	size_t		len;
	size_t		max;
	t_xy_t		dim;
	t_tetra_t	t;

	len = ft_lstlen(list);
	dim = (t_xy_t){1, 1};
	while (list && (i = -1))
	{
		t = ((t_tetra_t *)list->content)[0];
		while (++i < 4)
			dim = (t_xy_t){dim.x < t.ndx[i].x + 1 ? t.ndx[i].x + 1 : dim.x,
				dim.y < t.ndx[i].y + 1 ? t.ndx[i].y + 1 : dim.y};
		list = list->next;
	}
	max = dim.x > dim.y ? dim.x : dim.y;
	return (2 * root_int(len) - (max % 2));
}

static void
	solve(t_list_t *list)
{
	char	*map;
	size_t	map_size;

	if (ft_lstlen(list) > 52)
		return (ft_error("error"));
	map_size = get_max_dim(list);
	while ((1))
	{
		map = ft_strnew(map_size * map_size);
		map = ft_memset(map, '.', map_size * map_size);
		if (tetra_fits(list, &map, map_size, 0))
			break ;
		else
			map_size++;
		free(map);
	}
	print_map(map, map_size);
	free(map);
	ft_lstdel(&list, ft_del);
}

static void
	error_check(char *file, t_list_t *list, int *ret)
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
		ft_lstpush(&list, ft_lstnew(make_tetra(str), sizeof(t_tetra_t)));
		free(str);
		i += 20 + (file[i + 20] == '\n');
		if (!file[i])
			break ;
		if ((ret[0] = 2 * (!validate_tetra((t_tetra_t *)list->content)
				|| (&file[i] > &file[len]))))
			return ;
	}
	if ((ret[0] = 3 * (!list)))
		return ;
	return (solve(list));
}

int
	main(int n, char **v)
{
	int			fd;
	int			ret;
	char		*input;
	t_list_t	*list;

	ret = 0;
	list = NULL;
	if (n != 2)
	{
		ft_putendl("usage: fillit source_file\n"
			"       file must have between 1 and 26 tetriminos");
		return (-1);
	}
	fd = (open(v[1], O_RDONLY));
	if (!(input = readfile(fd)))
	{
		ft_error("error");
		return (1);
	}
	error_check(input, list, &ret);
	close(fd);
	if (ret > 0)
		ft_error("error");
	return (ret);
}
