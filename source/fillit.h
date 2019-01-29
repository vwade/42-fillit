/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:04:16 by marvin            #+#    #+#             */
/*   Updated: 2019/01/28 18:33:06 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../includes/libft/libft.h"
# include "../includes/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>

struct	s_map
{
	size_t	size;
	char	*str;
};
typedef struct s_map	t_map;

struct	s_coord
{
	int	x;
	int	y;
};
typedef struct s_coord	t_coord;
struct	s_tetra
{
	t_coord	pos;
	t_coord ndx[4];
};
typedef struct s_tetra	t_tetra;

size_t	tetra_len(t_tetra **list);
t_tetra	**tetra_new(size_t size);
t_tetra	**tetra_add(t_tetra **list, t_tetra *piece);
void	tetra_del(t_tetra *node);
t_coord	newcoord(void);

int		readline(const int fd, char **line);
char	*readfile(int fd);
char	*map_size(size_t size);
t_map	*map_new(void);

#endif
