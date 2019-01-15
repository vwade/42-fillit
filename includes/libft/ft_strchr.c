/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 03:44:09 by viwade            #+#    #+#             */
/*   Updated: 2018/12/06 00:50:54 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	if (!s)
		ft_error("");
	while (s[i])
	{
		p = &((unsigned char *)s)[i];
		if ((unsigned char)c == p[0])
			return ((char *)p);
		i++;
	}
	p = &((unsigned char *)s)[i];
	return ((*p == (unsigned char)c) ? (char *)p : NULL);
}
