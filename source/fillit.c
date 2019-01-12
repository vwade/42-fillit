/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 04:01:54 by viwade            #+#    #+#             */
/*   Updated: 2019/01/12 15:16:29 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fillit.h"

static void
	tetra(char *t)
{
	;
}

static void
	append(char **line, char *content)
{
	;
}

static void
	solve()
{
	;
}

static int
	validate(char *s)
{
	;
}


static void
	fillit(int fd, char **line)
{
	char	*str;
	t_map	*map;

	map = map_new();
	readline(fd, line);
}

int
	main(int n, char **v)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 0;
	fd = (open(v[1], O_RDONLY));
	if (n == 2)
		if (fd > 0 && fd < FD_LIMIT && read(fd, 0, 0) != -1)
			fillit(fd, &line);
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
**	
**	
**	
**	
**	
**	
*/
