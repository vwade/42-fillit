/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 21:04:41 by viwade            #+#    #+#             */
/*   Updated: 2019/01/28 19:15:22 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FD_LIMIT 8192
# define BUFF_SIZE 21

# include "libft/libft.h"
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>

struct	s_file
{
	size_t	ndx;
	size_t	len;
	char	*str;
};
typedef struct s_file	t_file;

int		get_next_line(const int fd, char **line);

#endif
