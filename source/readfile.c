/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 20:04:53 by viwade            #+#    #+#             */
/*   Updated: 2019/01/20 20:13:05 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char
	*readfile(fd)
{
	char	*file;
	char	*line;
	char	*tmp;

	file = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = file;
		file = ft_strjoin(file, line);
		free(line);
		free(tmp);
	}
	return (file);
}