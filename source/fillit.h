/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:04:16 by marvin            #+#    #+#             */
/*   Updated: 2019/01/28 20:32:35 by viwade           ###   ########.fr       */
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
char	*readfile(int fd);
size_t	root_int(int n);
t_tetra	*make_tetra(char *str);
int		validate_tetra(t_tetra *tetra);
int		tetra_fits(t_list *list, char **map, int n, int depth);

#endif
