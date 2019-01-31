/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 20:04:53 by viwade            #+#    #+#             */
/*   Updated: 2019/01/30 18:10:15 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void
	join_line(char **v, char *new)
{
	char	*tmp;

	tmp = v[0];
	v[0] = ft_strjoin(v[0], new);
	free(tmp);
}

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

	i = 0;
	str = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 4)

		if (!verify(line, &i))
			return (NULL);
		join_line(&line, "\n");
		join_line(&str, line);
		free(line);
	}
	return (!str[0] ? NULL : str);
}
