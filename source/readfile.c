/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 20:04:53 by viwade            #+#    #+#             */
/*   Updated: 2019/01/30 20:43:49 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int
	verify(char *s, int *nonce)
{
	nonce[0] += 1;
	if (nonce[0] == 5)
	{
		if (*s)
			return (0);
		nonce[0] = 0;
	}
	else
	{
		if (ft_strlen(s) != 4)
			return (0);
		while (*s++)
			if (*(s - 1) != '.' && *(s - 1) != '#')
				return (0);
	}
	return (1);
}

char
	*readfile(int fd)
{
	int		i;
	char	*line;
	char	*str;
	char	*tmp;

	i = 0;
	str = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		if (!verify(line, &i))
			return (NULL);
		tmp = line;
		line = ft_strjoin(line, "\n");
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, line);
		free(line);
		free(tmp);
	}
	return (!str[0] || !i ? NULL : str);
}
