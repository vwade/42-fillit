/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:32:23 by viwade            #+#    #+#             */
/*   Updated: 2018/11/10 14:22:04 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void
	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
		if ((*((unsigned char *)dst++) = *((unsigned char *)src++))\
				== (unsigned char)c)
			return (dst);
	return (NULL);
}
