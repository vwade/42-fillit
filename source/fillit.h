/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:04:16 by marvin            #+#    #+#             */
/*   Updated: 2019/01/28 19:45:33 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../includes/libft/libft.h"
# include "../includes/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>

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

void	print_map(char *map, int size);
t_tetra	make_tetramino(char *str);
size_t	tetra_len(t_tetra **list);

int		readline(const int fd, char **line);
char	*readfile(int fd);
char	*map_size(size_t size);

#endif
