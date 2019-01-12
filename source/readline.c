/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 11:13:27 by viwade            #+#    #+#             */
/*   Updated: 2019/01/12 11:16:14 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//#define DEBUG 0
/*
static void
	debug(char *message)
{
	if (!DEBUG)
		return ;
	if (!message)
		ft_putendl("Error in debug message.");
	ft_putstr("\033[32mDEBUG:\t\033[1m\033[36m");
	ft_putendl(message);
	ft_putstr("\033[0m");
}//*/

static int
	process(char **str, size_t fd, char **line)
{
	int		nb;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	nb = BUFF_SIZE;
	while (1)
	{
		if ((tmp = ft_strchr(*str, '\n')) || (nb != BUFF_SIZE))
		{
			fd = (tmp) ? (size_t)(tmp - *str) : 0;
			line[0] = (tmp) ? ft_strsub(*str, 0, fd) : ft_strdup(*str);
			*str = (tmp) ? ft_strdup(tmp + 1) : ft_strnew(0);
			free(tmp - fd);
			return (!!nb);
		}
		if ((nb = (int)read((int)fd, buf, BUFF_SIZE)) < 0)
			return (!!nb * -1);
		buf[nb] = 0;
		tmp = *str;
		*str = ft_strjoin(tmp, buf);
		free(tmp);
	}
}

int
	readline(const int fd, char **line)
{
	static char *file[FD_LIMIT];

	if (fd < 0 || fd > FD_LIMIT - 1 || !line || read(fd, 0, 0) == -1)
		return (-1);
	if (!file[fd])
		file[fd] = ft_strnew(0);
//	debug(ft_strjoin("file[fd]: ", file[fd]));
	return (process(&file[fd], (size_t)fd, line));
}
