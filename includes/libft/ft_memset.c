/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:13:30 by viwade            #+#    #+#             */
/*   Updated: 2018/11/09 20:20:01 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*dup;

	i = 0;
	while (len--)
	{
		dup = &b[i];
		dup[0] = (unsigned char)c;
		i++;
	}
	return (b);
}
