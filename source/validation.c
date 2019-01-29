/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:53:46 by viwade            #+#    #+#             */
/*   Updated: 2019/01/28 20:56:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

typedef struct s_tetra	t_tetra_t;
typedef struct s_list	t_list_t;
typedef struct s_coord	t_xy_t;

int
	str_verify(char *s)
{
	int		i;
	int		count;
	t_xy_t	x;

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

int
	str_isvalid(char *s)
{
	int	count;

	count = 0;
	while (*s++)
	{
		if (*(s - 1) != '.' && *(s - 1) != '#' && *(s - 1) != '\n')
			return (0);
		count += (*(s - 1) == '#');
	}
	return (count == 4);
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
