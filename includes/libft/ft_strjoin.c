/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:02:07 by viwade            #+#    #+#             */
/*   Updated: 2019/01/28 19:50:26 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((new = (char *)malloc(sizeof(*new) * len + 1)))
		if ((new = ft_strncpy(new, s1, len)))
			if ((new = ft_strncat(new, s2, len)))
				new[len] = 0;
	return (new);
}

/*
**  command to compile
**  compile source/fillit.c \
**  includes/libft/ft_bzero.c \
**  includes/libft/added_functions/ft_error.c \
**  includes/libft/ft_lstnew.c \
**  includes/libft/added_functions/ft_lstpush.c \
**  includes/libft/ft_memset.c \
**  includes/libft/ft_putendl.c \
**  includes/libft/ft_putnbr.c \
**  includes/libft/ft_strjoin.c \
**  includes/libft/ft_strlen.c \
**  includes/libft/ft_strnew.c \
**  source/readline.c \
**  includes/libft/ft_memalloc.c \
**  includes/libft/ft_memcpy.c \
**  includes/libft/ft_putstr.c \
**  includes/libft/ft_strdup.c \
**  includes/libft/ft_strncat.c \
**  includes/libft/ft_strncpy.c \
**  includes/libft/ft_strsub.c \
**  includes/libft/ft_strcpy.c \
**  includes/libft/ft_strchr.c \
**  includes/get_next_line.c
*/
