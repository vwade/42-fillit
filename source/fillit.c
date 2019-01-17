/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 04:01:54 by viwade            #+#    #+#             */
/*   Updated: 2019/01/16 22:44:08 by viwade           ###   ########.fr       */
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
	int j;

	tetra[0]->pos.y = tetra[0]->ndx[0].y;
	tetra[0]->pos.x = tetra[0]->ndx[0].x;
	i = 1;
	while (i < 4)
	{
		if (tetra[0]->ndx[i].x < tetra[0]->pos.x)
			tetra[0]->pos.x = tetra[0]->ndx[i].x;
		++i;
	}
	i = 0;
	while ((tetra[0]->pos.x > 0 || tetra[0]->pos.y > 0))
	{
		if (tetra[0]->pos.x > 0 && !(j = 0))
		{
			tetra[0]->pos.x -= 1;
			while (j < 4)
				tetra[0]->ndx[j--].x -= 1;
		}
		if (tetra[0]->pos.y > 0 && !(j = 0))
		{
			tetra[0]->pos.y -= 1;
			while (j < 4)
				tetra[0]->ndx[j--].y -= 1;
		}
	}
}

static tetra_t
	*tetramino(char *str)
{
	tetra_t	*tetra;
	int		i, j;

	if (!(tetra = (tetra_t *)malloc(sizeof(*tetra))))
		return (NULL);
	tetra = (tetra_t *)ft_memset(tetra, 0, sizeof(tetra));
	j = i = 0;
	while (str[i])
	{
		if (j >= 3)
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

static void
	append(char **line, char *content)
{
	;
}

static void
	solve(list_t *list)
{
	;
}

static int
	validate(tetra_t *tetra)
{
	int	i;
	int	count;

	i = 0;
	ft_putnbr(tetra->pos.x);
	ft_putnbr(tetra->pos.y); ft_putendl(0);
	while (i < 4)
	{
		ft_putnbr(tetra->ndx[i].x);
		ft_putnbr(tetra->ndx[i].y); ft_putendl(0);
		++i;
	}
	i = 0;
	count = 0;
	while (i < 3)
		if (count != 3)
			count += (tetra->ndx[i].x + 1 == tetra->ndx[i + 1].x)
				+ (tetra->ndx[i].y + 1 == tetra->ndx[i + 1].y);
	ft_putendl("VALIDATION COUNT:\t"); ft_putnbr(count); ft_putendl(0);
	return (count == 3);
}

static int
	isvalid(char *s)
{
	while(*s++)
		if (*(s - 1) != '.' && *(s - 1) != '#')
			return (0);
	return(1);
}


static void
	fillit(int fd, list_t *list, int *ret)
{
	char	*line;
	char	*str;
	char	*tmp;
	t_map	*map;

	int		count;

	map = map_new();
	str = ft_strnew(0);
	count = 0;
	while (readline(fd, &line) > 0)
	{
		tmp = str;
		if (count != 5)
			if ((ret[0] = (ft_strlen(line) != 4 && !isvalid(line))))
				return ft_error("error");
		str = ft_strjoin(str, line);
		free(tmp);
		count++;
		if (count == 5)
		{
			count = 0;
			ft_lstpush(&list, ft_lstnew(tetramino(str), ft_strlen(str)));
			if ((ret[0] = (!validate((tetra_t *)list->content))))
				return ft_error("error");
			ft_bzero(str, ft_strlen(str));
		}
	}
	if ((0)) solve(list);
}

int
	main(int n, char **v)
{
	int		fd;
	int		ret;
	list_t	*list;

	ret = 0;
	list = ft_lstnew(0, 0);
	fd = (open(v[1], O_RDONLY));
	if (n != 2)
	{
		ft_putendl("usage:\t""fillit tetrimino_file (1-26 pieces max)");
		return (1);
	}
	if (n == 2)
		if (fd > 0 && fd < FD_LIMIT && read(fd, 0, 0) != -1)
			fillit(fd, list, &ret);
	return (ret);
	return (ret);
}

/*
**	Footnotes
**
**	Will need.
**	Map variable
**	Choice of variable storage
**
**
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
**
**
**
**	Solve for coordinates. Where "n" is the size of grid.
**
**	CONVERSION: String Index => Coordinate
**	cd.x = i % n;
**	cd.y = i / n;
**
**	CONVERSION: Coordinate => String Index
**	i = (cd.y * n) + (cd.x);
**
**
**
**
**
**
**
**
**
**
**
*/
