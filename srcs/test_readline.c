/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_readline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:54:50 by viwade            #+#    #+#             */
/*   Updated: 2019/01/18 07:44:02 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
static void
	openfile(char *file)
{
	int		ret;
//
	int     fd;
	char    *line;

	fd = open(file, O_RDONLY);
	while ((ret = readline(fd, &line)) > 0)
		ft_putendl(line);
	if (ret == -1)
		ft_error("An error reading the file was encountered.");
	if (ret == 0)
		ft_error("Finished reading file succesfully.");
	if (ret == 1)
		ft_error("Something odd has happened. File reading was not completed. Exiting anyway.");
}//*/

static void
	openfile(const char *file)
{
	char    *line;
	int     fd;

	fd = open(file, O_RDONLY);
	while (readline(fd, &line))
	{
		ft_putendl(line);
		free(line);
	}
}

static void
	open_gnl(const char *file)
{
	char    *line;
    int     fd;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		free(line);
	}
}

static void
	mulitiopen(const int n, const char **v)
{
	int		i, j;
	int		fd[FD_LIMIT];
	int		ret[FD_LIMIT];
	char	*line;
	
	i = 0;
	while (i < n){
		fd[i] = open(v[i], O_RDONLY);
		++i;
	}
	while (!(i = 0) && !(j = 0)){
		while (j < n){
			ret[j] = readline(fd[j], &line);
			if (ret[j] > 0){
				ft_putendl(line);
				free(line);
			}
			++j;
		}
		while (i < n){
			if (ret[i++])
				break ;
			return ;
		}
	}
}

int
	main(int n, const char **v)
{
	int	i;

	i = 0;
	if (n > 1){
		if ((0))
		while (++i < n){
			openfile(v[i]);
			if ((0))
				open_gnl(v[i]);
		}
		mulitiopen(n - 1, &v[1]);
	}
}
